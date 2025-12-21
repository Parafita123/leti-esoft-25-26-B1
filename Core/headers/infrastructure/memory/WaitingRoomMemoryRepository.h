// created by Guta on 2025-12-20
//
// In-memory implementation of the WaitingRoomRepository.  Maintains a
// simple list of SNS user identifiers representing citizens awaiting
// vaccination.  Removal succeeds only if the identifier exists.

#ifndef LETI_ESOFT_25_26_B1_WAITINGROOMMEMORYREPOSITORY_H
#define LETI_ESOFT_25_26_B1_WAITINGROOMMEMORYREPOSITORY_H

#include <vector>
#include <string>
#include <algorithm>
#include "headers/domain/repositories/WaitingRoomRepository.h"

class WaitingRoomMemoryRepository : public WaitingRoomRepository {
private:
    std::vector<std::string> waitingList;
public:
    /**
     * Adds a user to the waiting list.  This helper is provided to
     * simulate population of the waiting room in tests.  It is not
     * specified by the US but makes the repository usable.
     */
    void addSNSUser(const std::string &snsUserNumber) {
        waitingList.push_back(snsUserNumber);
    }

    Result removeSNSUser(const std::string &snsUserNumber) override;
};

#endif // LETI_ESOFT_25_26_B1_WAITINGROOMMEMORYREPOSITORY_H