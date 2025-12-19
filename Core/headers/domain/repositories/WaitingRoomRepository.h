//
// Created by Guta on 18/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_WAITINGROOMREPOSITORY_H
#define LETI_ESOFT_25_26_B1_WAITINGROOMREPOSITORY_H

#include <string>
#include <vector>

/**
 * Interface for managing the waiting room.  The waiting room holds
 * SNS user numbers of patients waiting to be vaccinated.  Once a
 * vaccination is recorded, the SNS user is removed from the waiting
 * room.
 */
class WaitingRoomRepository {
public:
    virtual ~WaitingRoomRepository() = default;

    /**
     * Removes an SNS user from the waiting room.  If the user is
     * present, the method returns true and removes it; otherwise
     * returns false.
     */
    virtual bool removeSNSUser(const std::string &snsUserNumber) = 0;

    /**
     * Adds an SNS user to the waiting room.  Not required by US41
     * but included for completeness.
     */
    virtual void addSNSUser(const std::string &snsUserNumber) = 0;

    /**
     * Returns the current list of SNS user numbers in the waiting room.
     */
    virtual std::vector<std::string> listWaitingUsers() const = 0;
};

#endif // LETI_ESOFT_25_26_B1_WAITINGROOMREPOSITORY_H