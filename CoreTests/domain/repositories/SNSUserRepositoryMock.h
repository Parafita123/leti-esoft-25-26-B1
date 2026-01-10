//
// Created by Filipe on 10/01/2026.
//

#ifndef LETI_ESOFT_25_26_B1_SNSUSERREPOSITORYMOCK_H
#define LETI_ESOFT_25_26_B1_SNSUSERREPOSITORYMOCK_H
#pragma once

#include "gmock/gmock.h"
#include <headers/domain/repositories/SNSUserRepository.h>

class SNSUserRepositoryMock : public SNSUserRepository {
public:
    MOCK_METHOD(Result, save, (std::shared_ptr<SNSUser> user), (override));
    MOCK_METHOD(std::list<std::shared_ptr<SNSUser>>, getAll, (), (override));

    MOCK_METHOD(std::optional<std::shared_ptr<SNSUser>>, getByPhoneNumber,
                (const std::string &phone), (override));

    MOCK_METHOD(std::optional<std::shared_ptr<SNSUser>>, getByEmail,
                (const std::string &email), (override));

    MOCK_METHOD(std::optional<std::shared_ptr<SNSUser>>, getByCitizenCardNumber,
                (const std::string &cc), (override));

    MOCK_METHOD(std::optional<std::shared_ptr<SNSUser>>, getBySNSUserNumber,
                (const std::string &sns), (override));
};

#endif //LETI_ESOFT_25_26_B1_SNSUSERREPOSITORYMOCK_H
