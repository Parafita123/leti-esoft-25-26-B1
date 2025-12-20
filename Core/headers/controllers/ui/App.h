#ifndef LETI_ESOFT_25_26_B1_APP_H
#define LETI_ESOFT_25_26_B1_APP_H

#include "headers/domain/model/VaccineTypeContainer.h"
#include "headers/domain/model/VaccineContainer.h"
#include "headers/domain/model/EmployeeContainer.h"
// Repository and service infrastructure headers for SNS user registration
#include "headers/domain/repositories/RepositoryFactory.h"
#include "headers/infrastructure/memory/MemoryRepositoryFactory.h"
#include "headers/domain/services/SNSUserService.h"
#include <memory>
#include "headers/domain/services/VaccinationCenterService.h"

class App {
private:
    VaccineContainer vaccineContainer;
    EmployeeContainer employeeContainer;
    std::shared_ptr<RepositoryFactory> repoFactory;
    std::shared_ptr<SNSUserService> snsUserService;
    std::shared_ptr<VaccinationCenterService> vaccinationCenterService;
    std::shared_ptr<VaccineTypeRepository> vaccineTypeRepo;

public:
    App();
    /**
     * Returns a reference to the vaccine container.
     */
    VaccineContainer& getVaccineContainer();
    EmployeeContainer &getEmployeeContainer();

    /**
     * Returns the service responsible for registering SNS users. It
     * encapsulates both the creation of user domain objects and their
     * persistence through the repository. Exposed so that UI
     * controllers can obtain a service instance without being aware
     * of the underlying persistence mechanism.
     */
    std::shared_ptr<SNSUserService> getSNSUserService();
    std::shared_ptr<VaccinationCenterService> getVaccinationCenterService();
    std::shared_ptr<VaccineTypeRepository> getVaccineTypeRepository();
    std::shared_ptr<RepositoryFactory> getRepositoryFactory();
};

#endif //LETI_ESOFT_25_26_B1_APP_H
