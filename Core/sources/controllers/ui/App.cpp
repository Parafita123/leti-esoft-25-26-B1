//
// Created by Filipe on 04/11/2025.
//
#include "headers/controllers/ui/App.h"

// Include repositories and service for vaccination process
#include "headers/domain/repositories/VaccinationProcessRepository.h"
#include "headers/domain/repositories/WaitingRoomRepository.h"
#include "headers/domain/repositories/RecoveryRoomRepository.h"
#include "headers/domain/services/VaccinationProcessService.h"
#include "headers/infrastructure/memory/VaccinationProcessMemoryRepository.h"
#include "headers/infrastructure/memory/WaitingRoomMemoryRepository.h"
#include "headers/infrastructure/memory/RecoveryRoomMemoryRepository.h"
#include "headers/domain/repositories/VaccineTypeRepository.h"
#include "headers/domain/repositories/RepositoryFactory.h"
#include "headers/infrastructure/memory/MemoryRepositoryFactory.h"
#include <memory>
#include "headers/domain/services/VaccinationCenterService.h"


VaccineTypeContainer& App::getVaccineTypeContainer() {
    return vaccineTypeContainer;
}

VaccineContainer& App::getVaccineContainer() {
    return vaccineContainer;
}

EmployeeContainer &App::getEmployeeContainer() {
    return employeeContainer;
}

SNSUserContainer &App::getSNSUserContainer() {
    return snsUserContainer;
}

std::shared_ptr<VaccinationProcessService> App::getVaccinationProcessService() {
    // Lazy initialize on first use
    if (!vaccinationProcessService) {
        vaccinationProcessRepository = std::make_shared<VaccinationProcessMemoryRepository>();
        waitingRoomRepository = std::make_shared<WaitingRoomMemoryRepository>();
        recoveryRoomRepository = std::make_shared<RecoveryRoomMemoryRepository>();
        vaccinationProcessService = std::make_shared<VaccinationProcessService>(
                vaccinationProcessRepository, waitingRoomRepository, recoveryRoomRepository);
    }
    return vaccinationProcessService;
}

std::shared_ptr<VaccineTypeRepository> App::getVaccineTypeRepository() {
    return repositoryFactory->getVaccineTypeRepository();
    vaccinationCenterService = std::make_shared<VaccinationCenterService>(
            repositoryFactory->getVaccinationCenterRepository(),
            vaccineTypeRepo);
}

App::App() {
    repositoryFactory = std::make_shared<MemoryRepositoryFactory>();

    vaccineTypeRepo = repositoryFactory->getVaccineTypeRepository();

    auto ctrRepo = repositoryFactory->getVaccinationCenterRepository();
    auto vtRepo  = repositoryFactory->getVaccineTypeRepository();
    auto arrivalRepo = repositoryFactory->getUserArrivalRepository();
    auto snsRepo     = repositoryFactory->getSNSUserRepository();
    auto centerRepo  = repositoryFactory->getVaccinationCenterRepository();
    auto apptRepo    = repositoryFactory->getVaccinationAppointmentRepository();

    userArrivalService = std::make_shared<UserArrivalService>(repositoryFactory);

}

std::shared_ptr<SNSUserService> App::getSNSUserService() {
    auto repo = repositoryFactory->getSNSUserRepository();
    return std::make_shared<SNSUserService>(repo);
}

std::shared_ptr<VaccinationCenterService> App::getVaccinationCenterService() {
    return vaccinationCenterService;
}

std::shared_ptr<RepositoryFactory> App::getRepositoryFactory() {
    return repositoryFactory;
}

std::shared_ptr<UserArrivalService> App::getUserArrivalService() {
    return userArrivalService;
}
