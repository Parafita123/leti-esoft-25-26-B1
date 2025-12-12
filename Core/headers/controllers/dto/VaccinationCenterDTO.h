//
// Created by Filipe on 12/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_VACCINATIONCENTERDTO_H
#define LETI_ESOFT_25_26_B1_VACCINATIONCENTERDTO_H

#include <string>
#include "headers/domain/model/FacilityType.h"

struct VaccinationCenterDTO {
    std::string name;
    std::string postal_address;
    std::string phone_number;
    std::string email;
    std::string website_address;
    std::string opening_hours;
    std::string closing_hours;
    int max_vaccines_per_hour = 0;

    FacilityType facilityType = FacilityType::HEALTHCARE;

    // only for COMMUNITY
    std::string vaccineTypeCode;
};

#endif //LETI_ESOFT_25_26_B1_VACCINATIONCENTERDTO_H
