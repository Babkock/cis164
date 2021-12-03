#ifndef BANK_H
#define BANK_H

#include <vector>
#include <memory>
#include <unordered_map>
#include <map>
#include "transaction.h"
#include "database.h"

class Bank {
private:
    string name;
    long nextUniqueId = 1000;
    Database database;
public:
    void setName(std::string const & name) { this->name = name; }
    string getName(void) const { return name; }
    unique_ptr<Account> getAccount(long long accountId);
    void createAccount(long long accountId);
    bool accountExists(long long accountId);
    double getBalance(long long accountId);
    vector<unique_ptr<Account>> getAccounts(void);
    unique_ptr<Transaction> getTransaction(long long transactionId);
    vector<unique_ptr<Transaction>> getTransactions(long long accountId);
    void performTransactions(vector<unique_ptr<Transaction>>& transactions);
    long getUniqueId(void);
};

#endif // BANK_H
