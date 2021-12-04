/* Bank Database
 * Tanner Babcock
 * tababcock@dmacc.edu
 * December 3, 2021 */
/* In this file I added some error-checking, so I could
 * more easily figure out my problem */
#include <memory>
#include <cstdlib>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include "database.h"
#include "bank.h"
#include "counterparty.h"

Database::Database(void) {
    const QString DRIVER("QSQLITE");
    if (!QSqlDatabase::isDriverAvailable(DRIVER)) {
        qWarning() << "ERROR: driver not available";
    }
    QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);
    db.setDatabaseName(":memory:");
    if (!db.open()) {
        qWarning() << "ERROR: " << db.lastError();
    }
    rebuildTestDatabase();
}

unique_ptr<Transaction> Database::getTransaction(long long transactionId) {
    auto query = make_unique<QSqlQuery>();
    query->prepare("SELECT AccountId, counterpartyId, Amount, Timestamp FROM AccountTransaction WHERE TransactionId = :id");
    query->bindValue(":id", transactionId);
    query->exec();
    query->next();

    long long account = query->value(0).toLongLong();
    Counterparty cp(query->value(1).toLongLong(), 0, "", "", "");
    double amount = query->value(2).toDouble();
    time_t ts = query->value(3).toLongLong();

    /* TODO: Complete the following query so that the transaction for the
     * transactionId is loaded from the database and stored into a
     * Transaction object which returned by unique_ptr.
     *
     * When it is working the CLI Menu should do the following:
     * Account 1. Make a selection.
     * 1. Display balance.
     * 2. List all transactions.
     * 3. View transaction.
     * 4. Exit.
     * 3
     * Select transaction by id:
     * 2
     * Transaction 2 $-2122
     *
     *
     * Here is the query string to use:
     * "SELECT AccountId, counterpartyId, Amount, Timestamp " \
     * "FROM AccountTransaction WHERE TransactionId = :id");
     *
     * You can create a default Counterparty object.
     * Counterparty counterparty(counterpartyId, 0, "", "", "");
     */
    unique_ptr<Transaction> ta = make_unique<Transaction>(transactionId, account, cp, amount, ts);
    return ta;
}

unique_ptr<Account> Database::getAccount(long long accountId) {
    auto query = make_unique<QSqlQuery>();
    query->prepare("SELECT Balance FROM Account WHERE AccountId = :accountId");
    query->bindValue(":accountId", accountId);
    if (!query->exec()) {
        qWarning() << "Could not execute getAccount() SELECT" << endl;
        abort();
    }
    query->next();
    double balance = query->value(0).toDouble();

    unique_ptr<Account> account = make_unique<Account>(accountId);
    account->deposit(balance);
    return account;
}

void Database::createAccount(long long accountId) {
    auto insert = make_unique<QSqlQuery>();
    insert->prepare("INSERT INTO Account (AccountId, Balance) VALUES (:accountId, :balance)");
    insert->bindValue(":accountId", accountId);
    insert->bindValue(":balance", 0);
    if (!insert->exec()) {
        qWarning() << "Could not execute createAccount() with " << accountId << endl;
        abort();
    }
}

bool Database::accountExists(long long accountId) {
    auto query = make_unique<QSqlQuery>();
    query->prepare("SELECT Balance FROM Account WHERE AccountId = :accountId");
    query->bindValue(":accountId", accountId);
    if (!query->exec()) {
        qWarning() << "Could not execute accountExists() with ID " << accountId << endl;
        abort();
    }
    return query->next();
}

double Database::getBalance(long long accountId) {
    auto query = make_unique<QSqlQuery>();
    query->prepare("SELECT Balance FROM Account WHERE AccountId = :accountId");
    query->bindValue(":accountId", accountId);
    if (!query->exec()) {
        qWarning() << "Could not execute getBalance() with ID " << accountId << endl;
        abort();
    }
    query->next();
    return query->value(0).toDouble();
}

vector<unique_ptr<Account>> Database::getAccounts() {
    auto queryPtr = make_unique<QSqlQuery>();
    queryPtr->exec("SELECT AccountId, Balance FROM Account");
    vector<unique_ptr<Account>> accounts;

    while (queryPtr->next())  {
        long long accountId = queryPtr->value(0).toLongLong();
        double balance = queryPtr->value(1).toDouble();
        unique_ptr<Account> account = make_unique<Account>(accountId);
        account->deposit(balance);
        accounts.push_back(move(account));
    }

    return accounts;
}

vector<unique_ptr<Transaction>> Database::getTransactions(long long accountId) {
    auto selectPtr = make_unique<QSqlQuery>();
    selectPtr->prepare("SELECT TransactionId, CounterpartyId, Amount, Timestamp " \
                       "FROM AccountTransaction WHERE AccountId = :accountId");
    selectPtr->bindValue(":accountId", accountId);
    if (!selectPtr->exec()) {
        qWarning() << "Could not execute getTransactions() with ID " << accountId << endl;
        abort();
    }
    vector<unique_ptr<Transaction>> transactions;

    while (selectPtr->next()) {
        long long transactionId = selectPtr->value(0).toLongLong();
        long long counterpartyId = selectPtr->value(1).toLongLong();
        double amount = selectPtr->value(2).toDouble();
        long long timestamp = selectPtr->value(3).toLongLong();
        Counterparty counterparty(counterpartyId, 0, "", "", "");
        unique_ptr<Transaction> transaction = make_unique<Transaction>(
                    transactionId, accountId, counterparty, amount, timestamp);
        transactions.push_back(move(transaction));
    }

    return transactions;
}

void Database::performTransaction(Transaction &transaction) {
    unique_ptr<Account> account = getAccount(transaction.getAccountId());
    if (transaction.getAmount() < 0) {
        account->withdraw(-transaction.getAmount());
    } else {
        account->deposit(transaction.getAmount());
    }
    auto query = make_unique<QSqlQuery>();
    query->prepare("UPDATE Account SET Balance = :balance WHERE AccountId = :accountId");
    query->bindValue(":balance", account->getBalance());
    query->bindValue(":accountId", account->getId());
    if (!query->exec()) {
        qWarning() << "Could not execute performTransaction() with account " << account->getId() << endl;
        abort();
    }
}

long Database::getLatestRowId(void) {
    QSqlQuery query;
    query.exec("SELECT last_insert_rowid()");
    query.next();
    return query.value(0).toLongLong();
}

void Database::rebuildTestDatabase(void) {
    // drop sample table, if it exists
    QSqlQuery query;
    query.exec("DROP TABLE IF EXISTS AccountTransaction");
    query.exec("DROP TABLE IF EXISTS AccountTransaction");
    query.exec("DROP TABLE IF EXISTS AccountTransaction");
    query.exec("DROP TABLE IF EXISTS Counterparty");
    query.exec("DROP TABLE IF EXISTS Account");

    // (re)create table
    query.exec("CREATE TABLE Account (AccountId INTEGER PRIMARY KEY, Balance REAL)");
    query.exec("CREATE TABLE Counterparty (CounterpartyId INTEGER PRIMARY KEY, RoutingNumber INTEGER(8), AccountId INTEGER(8), BusinessName TEXT, FirstName TEXT, LastName TEXT, FOREIGN KEY(AccountId) REFERENCES Account(AccountId))");
    query.exec("CREATE TABLE AccountTransaction (TransactionId INTEGER PRIMARY KEY, AccountId, CounterpartyId, Amount REAL, Timestamp INTEGER(8), FOREIGN KEY(AccountId) REFERENCES Account(AccountId), FOREIGN KEY(CounterpartyId) REFERENCES Counterparty(CounterpartyId))");

    QSqlQuery insertAccount;
    insertAccount.prepare("INSERT INTO Account (Balance) VALUES (:balance)");
    insertAccount.bindValue(":balance", 5000);
    insertAccount.exec();
    long long accountId1 = getLatestRowId();
    insertAccount.bindValue(":balance", 9000);
    insertAccount.exec();
    long long accountId2 = getLatestRowId();

    QSqlQuery insertCounterParty1;
    insertCounterParty1.prepare("INSERT INTO CounterParty (RoutingNumber, AccountId, BusinessName, FirstName, LastName) VALUES (?, ?, ?, ?, ?)");
    insertCounterParty1.addBindValue(0);
    insertCounterParty1.addBindValue(1010);
    insertCounterParty1.addBindValue("Acme");
    insertCounterParty1.addBindValue("Wile");
    insertCounterParty1.addBindValue("Cyote");
    insertCounterParty1.exec();
    long long counterpartyId1 = getLatestRowId();

    QSqlQuery insertCounterParty2;
    insertCounterParty2.prepare("INSERT INTO CounterParty (RoutingNumber, AccountId, BusinessName, FirstName, LastName) VALUES (?, ?, ?, ?, ?)");
    insertCounterParty2.addBindValue(1111);
    insertCounterParty2.addBindValue(accountId2);
    insertCounterParty2.addBindValue("LexCorp");
    insertCounterParty2.addBindValue("Lex");
    insertCounterParty2.addBindValue("Luthor");
    insertCounterParty2.exec();
    long long counterpartyId2 = getLatestRowId();

    QSqlQuery insertTransaction;
    insertTransaction.prepare("INSERT INTO AccountTransaction (AccountId, CounterpartyId, Amount, Timestamp) VALUES (:accId, :counterId, :amount, :time)");

    insertTransaction.bindValue(":accId", accountId2);
    insertTransaction.bindValue(":countId", counterpartyId2);
    insertTransaction.bindValue(":amount", 8000);
    insertTransaction.bindValue(":time", 1570049000);
    insertTransaction.exec();

    insertTransaction.bindValue(":accId", accountId2);
    insertTransaction.bindValue(":amount", -4000);
    insertTransaction.exec();
    insertTransaction.bindValue(":countId", counterpartyId1);

    /**
     * TODO: The code above has inserted two transactions for acountId2.
     * Now insert four transactions for accountId2. They should be
     * for the amount 4022, -2122, 4102 and 1002.
     *
     * When it is working the CLI menu should do the following:
     * Account 1. Make a selection.
     * 1. Display balance.
     * 2. List all transactions.
     * 3. View transaction.
     * 4. Exit.
     * 2
     *
     * Transactions for account 1
     * Transaction 1. 1 4022
     * Transaction 2. 2 -2122
     * Transaction 3. 3 4102
     * Transaction 4. 4 -1002
     */
    /* These instructions in the code say to do accountId2, instead of account 1,
     * but the assignment output says account 1 */
    insertTransaction.bindValue(":accId", accountId1);
    insertTransaction.bindValue(":amount", 4022);
    insertTransaction.bindValue(":time", 1570049000);
    insertTransaction.exec();

    insertTransaction.bindValue(":amount", -2122);
    insertTransaction.bindValue(":time", 1670049000);
    insertTransaction.exec();

    insertTransaction.bindValue(":amount", 4102);
    insertTransaction.bindValue(":time", 1770049000);
    insertTransaction.exec();

    insertTransaction.bindValue(":amount", -1002);
    insertTransaction.bindValue(":time", 1870049000);
    insertTransaction.exec();
}
