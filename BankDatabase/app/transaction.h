#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <ctime>
#include "account.h"
#include "counterparty.h"

class Transaction {
    private:
        long long transactionId;
        long long accountId;
        Counterparty counterparty;
        double amount;
        time_t timestamp;
    public:
        Transaction(long long transactionId, long long accountId,
            Counterparty counterparty, double amount, time_t timestamp);
        long long getTransactionId(void) const;
        long long getAccountId(void) const;
        double getAmount(void) const;
        Counterparty getCounterparty(void) const;
};

#endif //TRANSACTION_H
