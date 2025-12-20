#include "headers/controllers/ui/App.h"

// Include service and repository implementation headers for SNS users
#include "headers/infrastructure/memory/MemoryRepositoryFactory.h"
#include "headers/domain/services/SNSUserService.h"
#include "headers/domain/repositories/VaccinationCenterRepository.h"
#include "headers/domain/repositories/VaccineTypeRepository.h"

App::App() {

    this->repoFactory = std::make_shared<MemoryRepositoryFactory>();
    // Create the SNS user service using the repository provided by the factory.
    this->snsUserService = std::make_shared<SNSUserService>(repoFactory->getSNSUserRepository());
    vaccineTypeRepo = repoFactory->getVaccineTypeRepository();

    auto ctrRepo = repoFactory->getVaccinationCenterRepository();
    auto vtRepo  = repoFactory->getVaccineTypeRepository();

    vaccinationCenterService = std::make_shared<VaccinationCenterService>(
            repoFactory->getVaccinationCenterRepository(),
            vaccineTypeRepo);
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

std::shared_ptr<VaccinationCenterService> App::getVaccinationCenterService() {
    return vaccinationCenterService;
}

std::shared_ptr<RepositoryFactory> App::getRepositoryFactory() {
    return repoFactory;
}

std::shared_ptr<VaccineTypeRepository> App::getVaccineTypeRepository() {
    return vaccineTypeRepo;
}
