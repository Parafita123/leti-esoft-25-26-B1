// created by Guta on 2025-12-20
//
// Implementation of the in-memory waiting room repository.

#include "headers/infrastructure/memory/WaitingRoomMemoryRepository.h"

Result WaitingRoomMemoryRepository::removeSNSUser(const std::string &snsUserNumber) {
    auto it = std::find(waitingList.begin(), waitingList.end(), snsUserNumber);
    if (it == waitingList.end()) {
        return Result::NOK(L"SNS user not found in waiting room.");
    }
    waitingList.erase(it);
    return Result::OK();
}