// created by Guta on 2025-12-20
//
// Interface definition for a repository managing the recovery room where
// citizens stay after being vaccinated.  Assigning a citizen to the
// recovery room should succeed only if capacity allows.

#ifndef LETI_ESOFT_25_26_B1_RECOVERYROOMREPOSITORY_H
#define LETI_ESOFT_25_26_B1_RECOVERYROOMREPOSITORY_H

#include <string>
#include "headers/domain/shared/Result.h"

class RecoveryRoomRepository {
public:
    virtual ~RecoveryRoomRepository() = default;

    /**
     * Assigns the SNS user with the given identifier to the recovery room.
     * Returns a Result indicating success or failure.
     */
    virtual Result assignSNSUser(const std::string &snsUserNumber) = 0;
};

#endif // LETI_ESOFT_25_26_B1_RECOVERYROOMREPOSITORY_H