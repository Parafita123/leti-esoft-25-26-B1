//
// Created by Guta on 18/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_WAITINGROOMMEMORYREPOSITORY_H
#define LETI_ESOFT_25_26_B1_WAITINGROOMMEMORYREPOSITORY_H

#include "headers/domain/repositories/WaitingRoomRepository.h"
#include <set>

/**
 * In‑memory implementation of WaitingRoomRepository.  Uses a set
 * to store SNS user numbers currently in the waiting room.
 */
class WaitingRoomMemoryRepository : public WaitingRoomRepository {
private:
    std::set<std::string> waiting;

public:
    bool removeSNSUser(const std::string &snsUserNumber) override;
    void addSNSUser(const std::string &snsUserNumber) override;
    std::vector<std::string> listWaitingUsers() const override;
};

#endif // LETI_ESOFT_25_26_B1_WAITINGROOMMEMORYREPOSITORY_H