//
// Created by Filipe on 04/11/2025.
//

#ifndef LETI_ESOFT_25_26_B1_CREATENEWVACCINETYPECONTROLLER_H
#define LETI_ESOFT_25_26_B1_CREATENEWVACCINETYPECONTROLLER_H

#include "headers/domain/model/VaccineType.h"
#include "headers/domain/model/VaccineTypeContainer.h"

class CreateNewVaccineTypeController {
private:
    VaccineTypeContainer& vaccineTypeContainer;
    VaccineType currentVaccineType;

public:
    explicit CreateNewVaccineTypeController(VaccineTypeContainer& container);

    void createNewVaccineType(const std::string& type_code,
                              const std::string& disease,
                              const std::string& short_description);

    Result saveCreatedNewVaccineType();
};

#endif //LETI_ESOFT_25_26_B1_CREATENEWVACCINETYPECONTROLLER_H
