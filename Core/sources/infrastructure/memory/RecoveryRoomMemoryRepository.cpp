// created by Guta on 2025-12-20
//
// Implementation of the in-memory recovery room repository.

#include "headers/infrastructure/memory/RecoveryRoomMemoryRepository.h"

Result RecoveryRoomMemoryRepository::assignSNSUser(const std::string &snsUserNumber) {
    // Simply add the SNS user identifier to the recovery list.  We do
    // not enforce capacity constraints as these are outside the scope
    // of this simplified implementation.
    recoveryList.push_back(snsUserNumber);
    return Result::OK();
}