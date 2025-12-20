

#include "headers/infrastructure/memory/MemoryRepositoryFactory.h"
#include "headers/infrastructure/memory/SNSUserMemoryRepository.h"
#include "headers/infrastructure/memory/UserArrivalMemoryRepository.h"
#include "headers/infrastructure/memory/VaccinationAppointmentMemoryRepository.h"
#include "headers/infrastructure/memory/VaccinationCenterMemoryRepository.h"

MemoryRepositoryFactory::MemoryRepositoryFactory() {
    vcRepo = std::make_shared<VaccinationCenterMemoryRepository>();
    vtRepo = std::make_shared<VaccineTypeMemoryRepository>();
}

std::shared_ptr<SNSUserRepository> MemoryRepositoryFactory::getSNSUserRepository() {
    if (!this->snsRepo) {
        this->snsRepo = std::make_shared<SNSUserMemoryRepository>();
    }
    return this->snsRepo;
}

std::shared_ptr<VaccinationCenterRepository> MemoryRepositoryFactory::getVaccinationCenterRepository() {
    return vcRepo;
}

std::shared_ptr<VaccineTypeRepository> MemoryRepositoryFactory::getVaccineTypeRepository() {
    return vtRepo;
}


std::shared_ptr<UserArrivalRepository> MemoryRepositoryFactory::getUserArrivalRepository() {
    if (!uaRepo) uaRepo = std::make_shared<UserArrivalMemoryRepository>();
    return uaRepo;
}

std::shared_ptr<VaccinationAppointmentRepository> MemoryRepositoryFactory::getVaccinationAppointmentRepository() {
    if (!vaRepo) vaRepo = std::make_shared<VaccinationAppointmentMemoryRepository>();
    return vaRepo;
}