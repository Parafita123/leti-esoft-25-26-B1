//
// Created by Filipe on 04/11/2025.
//

#ifndef LETI_ESOFT_25_26_B1_APP_H
#define LETI_ESOFT_25_26_B1_APP_H

#include "headers/domain/repositories/VaccinationProcessRepository.h"
#include "headers/domain/repositories/WaitingRoomRepository.h"
#include "headers/domain/repositories/RecoveryRoomRepository.h"
#include "headers/domain/services/VaccinationProcessService.h"
#include "headers/domain/repositories/VaccineTypeRepository.h"
#include "headers/domain/model/VaccineTypeContainer.h"
#include "headers/domain/model/VaccineContainer.h"
#include "headers/domain/model/EmployeeContainer.h"
#include "headers/domain/model/SNSUserContainer.h"
#include "headers/domain/repositories/RepositoryFactory.h"
#include "headers/domain/services/SNSUserService.h"
#include <memory>
#include "headers/domain/services/VaccinationCenterService.h"
#include "headers/domain/services/UserArrivalService.h"

class App {
private:
    VaccineTypeContainer vaccineTypeContainer;
    VaccineContainer vaccineContainer;
    EmployeeContainer employeeContainer;
    SNSUserContainer snsUserContainer;


    // Repositories and services for recording vaccination processes
    std::shared_ptr<VaccinationProcessRepository> vaccinationProcessRepository;
    std::shared_ptr<WaitingRoomRepository> waitingRoomRepository;
    std::shared_ptr<RepositoryFactory> repositoryFactory;
    std::shared_ptr<RecoveryRoomRepository> recoveryRoomRepository;
    std::shared_ptr<VaccinationProcessService> vaccinationProcessService;
    std::shared_ptr<VaccinationCenterService> vaccinationCenterService;
    std::shared_ptr<VaccineTypeRepository> vaccineTypeRepo;
    std::shared_ptr<UserArrivalService> userArrivalService;
    static std::shared_ptr<App> instance;

public:
    App();
    static App& getInstance();
    VaccineTypeContainer& getVaccineTypeContainer();
    std::shared_ptr<VaccineTypeRepository> getVaccineTypeRepository();
    std::shared_ptr<SNSUserService> getSNSUserService();
    /**
     * Returns a reference to the vaccine container.
     */
    VaccineContainer& getVaccineContainer();
    EmployeeContainer &getEmployeeContainer();

    /**
     * Returns a reference to the SNS user container.
     */
    SNSUserContainer &getSNSUserContainer();
    std::shared_ptr<VaccinationCenterService> getVaccinationCenterService();
    std::shared_ptr<RepositoryFactory> getRepositoryFactory();

    /**
     * Returns the service responsible for recording vaccination processes.
     */
    std::shared_ptr<VaccinationProcessService> getVaccinationProcessService();
    std::shared_ptr<UserArrivalService> getUserArrivalService();
};

#endif //LETI_ESOFT_25_26_B1_APP_H
