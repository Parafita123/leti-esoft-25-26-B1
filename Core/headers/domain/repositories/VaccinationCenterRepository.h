//
// Created by Filipe on 12/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_VACCINATIONCENTERREPOSITORY_H
#define LETI_ESOFT_25_26_B1_VACCINATIONCENTERREPOSITORY_H

#include <memory>
#include "headers/domain/model/Facility.h"
#include "headers/domain/shared/Result.h"
#include <vector>
#include <optional>

class VaccinationCenterRepository {
public:
    virtual ~VaccinationCenterRepository() = default;
    virtual Result save(std::shared_ptr<Facility> obj) = 0;
    // US22: list facilities
    virtual std::vector<std::shared_ptr<Facility>> findAll() = 0;

    // US22: retrieve selected facility by id
    virtual std::optional<std::shared_ptr<Facility>> findById(int facilityID) = 0;
};

#endif //LETI_ESOFT_25_26_B1_VACCINATIONCENTERREPOSITORY_H
