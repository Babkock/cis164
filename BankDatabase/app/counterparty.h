#ifndef COUNTERPARTY_H
#define COUNTERPARTY_H

#include <iostream>

class Counterparty {
private:
    long routingNumber;
    long accountId;
    std::string businessName;
    std::string firstName;
    std::string lastName;
public:
    Counterparty(long routingNumber, long accountId,
                 std::string businessName, std::string firstName, std::string lastName):
        routingNumber(routingNumber), accountId(accountId),
        businessName(businessName), firstName(firstName),
        lastName(lastName) {}
    long getRoutingNumber(void) const;
    long getAccountId(void) const;
    std::string getBusinessName(void) const;
    std::string getFirstName(void) const;
    std::string getLastName(void) const;
};

#endif //COUNTERPARTY_H
