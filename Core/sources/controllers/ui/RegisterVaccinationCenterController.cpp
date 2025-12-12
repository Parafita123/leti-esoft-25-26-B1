//
// Created by Filipe on 12/12/2025.
//

#include "headers/controllers/ui/RegisterVaccinationCenterController.h"

RegisterVaccinationCenterController::RegisterVaccinationCenterController(std::shared_ptr<VaccinationCenterService> svc)
        : service(std::move(svc)) {}

std::vector<std::shared_ptr<VaccineType>> RegisterVaccinationCenterController::listVaccineTypes() {
    return service->listVaccineTypes();
}

Result RegisterVaccinationCenterController::registerVaccinationCenter(const VaccinationCenterDTO& dto) {
    return service->registerCenter(dto);
}