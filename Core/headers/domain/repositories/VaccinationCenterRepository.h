//
// Created by Filipe on 12/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_VACCINATIONCENTERREPOSITORY_H
#define LETI_ESOFT_25_26_B1_VACCINATIONCENTERREPOSITORY_H

#include <memory>
#include "headers/domain/model/Facility.h"
#include "headers/domain/shared/Result.h"

class VaccinationCenterRepository {
public:
    virtual ~VaccinationCenterRepository() = default;
    virtual Result save(std::shared_ptr<Facility> obj) = 0;
};

#endif //LETI_ESOFT_25_26_B1_VACCINATIONCENTERREPOSITORY_H
