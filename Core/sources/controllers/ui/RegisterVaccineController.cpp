//
// Created by ChatGPT on 2025-11-15.
//

#include "../Core/headers/controllers/ui/RegisterVaccineController.h"

RegisterVaccineController::RegisterVaccineController(VaccineContainer& vContainer,
                                                     VaccineTypeContainer& tContainer)
        : vaccineContainer(vContainer), vaccineTypeContainer(tContainer) {}

void RegisterVaccineController::createNewVaccine(const std::string& commercialName,
                                                 const std::string& brand,
                                                 const std::string& typeCode,
                                                 VaccineTechnology technology,
                                                 const std::string& lot,
                                                 std::optional<std::string> expirationDate) {
    currentVaccine = vaccineContainer.create(commercialName, brand, typeCode, technology, lot, expirationDate);
}

Result RegisterVaccineController::saveCreatedNewVaccine() {
    return vaccineContainer.save(currentVaccine, vaccineTypeContainer);
}