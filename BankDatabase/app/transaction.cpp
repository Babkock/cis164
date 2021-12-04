/* Bank Database
 * Tanner Babcock
 * tababcock@dmacc.edu
 * December 3, 2021 */
#include <ctime>
#include "transaction.h"

Transaction::Transaction(long long transactionId, long long accountId, Counterparty counterparty,
        double amount, time_t timestamp): transactionId(transactionId),
        accountId(accountId), counterparty(counterparty), amount(amount),
        timestamp(timestamp) {
}

long long Transaction::getTransactionId(void) const {
    return transactionId;
}

long long Transaction::getAccountId(void) const {
    return accountId;
}

double Transaction::getAmount(void) const {
    return amount;
}

Counterparty Transaction::getCounterparty(void) const {
    return counterparty;
}
