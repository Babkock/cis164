/* Bank Database
 * Tanner Babcock
 * tababcock@dmacc.edu
 * December 3, 2021 */
#include "account.h"

Account::Account(long long accountId): accountId(accountId) {
    balance = 0.0;
}

double Account::getBalance(void) const {
    return balance;
}

long long Account::getId(void) const {
    return accountId;
}

void Account::setId(long long accountId) {
    this->accountId = accountId;
}

double Account::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        return amount;
    } else {
        return 0;
    }
}

double Account::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        return amount;
    } else {
        return 0;
    }
}
