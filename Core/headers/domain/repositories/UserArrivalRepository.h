//
// Created by Filipe on 20/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_USERARRIVALREPOSITORY_H
#define LETI_ESOFT_25_26_B1_USERARRIVALREPOSITORY_H

#pragma once
#include <memory>
#include <string>
#include "headers/domain/shared/Result.h"
#include "headers/domain/model/UserArrival.h"

class UserArrivalRepository {
public:
    virtual ~UserArrivalRepository() = default;

    virtual Result save(std::shared_ptr<UserArrival> obj) = 0;

    virtual bool exists(const std::string& snsUserNumber,
                        int facilityID,
                        const std::string& day) = 0;
};

#endif //LETI_ESOFT_25_26_B1_USERARRIVALREPOSITORY_H
