//
// Created by Filipe on 12/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_VACCINATIONCENTERMEMORYREPOSITORY_H
#define LETI_ESOFT_25_26_B1_VACCINATIONCENTERMEMORYREPOSITORY_H

#pragma once
#include <vector>
#include <memory>
#include <optional>
#include "headers/domain/repositories/VaccinationCenterRepository.h"
#include "headers/domain/shared/Result.h"

class VaccinationCenterMemoryRepository : public VaccinationCenterRepository {
private:
    std::vector<std::shared_ptr<Facility>> data;

public:
    Result save(std::shared_ptr<Facility> obj) override;
    std::vector<std::shared_ptr<Facility>> findAll() override;
    std::optional<std::shared_ptr<Facility>> findById(int facilityId) override;
    bool isEmpty() const { return data.empty(); }
    size_t size() const { return data.size(); }
};

#endif //LETI_ESOFT_25_26_B1_VACCINATIONCENTERMEMORYREPOSITORY_H
