//
// Created by ChatGPT on 2025-11-15.
//

#ifndef LETI_ESOFT_25_26_B1_VACCINECONTAINER_H
#define LETI_ESOFT_25_26_B1_VACCINECONTAINER_H

#include <vector>
#include "headers/domain/model/Vaccine.h"
#include "headers/domain/model/VaccineTypeContainer.h"
#include "headers/domain/shared/Result.h"

/**
 * In-memory container for Vaccine objects.
 *
 * This class encapsulates the process of creating, validating and saving new vaccines.
 * A vaccine is only persisted to the container if validation passes successfully.
 */
class VaccineContainer {
private:
    std::vector<Vaccine> vaccines;

    // Helper to check if a type code exists in the provided VaccineTypeContainer
    bool existsTypeCode(const std::string& typeCode, const VaccineTypeContainer& typeContainer) const;

public:
    VaccineContainer() = default;

    /**
     * Creates a Vaccine object from the given parameters without persisting it.
     */
    Vaccine create(const std::string& commercialName,
                   const std::string& brand,
                   const std::string& typeCode,
                   VaccineTechnology technology,
                   const std::string& lot = "",
                   std::optional<std::string> expirationDate = std::nullopt) const;

    /**
     * Validates a Vaccine instance according to the business rules:
     *  - All mandatory fields must be present.
     *  - Technology must be allowed.
     *  - The referenced type code must exist in the VaccineTypeContainer.
     */
    Result validate(const Vaccine& vaccine,
                    const VaccineTypeContainer& typeContainer) const;

    /**
     * Validates and saves a vaccine to the container if valid.
     * Returns a Result indicating success or failure.
     */
    Result save(const Vaccine& vaccine,
                const VaccineTypeContainer& typeContainer);

    /**
     * Returns all persisted vaccines.
     */
    const std::vector<Vaccine>& getAll() const;
};

#endif //LETI_ESOFT_25_26_B1_VACCINECONTAINER_H