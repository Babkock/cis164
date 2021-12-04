/* Bank Database
 * Tanner Babcock
 * tababcock@dmacc.edu
 * December 3, 2021 */
#include "counterparty.h"

long Counterparty::getRoutingNumber(void) const {
    return routingNumber;
}

long Counterparty::getAccountId(void) const {
    return accountId;
}

std::string Counterparty::getBusinessName(void) const {
    return businessName;
}

std::string Counterparty::getFirstName(void) const {
    return firstName;
}

std::string Counterparty::getLastName(void) const {
    return lastName;
}
