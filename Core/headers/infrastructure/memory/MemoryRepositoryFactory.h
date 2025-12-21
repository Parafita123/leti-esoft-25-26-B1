

#ifndef LETI_ESOFT_25_26_B1_MEMORYREPOSITORYFACTORY_H
#define LETI_ESOFT_25_26_B1_MEMORYREPOSITORYFACTORY_H

#include <memory>
#include "headers/domain/repositories/RepositoryFactory.h"
#include "headers/domain/repositories/SNSUserRepository.h"
#include "VaccinationCenterMemoryRepository.h"
#include "VaccineTypeMemoryRepository.h"
#include "headers/domain/repositories/UserArrivalRepository.h"
#include "headers/domain/repositories/VaccinationAppointmentRepository.h"
// US41 repository forward declarations
#include "headers/domain/repositories/VaccinationProcessRepository.h"
#include "headers/domain/repositories/WaitingRoomRepository.h"
#include "headers/domain/repositories/RecoveryRoomRepository.h"
class MemoryRepositoryFactory : public RepositoryFactory {
private:

    std::shared_ptr<SNSUserRepository> snsRepo;
    std::shared_ptr<VaccinationCenterRepository> vcRepo;
    std::shared_ptr<VaccineTypeRepository> vtRepo;
    std::shared_ptr<UserArrivalRepository> arrivalRepo;
    std::shared_ptr<VaccinationAppointmentRepository> apptRepo;
    std::shared_ptr<VaccinationCenterRepository> centersRepo;
    std::shared_ptr<VaccinationAppointmentRepository> vaRepo;
    std::shared_ptr<UserArrivalRepository> uaRepo;


    std::shared_ptr<VaccinationProcessRepository> vpRepo;
    std::shared_ptr<WaitingRoomRepository> wrRepo;
    std::shared_ptr<RecoveryRoomRepository> rrRepo;

public:
    MemoryRepositoryFactory();
    virtual std::shared_ptr<SNSUserRepository> getSNSUserRepository() override;
    std::shared_ptr<VaccinationCenterRepository> getVaccinationCenterRepository() override;
    std::shared_ptr<VaccineTypeRepository> getVaccineTypeRepository() override;
    std::shared_ptr<VaccinationAppointmentRepository> getVaccinationAppointmentRepository() override;
    std::shared_ptr<UserArrivalRepository> getUserArrivalRepository() override;

    // US41 repositories
    std::shared_ptr<VaccinationProcessRepository> getVaccinationProcessRepository() override;
    std::shared_ptr<WaitingRoomRepository> getWaitingRoomRepository() override;
    std::shared_ptr<RecoveryRoomRepository> getRecoveryRoomRepository() override;
};

#endif // LETI_ESOFT_25_26_B1_MEMORYREPOSITORYFACTORY_H