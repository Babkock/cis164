/* Bank Database
 * Tanner Babcock
 * tababcock@dmacc.edu
 * December 3, 2021 */
#include <iostream>
#include <memory>
#include "cli.h"
#include "transaction.h"
using namespace std;

void Cli::printAccounts(void) {
    /**
     * TODO: Display all accounts. Use bank.getAccounts() which makes a call
     * to the database layer.
     *
     * When it is working the CLI should do the following:
     * 1. List all accounts.
     * 2. View account.
     * 3. Exit.
     * 1
     *
     * Bank Accounts
     * Account 1 has balance 5000
     * Account 2 has balance 9000
     */

    cout << "Bank Accounts" << endl;
    vector<unique_ptr<Account>> acc;
    acc = bank.getAccounts();

    for (auto &account : acc) {
        cout << "Account " << account->getId() << " has balance $" << account->getBalance() << endl;
    }
}

void Cli::printTransactions(Account &account) {
    int count = 1;
    cout << endl << "Transactions for account " << account.getId() << endl;
    vector<unique_ptr<Transaction>> transactions = bank.getTransactions(account.getId());
    for (auto &transaction : transactions) {
        cout << "Transaction " << transaction->getTransactionId() << ". (" << count << ") $" << transaction->getAmount() << endl;
        count++;
    }
}

void Cli::printTransaction(long transactionId) {
    unique_ptr<Transaction> transaction = bank.getTransaction(transactionId);
    cout << "Transaction " << transaction->getTransactionId() << " $" << transaction->getAmount() << endl;
}

void Cli::printGreeting(void) {
    cout << "============================" << endl;
    cout << "=  Welcome to " << bank.getName() << ".   =" << endl;
    cout << "============================" << endl;
}

void Cli::accountMenu(long accountId) {
    int selection;
    bool exit = false;

    unique_ptr<Account> account = bank.getAccount(accountId);

    while (!exit) {
        cout << endl;
        cout << "Account " << account->getId() << ". Make a selection." << endl;
        cout << "1. Display balance. " << endl;
        cout << "2. List all transactions. " << endl;
        cout << "3. View transaction. " << endl;
        cout << "4. Exit. " << endl;
        cin >> selection;
        switch (selection) {
            case 1:
                cout << endl << "Current balance is $" << account->getBalance() << endl;
                break;
            case 2:
                printTransactions(*account);
                break;
            case 3:
                int transactionId;
                cout << "Select transaction by id: " << endl;
                cin >> transactionId;
                printTransaction(transactionId);
                break;
            case 4:
                exit = true;
                break;
            default:
                cout << "Invlaid selection." << endl;
                break;
        }
    }
}

void Cli::mainMenu(void) {
    int selection;
    long accountId;
    bool exit = false;

    while (!exit) {
        cout << endl;
        printGreeting();
        cout << "1. List all accounts. " << endl;
        cout << "2. View account. " << endl;
        cout << "3. Exit. " << endl;
        cin >> selection;
        switch (selection) {
            case 1:
                printAccounts();
                break;
            case 2:
                cout << "Select account: ";
                cin >> accountId;
                accountMenu(accountId);
                cout << endl;
                break;
            case 3:
                cout << "Goodbye." << endl;
                exit = true;
                break;
            default:
                cout << "Invlaid selection." << endl;
        }
    }
}

void Cli::start(void) {
    mainMenu();
}
