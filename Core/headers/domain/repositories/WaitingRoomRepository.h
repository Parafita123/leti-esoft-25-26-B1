// created by Guta on 2025-12-20
//
// Interface definition for a repository managing the waiting room of
// citizens awaiting vaccination.  It allows removal of citizens once
// they have been vaccinated.

#ifndef LETI_ESOFT_25_26_B1_WAITINGROOMREPOSITORY_H
#define LETI_ESOFT_25_26_B1_WAITINGROOMREPOSITORY_H

#include <string>
#include "headers/domain/shared/Result.h"

class WaitingRoomRepository {
public:
    virtual ~WaitingRoomRepository() = default;

    /**
     * Removes the SNS user with the given identifier from the waiting room.
     * Returns a Result indicating success or failure (e.g. if the user is
     * not found).
     */
    virtual Result removeSNSUser(const std::string &snsUserNumber) = 0;
};

#endif // LETI_ESOFT_25_26_B1_WAITINGROOMREPOSITORY_H