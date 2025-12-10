#include "headers/controllers/ui/App.h"

// Include service and repository implementation headers for SNS users
#include "headers/infrastructure/memory/MemoryRepositoryFactory.h"
#include "headers/domain/services/SNSUserService.h"

App::App() {
    // Initialize the repository factory. In this sprint we always use
    // the in‑memory implementation. In later sprints this could be
    // chosen based on a configuration file (e.g. memory, file, SQL).
    this->repoFactory = std::make_shared<MemoryRepositoryFactory>();
    // Create the SNS user service using the repository provided by the factory.
    this->snsUserService = std::make_shared<SNSUserService>(repoFactory->getSNSUserRepository());
}

VaccineTypeContainer& App::getVaccineTypeContainer() {
    return vaccineTypeContainer;
}

VaccineContainer& App::getVaccineContainer() {
    return vaccineContainer;
}

EmployeeContainer &App::getEmployeeContainer() {
    return employeeContainer;
}

std::shared_ptr<SNSUserService> App::getSNSUserService() {
    return this->snsUserService;
}
