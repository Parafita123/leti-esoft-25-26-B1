//
// Created by Guta on 2025-11-15.
//

#ifndef LETI_ESOFT_25_26_B1_VACCINE_H
#define LETI_ESOFT_25_26_B1_VACCINE_H

#include <string>
#include <optional>
#include "headers/domain/model/VaccineTechnology.h"

/**
 * Represents a vaccine available in the system.
 *
 * Each vaccine is identified by its commercial name, brand and the
 * type code (linking it to a VaccineType).  The vaccine technology must
 * belong to the predefined list of allowed technologies (AC11-1).
 *
 * Optional attributes such as lot number and expiration date can be stored,
 * but their validation is not in scope for this sprint.
 */
class Vaccine {
private:
    std::string commercialName;
    std::string brand;
    std::string typeCode;
    VaccineTechnology technology;
    std::string lot;
    std::optional<std::string> expirationDate;

public:
    Vaccine() = default;

    Vaccine(std::string commercialName,
            std::string brand,
            std::string typeCode,
            VaccineTechnology technology,
            std::string lot = "",
            std::optional<std::string> expirationDate = std::nullopt);

    const std::string& getCommercialName() const;
    const std::string& getBrand() const;
    const std::string& getTypeCode() const;
    VaccineTechnology getTechnology() const;
    const std::string& getLot() const;
    const std::optional<std::string>& getExpirationDate() const;

    // Utility for printing
    std::string toString() const;
};

#endif //LETI_ESOFT_25_26_B1_VACCINE_H