//
// Created by Filipe on 12/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_VACCINATIONCENTERMEMORYREPOSITORY_H
#define LETI_ESOFT_25_26_B1_VACCINATIONCENTERMEMORYREPOSITORY_H

#include <vector>
#include <memory>
#include "headers/domain/repositories/VaccinationCenterRepository.h"

class VaccinationCenterMemoryRepository : public VaccinationCenterRepository {
private:
    std::vector<std::shared_ptr<Facility>> data;

public:
    Result save(std::shared_ptr<Facility> obj) override;
};

#endif //LETI_ESOFT_25_26_B1_VACCINATIONCENTERMEMORYREPOSITORY_H
