

#ifndef LETI_ESOFT_25_26_B1_MEMORYREPOSITORYFACTORY_H
#define LETI_ESOFT_25_26_B1_MEMORYREPOSITORYFACTORY_H

#include <memory>
#include "headers/domain/repositories/RepositoryFactory.h"
#include "headers/domain/repositories/SNSUserRepository.h"
#include "VaccinationCenterMemoryRepository.h"
#include "VaccineTypeMemoryRepository.h"
#include "headers/domain/repositories/UserArrivalRepository.h"
#include "headers/domain/repositories/VaccinationAppointmentRepository.h"
class MemoryRepositoryFactory : public RepositoryFactory {
private:
    // A single instance of the SNS user repository stored as a member
    // so that repeated calls return the same object.  This mirrors the
    // behaviour seen in DemoTasks where repositories are reused.
    std::shared_ptr<SNSUserRepository> snsRepo;
    std::shared_ptr<VaccinationCenterRepository> vcRepo;
    std::shared_ptr<VaccineTypeRepository> vtRepo;
    std::shared_ptr<UserArrivalRepository> arrivalRepo;
    std::shared_ptr<VaccinationAppointmentRepository> apptRepo;
    std::shared_ptr<VaccinationCenterRepository> centersRepo;
    std::shared_ptr<VaccinationAppointmentRepository> vaRepo;
    std::shared_ptr<UserArrivalRepository> uaRepo;

public:
    MemoryRepositoryFactory();
    virtual std::shared_ptr<SNSUserRepository> getSNSUserRepository() override;
    std::shared_ptr<VaccinationCenterRepository> getVaccinationCenterRepository() override;
    std::shared_ptr<VaccineTypeRepository> getVaccineTypeRepository() override;
    std::shared_ptr<VaccinationAppointmentRepository> getVaccinationAppointmentRepository() override;
    std::shared_ptr<UserArrivalRepository> getUserArrivalRepository() override;
};

#endif // LETI_ESOFT_25_26_B1_MEMORYREPOSITORYFACTORY_H