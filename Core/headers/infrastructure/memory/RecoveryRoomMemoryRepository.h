//
// Created by Guta on 19/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_RECOVERYROOMMEMORYREPOSITORY_H
#define LETI_ESOFT_25_26_B1_RECOVERYROOMMEMORYREPOSITORY_H

#include "headers/domain/repositories/RecoveryRoomRepository.h"
#include <set>

/**
 * In‑memory implementation of the RecoveryRoomRepository.  Uses a set
 * to store SNS user numbers currently assigned to the recovery room.  A
 * user can only be assigned once; duplicate assignments are ignored.
 */
class RecoveryRoomMemoryRepository : public RecoveryRoomRepository {
private:
    std::set<std::string> recovery;

public:
    bool assignSNSUser(const std::string &snsUserNumber) override;
    bool removeSNSUser(const std::string &snsUserNumber) override;
    std::vector<std::string> listRecoveryUsers() const override;
};

#endif // LETI_ESOFT_25_26_B1_RECOVERYROOMMEMORYREPOSITORY_H
