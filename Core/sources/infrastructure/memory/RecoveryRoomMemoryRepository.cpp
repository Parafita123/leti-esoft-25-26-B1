//
// Created by Guta on 19/12/2025.
//

#include "headers/infrastructure/memory/RecoveryRoomMemoryRepository.h"

bool RecoveryRoomMemoryRepository::assignSNSUser(const std::string &snsUserNumber) {
    auto result = recovery.insert(snsUserNumber);
    return result.second; // true if inserted, false if already existed
}

bool RecoveryRoomMemoryRepository::removeSNSUser(const std::string &snsUserNumber) {
    auto it = recovery.find(snsUserNumber);
    if (it != recovery.end()) {
        recovery.erase(it);
        return true;
    }
    return false;
}

std::vector<std::string> RecoveryRoomMemoryRepository::listRecoveryUsers() const {
    return std::vector<std::string>(recovery.begin(), recovery.end());
}
