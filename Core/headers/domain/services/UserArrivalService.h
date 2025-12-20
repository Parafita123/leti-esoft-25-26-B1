//
// Created by Filipe on 20/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_USERARRIVALSERVICE_H
#define LETI_ESOFT_25_26_B1_USERARRIVALSERVICE_H

#pragma once

#include <memory>
#include <string>
#include "headers/domain/shared/Result.h"
#include "headers/controllers/dto/UserArrivalDTO.h"

class RepositoryFactory;
class UserArrivalRepository;
class SNSUserRepository;
class VaccinationCenterRepository;
class VaccinationAppointmentRepository;

class UserArrivalService {
private:
    std::shared_ptr<RepositoryFactory> repoFactory;

    std::string getTodayDate() const; // YYYY-MM-DD

public:
    explicit UserArrivalService(std::shared_ptr<RepositoryFactory> repoFactory);

    Result registerArrival(const UserArrivalDTO& dto);
};


#endif //LETI_ESOFT_25_26_B1_USERARRIVALSERVICE_H
