#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "account.h"
#include "transaction.h"
using namespace std;

class Database {
private:
    long getLatestRowId(void);
public:
    Database(void);
    void rebuildTestDatabase(void);
    void performTransaction(Transaction &transaction);
    void createAccount(long long accountId);
    bool accountExists(long long accountId);
    double getBalance(long long accountId);
    unique_ptr<Account> getAccount(long long accountId);
    vector<unique_ptr<Account>> getAccounts(void);
    unique_ptr<Transaction> getTransaction(long long transactionId);
    vector<unique_ptr<Transaction>> getTransactions(long long accountId);
};

#endif // DATABASE_H
