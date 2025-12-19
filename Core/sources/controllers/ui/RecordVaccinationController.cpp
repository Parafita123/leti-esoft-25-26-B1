//
// Created by Guta on 19/12/2025.
//

#include "headers/controllers/ui/RecordVaccinationController.h"

RecordVaccinationController::RecordVaccinationController(std::shared_ptr<VaccinationProcessService> service)
        : service(std::move(service)) {}

void RecordVaccinationController::removeFromWaitingRoom(const std::string &snsUserNumber) {
    if (service) {
        service->removeFromWaitingRoom(snsUserNumber);
    }
}

Result RecordVaccinationController::registerVaccination(const VaccinationProcessDTO &dto) {
    if (!service) {
        return Result::NOK(L"Vaccination service not configured.");
    }


    // Create domain object
    VaccinationProcess process = service->createVaccinationProcess(dto.snsUserNumber,
                                                                  dto.vaccineCode,
                                                                  dto.lotNumber);
    // Persist
    Result result = service->addOrUpdate(process);
    if (result.isOK()) {
        service->assignToRecoveryRoom(dto.snsUserNumber);
    }
    return result;
}
