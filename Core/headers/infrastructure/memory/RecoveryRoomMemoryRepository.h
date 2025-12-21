// created by Guta on 2025-12-20


#ifndef LETI_ESOFT_25_26_B1_RECOVERYROOMMEMORYREPOSITORY_H
#define LETI_ESOFT_25_26_B1_RECOVERYROOMMEMORYREPOSITORY_H

#include <vector>
#include <string>
#include "headers/domain/repositories/RecoveryRoomRepository.h"

class RecoveryRoomMemoryRepository : public RecoveryRoomRepository {
private:
    std::vector<std::string> recoveryList;
public:
    Result assignSNSUser(const std::string &snsUserNumber) override;
};

#endif // LETI_ESOFT_25_26_B1_RECOVERYROOMMEMORYREPOSITORY_H