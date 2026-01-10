//
// Created by Filipe on 10/01/2026.
//

#ifndef LETI_ESOFT_25_26_B1_USERARRIVALREPOSITORYMOCK_H
#define LETI_ESOFT_25_26_B1_USERARRIVALREPOSITORYMOCK_H
#pragma once

#include "gmock/gmock.h"
#include <headers/domain/repositories/UserArrivalRepository.h>

class UserArrivalRepositoryMock : public UserArrivalRepository {
public:
    MOCK_METHOD(Result, save, (std::shared_ptr<UserArrival> obj), (override));

    MOCK_METHOD(bool, exists,
                (const std::string& snsUserNumber, int facilityID, const std::string& day),
                (override));

    MOCK_METHOD((std::vector<std::shared_ptr<UserArrival>>), findAll, (), (override));
};

#endif //LETI_ESOFT_25_26_B1_USERARRIVALREPOSITORYMOCK_H
