//
// MemoryRepositoryFactory.cpp
//
// Implements the MemoryRepositoryFactory which returns in‑memory
// repository instances.  The SNSUserMemoryRepository is created on
// first use and cached for subsequent calls.
//

#include "headers/infrastructure/memory/MemoryRepositoryFactory.h"
#include "headers/infrastructure/memory/SNSUserMemoryRepository.h"

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
