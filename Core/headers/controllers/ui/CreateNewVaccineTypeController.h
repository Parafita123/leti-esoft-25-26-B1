//
// Created by Filipe on 04/11/2025.
//

#ifndef LETI_ESOFT_25_26_B1_CREATENEWVACCINETYPECONTROLLER_H
#define LETI_ESOFT_25_26_B1_CREATENEWVACCINETYPECONTROLLER_H

#include "headers/domain/model/VaccineType.h"
#include "headers/domain/model/VaccineTypeContainer.h"
#include "headers/domain/repositories/VaccineTypeRepository.h"

class CreateNewVaccineTypeController {
private:
    std::shared_ptr<VaccineTypeRepository> repo;
    std::shared_ptr<VaccineType> current;

public:
    CreateNewVaccineTypeController(std::shared_ptr<VaccineTypeRepository> repo);

    void createNewVaccineType(const std::string& type_code,
                              const std::string& disease,
                              const std::string& short_description);

    Result save();

    const VaccineType& getCurrentVaccineType() const;
};

#endif //LETI_ESOFT_25_26_B1_CREATENEWVACCINETYPECONTROLLER_H
