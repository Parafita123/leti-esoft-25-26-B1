#ifndef LETI_ESOFT_25_26_B1_REPOSITORYFACTORYMOCK_H
#define LETI_ESOFT_25_26_B1_REPOSITORYFACTORYMOCK_H

#pragma once

#include "gmock/gmock.h"

// Interface real
#include <headers/domain/repositories/RepositoryFactory.h>

// Repos reais (tipos usados nos returns)
#include <headers/domain/repositories/SNSUserRepository.h>
#include <headers/domain/repositories/VaccinationCenterRepository.h>
#include <headers/domain/repositories/VaccineTypeRepository.h>
#include <headers/domain/repositories/VaccinationProcessRepository.h>
#include <headers/domain/repositories/WaitingRoomRepository.h>
#include <headers/domain/repositories/RecoveryRoomRepository.h>
#include <headers/domain/repositories/VaccineRepository.h>

#include <headers/domain/repositories/UserArrivalRepository.h>
#include <headers/domain/repositories/VaccinationAppointmentRepository.h>

class RepositoryFactoryMock : public RepositoryFactory {
public:
    MOCK_METHOD(std::shared_ptr<SNSUserRepository>, getSNSUserRepository, (), (override));
    MOCK_METHOD(std::shared_ptr<VaccinationCenterRepository>, getVaccinationCenterRepository, (), (override));
    MOCK_METHOD(std::shared_ptr<VaccineTypeRepository>, getVaccineTypeRepository, (), (override));
    MOCK_METHOD(std::shared_ptr<VaccinationAppointmentRepository>, getVaccinationAppointmentRepository, (), (override));
    MOCK_METHOD(std::shared_ptr<UserArrivalRepository>, getUserArrivalRepository, (), (override));
    MOCK_METHOD(std::shared_ptr<VaccineRepository>, getVaccineRepository, (), (override));
    MOCK_METHOD(std::shared_ptr<VaccinationProcessRepository>, getVaccinationProcessRepository, (), (override));
    MOCK_METHOD(std::shared_ptr<WaitingRoomRepository>, getWaitingRoomRepository, (), (override));
    MOCK_METHOD(std::shared_ptr<RecoveryRoomRepository>, getRecoveryRoomRepository, (), (override));
};


#endif
