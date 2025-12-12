//
// Created by Filipe on 12/12/2025.
//
#include "headers/domain/model/CommunityMassVaccinationCenter.h"

CommunityMassVaccinationCenter::CommunityMassVaccinationCenter(
        std::string name,
        std::string postal_address,
        std::string phone_number,
        std::string email,
        std::string website_address,
        std::string opening_hours,
        std::string closing_hours,
        int max_vaccines_per_hour,
        std::shared_ptr<VaccineType> vaccineType
) : Facility(std::move(name), std::move(postal_address), std::move(phone_number), std::move(email),
             std::move(website_address), std::move(opening_hours), std::move(closing_hours),
             max_vaccines_per_hour),
    vaccineType(std::move(vaccineType)) {}

std::shared_ptr<VaccineType> CommunityMassVaccinationCenter::getVaccineType() const {
    return vaccineType;
}
