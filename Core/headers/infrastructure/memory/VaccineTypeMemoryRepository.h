//
// Created by Filipe on 12/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_VACCINETYPEMEMORYREPOSITORY_H
#define LETI_ESOFT_25_26_B1_VACCINETYPEMEMORYREPOSITORY_H

#include <vector>
#include <memory>
#include <string>
#include "headers/domain/repositories/VaccineTypeRepository.h"
#include "headers/domain/shared/Result.h"

class VaccineTypeMemoryRepository : public VaccineTypeRepository {
private:
    std::vector<std::shared_ptr<VaccineType>> data;

public:
    std::vector<std::shared_ptr<VaccineType>> findAll() override;
    std::shared_ptr<VaccineType> findByCode(const std::string& code) override;
    bool exists(const std::string& code) override;
    Result save(std::shared_ptr<VaccineType> obj);
};

#endif //LETI_ESOFT_25_26_B1_VACCINETYPEMEMORYREPOSITORY_H
