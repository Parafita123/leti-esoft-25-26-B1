//
// Created by Filipe on 20/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_REGISTERUSERARRIVALCONTROLLER_H
#define LETI_ESOFT_25_26_B1_REGISTERUSERARRIVALCONTROLLER_H

#pragma once

#include <vector>
#include <optional>
#include <memory>
#include "headers/domain/shared/Result.h"
#include "headers/controllers/dto/UserArrivalDTO.h"
#include "headers/controllers/dto/FacilityDto.h"
#include "headers/controllers/dto/SNSUserDto.h"

class App;
class UserArrivalService;
class RepositoryFactory;
class VaccinationCenterRepository;
class SNSUserRepository;

class RegisterUserArrivalController {
private:
    App& app;
    std::shared_ptr<UserArrivalService> service;

public:
    explicit RegisterUserArrivalController(App& app);

    std::vector<FacilityDto> listFacilities();
    std::optional<SNSUserDto> getSNSUserSummary(int snsNumber);

    Result registerArrival(const UserArrivalDTO& dto);
};

#endif //LETI_ESOFT_25_26_B1_REGISTERUSERARRIVALCONTROLLER_H
