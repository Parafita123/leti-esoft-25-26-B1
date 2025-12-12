//
// Created by Filipe on 12/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_COMMUNITYMASSVACCINATIONCENTER_H
#define LETI_ESOFT_25_26_B1_COMMUNITYMASSVACCINATIONCENTER_H

#include <memory>
#include "headers/domain/model/Facility.h"
#include "headers/domain/model/VaccineType.h"

class CommunityMassVaccinationCenter : public Facility {
private:
    std::shared_ptr<VaccineType> vaccineType;

public:
    CommunityMassVaccinationCenter(std::string name,
                                      std::string postal_address,
                                      std::string phone_number,
                                      std::string email,
                                      std::string website_address,
                                      std::string opening_hours,
                                      std::string closing_hours,
                                      int max_vaccines_per_hour,
                                      std::shared_ptr<VaccineType> vaccineType);

    std::shared_ptr<VaccineType> getVaccineType() const;
};

#endif //LETI_ESOFT_25_26_B1_COMMUNITYMASSVACCINATIONCENTER_H
