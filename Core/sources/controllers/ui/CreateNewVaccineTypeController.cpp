//
// Created by Filipe on 04/11/2025.
//
#include "../Core/headers/controllers/ui/CreateNewVaccineTypeController.h"

CreateNewVaccineTypeController::CreateNewVaccineTypeController(VaccineTypeContainer& container)
        : vaccineTypeContainer(container) {}

void CreateNewVaccineTypeController::createNewVaccineType(const std::string& type_code,
                                                          const std::string& disease,
                                                          const std::string& short_description) {
    currentVaccineType = vaccineTypeContainer.create(type_code, disease, short_description);
}

Result CreateNewVaccineTypeController::saveCreatedNewVaccineType() {
    return vaccineTypeContainer.save(currentVaccineType);
}

const VaccineType& CreateNewVaccineTypeController::getCurrentVaccineType() const {
    return currentVaccineType;
}

