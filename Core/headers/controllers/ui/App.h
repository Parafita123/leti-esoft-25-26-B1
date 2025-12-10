#ifndef LETI_ESOFT_25_26_B1_APP_H
#define LETI_ESOFT_25_26_B1_APP_H

#include "headers/domain/model/VaccineTypeContainer.h"
#include "headers/domain/model/VaccineContainer.h"
#include "headers/domain/model/EmployeeContainer.h"

// Repository and service infrastructure headers for SNS user registration
#include "headers/domain/repositories/RepositoryFactory.h"
#include "headers/infrastructure/memory/MemoryRepositoryFactory.h"
#include "headers/domain/services/SNSUserService.h"

class App {
private:
    VaccineTypeContainer vaccineTypeContainer;
    VaccineContainer vaccineContainer;
    EmployeeContainer employeeContainer;
    // Repository factory that supplies repositories for various domain
    // entities.  For now we only require an SNS user repository but
    // additional repositories can be added in future sprints.
    std::shared_ptr<RepositoryFactory> repoFactory;
    // Service responsible for SNS user registration, built on top of
    // the repository returned by the factory.
    std::shared_ptr<SNSUserService> snsUserService;

public:
    App();

    VaccineTypeContainer& getVaccineTypeContainer();

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
};

#endif //LETI_ESOFT_25_26_B1_APP_H
