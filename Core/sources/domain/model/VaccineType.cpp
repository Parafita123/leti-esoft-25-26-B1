//
// Created by Filipe on 04/11/2025.
//

#include "headers/domain/model/VaccineType.h"

VaccineType::VaccineType(std::string type_code, std::string disease, std::string short_description)
        : type_code(std::move(type_code)),
          disease(std::move(disease)),
          short_description(std::move(short_description)) {}

const std::string& VaccineType::getTypeCode() const {
    return type_code;
}

const std::string& VaccineType::getDisease() const {
    return disease;
}

const std::string& VaccineType::getShortDescription() const {
    return short_description;
}

std::string VaccineType::toString() const {
    return "Type: " + type_code + " | Disease: " + disease + " | Description: " + short_description;
}