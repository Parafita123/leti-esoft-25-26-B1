//
// Created by Filipe on 12/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_VACCINETYPEREPOSITORY_H
#define LETI_ESOFT_25_26_B1_VACCINETYPEREPOSITORY_H

#include <memory>
#include <vector>
#include <string>
#include "headers/domain/model/VaccineType.h"
#include "headers/domain/shared/Result.h"

class VaccineTypeRepository {
public:
    virtual ~VaccineTypeRepository() = default;

    virtual std::vector<std::shared_ptr<VaccineType>> findAll() = 0;
    virtual std::shared_ptr<VaccineType> findByCode(const std::string& code) = 0;
    virtual bool exists(const std::string& code) = 0;
    virtual Result save(std::shared_ptr<VaccineType> obj) = 0;
};


#endif //LETI_ESOFT_25_26_B1_VACCINETYPEREPOSITORY_H
