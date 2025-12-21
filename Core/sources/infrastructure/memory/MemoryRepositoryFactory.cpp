

#include "headers/infrastructure/memory/MemoryRepositoryFactory.h"
#include "headers/infrastructure/memory/SNSUserMemoryRepository.h"
#include "headers/infrastructure/memory/UserArrivalMemoryRepository.h"
#include "headers/infrastructure/memory/VaccinationAppointmentMemoryRepository.h"
#include "headers/infrastructure/memory/VaccinationCenterMemoryRepository.h"
// US41 memory repositories
#include "headers/infrastructure/memory/VaccinationProcessMemoryRepository.h"
#include "headers/infrastructure/memory/WaitingRoomMemoryRepository.h"
#include "headers/infrastructure/memory/RecoveryRoomMemoryRepository.h"

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

std::shared_ptr<VaccinationProcessRepository> MemoryRepositoryFactory::getVaccinationProcessRepository() {
    if (!vpRepo) {
        vpRepo = std::make_shared<VaccinationProcessMemoryRepository>();
    }
    return vpRepo;
}

std::shared_ptr<WaitingRoomRepository> MemoryRepositoryFactory::getWaitingRoomRepository() {
    if (!wrRepo) {
        wrRepo = std::make_shared<WaitingRoomMemoryRepository>();
    }
    return wrRepo;
}

std::shared_ptr<RecoveryRoomRepository> MemoryRepositoryFactory::getRecoveryRoomRepository() {
    if (!rrRepo) {
        rrRepo = std::make_shared<RecoveryRoomMemoryRepository>();
    }
    return rrRepo;
}