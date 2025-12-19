//
// Created by Guta on 19/12/2025.
//

#include "headers/domain/model/CommunityMassVaccinationCenter.h"

CommunityMassVaccinationCenter::CommunityMassVaccinationCenter(
        std::string name,
        std::string postalAddress,
        std::string phoneNumber,
        std::string email,
        std::string websiteAddress,
        std::string openingHours,
        std::string closingHours,
        int maxVaccinesPerHour,
        std::shared_ptr<VaccineType> vaccineType)
        : Facility(std::move(name), std::move(postalAddress), std::move(phoneNumber),
                   std::move(email), std::move(websiteAddress), std::move(openingHours),
                   std::move(closingHours), maxVaccinesPerHour),
          vaccineType(std::move(vaccineType)) {}
