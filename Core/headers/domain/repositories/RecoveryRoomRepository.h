//
// Created by Guta on 18/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_RECOVERYROOMREPOSITORY_H
#define LETI_ESOFT_25_26_B1_RECOVERYROOMREPOSITORY_H

#include <string>
#include <vector>

/**
 * Interface for managing the recovery room.  The recovery room
 * holds SNS user numbers of patients who have just been vaccinated
 * and are under observation.  When the patient leaves the recovery
 * room (future user story), they are removed from this list.
 */
class RecoveryRoomRepository {
public:
    virtual ~RecoveryRoomRepository() = default;

    /**
     * Assigns an SNS user to the recovery room.  Returns true if
     * assigned successfully (user not already present), false if the
     * user was already assigned.
     */
    virtual bool assignSNSUser(const std::string &snsUserNumber) = 0;

    /**
     * Removes an SNS user from the recovery room.  Returns true if
     * removed successfully, false otherwise.
     */
    virtual bool removeSNSUser(const std::string &snsUserNumber) = 0;

    /**
     * Lists all SNS user numbers currently in the recovery room.
     */
    virtual std::vector<std::string> listRecoveryUsers() const = 0;
};

#endif // LETI_ESOFT_25_26_B1_RECOVERYROOMREPOSITORY_H