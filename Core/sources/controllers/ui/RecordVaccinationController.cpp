// created by Guta on 2025-12-20
//
// Implementation of the RecordVaccinationController.

#include "headers/controllers/ui/RecordVaccinationController.h"

RecordVaccinationController::RecordVaccinationController(std::shared_ptr<VaccinationProcessService> service)
        : service(std::move(service)) {}

Result RecordVaccinationController::recordVaccination(const VaccinationProcessDTO &dto) {
    return service->recordVaccination(dto);
}