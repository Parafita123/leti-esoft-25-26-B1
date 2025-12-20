//
// Created by Filipe on 20/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_USERARRIVALMEMORYREPOSITORY_H
#define LETI_ESOFT_25_26_B1_USERARRIVALMEMORYREPOSITORY_H

#pragma once
#include <vector>
#include <memory>
#include <string>
#include <chrono>

#include "headers/domain/repositories/UserArrivalRepository.h"

class UserArrivalMemoryRepository : public UserArrivalRepository {
private:
    std::vector<std::shared_ptr<UserArrival>> data;

    static std::string toDayString(std::chrono::system_clock::time_point tp);

public:
    Result save(std::shared_ptr<UserArrival> obj) override;

    bool exists(const std::string& snsUserNumber,
                int facilityID,
                const std::string& day) override;
};
#endif //LETI_ESOFT_25_26_B1_USERARRIVALMEMORYREPOSITORY_H
