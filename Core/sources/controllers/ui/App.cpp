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

std::shared_ptr<App> App::instance = nullptr;

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
        // obtain the repositories through the factory so that they can be
        // shared with other parts of the application
        vaccinationProcessRepository = repositoryFactory->getVaccinationProcessRepository();
        waitingRoomRepository       = repositoryFactory->getWaitingRoomRepository();
        recoveryRoomRepository      = repositoryFactory->getRecoveryRoomRepository();
        vaccinationProcessService   = std::make_shared<VaccinationProcessService>(
                vaccinationProcessRepository,
                waitingRoomRepository,
                recoveryRoomRepository);
    }
    return vaccinationProcessService;
}

std::shared_ptr<VaccineTypeRepository> App::getVaccineTypeRepository() {
    // always return the repository from the factory.  Initialization of
    // other services should not occur after this return statement.
    return repositoryFactory->getVaccineTypeRepository();
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

    // initialize user arrival service with repository factory so it can
    // obtain its own dependencies as required
    userArrivalService = std::make_shared<UserArrivalService>(repositoryFactory);

    // initialize vaccination center service with the appropriate
    // repositories.  this must be done here because the return
    // statement in getVaccineTypeRepository previously prevented
    // initialization.
    vaccinationCenterService = std::make_shared<VaccinationCenterService>(
            repositoryFactory->getVaccinationCenterRepository(),
            repositoryFactory->getVaccineTypeRepository());

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

App& App::getInstance() {
    if (instance == nullptr) {
        // Criar a instância se ainda não existir
        instance = std::shared_ptr<App>(new App());
    }
    return *instance;
}