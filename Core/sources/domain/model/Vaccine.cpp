//
// Created by ChatGPT on 2025-11-15.
//

#include "headers/domain/model/Vaccine.h"
#include <stdexcept>

Vaccine::Vaccine(std::string commercialName,
                 std::string brand,
                 std::string typeCode,
                 VaccineTechnology technology,
                 std::string lot,
                 std::optional<std::string> expirationDate)
        : commercialName(std::move(commercialName)),
          brand(std::move(brand)),
          typeCode(std::move(typeCode)),
          technology(technology),
          lot(std::move(lot)),
          expirationDate(std::move(expirationDate))
{
    // Minimal in-constructor validation:
    if (this->commercialName.empty()) {
        throw std::invalid_argument("Vaccine: commercial name is required");
    }
    if (this->brand.empty()) {
        throw std::invalid_argument("Vaccine: brand is required");
    }
    if (this->typeCode.empty()) {
        throw std::invalid_argument("Vaccine: type code is required");
    }
    if (!VaccineTechnologyUtils::isAllowed(technology)) {
        throw std::invalid_argument("Vaccine: technology is not allowed");
    }
}

const std::string& Vaccine::getCommercialName() const {
    return commercialName;
}

const std::string& Vaccine::getBrand() const {
    return brand;
}

const std::string& Vaccine::getTypeCode() const {
    return typeCode;
}

VaccineTechnology Vaccine::getTechnology() const {
    return technology;
}

const std::string& Vaccine::getLot() const {
    return lot;
}

const std::optional<std::string>& Vaccine::getExpirationDate() const {
    return expirationDate;
}

std::string Vaccine::toString() const {
    return commercialName + " (" + brand + ", type=" + typeCode + ", " +
           VaccineTechnologyUtils::toString(technology) + ")";
}