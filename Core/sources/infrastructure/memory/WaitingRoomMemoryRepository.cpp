//
// Created by Guta on 18/12/2025.
//

#include "headers/infrastructure/memory/WaitingRoomMemoryRepository.h"

bool WaitingRoomMemoryRepository::removeSNSUser(const std::string &snsUserNumber) {
    auto it = waiting.find(snsUserNumber);
    if (it != waiting.end()) {
        waiting.erase(it);
        return true;
    }
    return false;
}

void WaitingRoomMemoryRepository::addSNSUser(const std::string &snsUserNumber) {
    waiting.insert(snsUserNumber);
}

std::vector<std::string> WaitingRoomMemoryRepository::listWaitingUsers() const {
    return std::vector<std::string>(waiting.begin(), waiting.end());
}