#ifndef CLI_H
#define CLI_H

#include <iostream>
#include "bank.h"

class Cli {
private:
    Bank &bank;
    void printGreeting(void);
    void printAccounts(void);
    void printTransactions(Account &accountId);
    void printTransaction(long transactionId);
    void mainMenu(void);
    void accountMenu(long accountId);
public:
    Cli(Bank &bank): bank(bank) {}
    void start(void);
};

#endif // CLI_H
