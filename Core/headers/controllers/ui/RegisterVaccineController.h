//
// Created by ChatGPT on 2025-11-15.
//

#ifndef LETI_ESOFT_25_26_B1_REGISTERVACCINECONTROLLER_H
#define LETI_ESOFT_25_26_B1_REGISTERVACCINECONTROLLER_H

#include "headers/domain/model/VaccineContainer.h"
#include "headers/domain/model/VaccineTypeContainer.h"

/**
 * Controller responsible for the vaccine registration use case (US11).
 *
 * The controller coordinates between the view (UI) and the domain model:
 *  - Builds a Vaccine instance with user-supplied data.
 *  - Validates it against the type container and business rules.
 *  - Persists it into the vaccine container on success.
 */
class RegisterVaccineController {
private:
    VaccineContainer& vaccineContainer;
    VaccineTypeContainer& vaccineTypeContainer;
    Vaccine currentVaccine;

public:
    RegisterVaccineController(VaccineContainer& vContainer,
                              VaccineTypeContainer& tContainer);

    /**
     * Step 1: Build a vaccine in memory (not persisted yet).
     */
    void createNewVaccine(const std::string& commercialName,
                          const std::string& brand,
                          const std::string& typeCode,
                          VaccineTechnology technology,
                          const std::string& lot = "",
                          std::optional<std::string> expirationDate = std::nullopt);

    /**
     * Step 2: Validate and save the vaccine previously built.
     */
    Result saveCreatedNewVaccine();
};

#endif //LETI_ESOFT_25_26_B1_REGISTERVACCINECONTROLLER_H