//
// Created by Filipe on 12/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_REGISTERVACCINATIONCENTERCONTROLLER_H
#define LETI_ESOFT_25_26_B1_REGISTERVACCINATIONCENTERCONTROLLER_H

#include <memory>
#include <vector>
#include "headers/controllers/dto/VaccinationCenterDTO.h"
#include "headers/domain/shared/Result.h"
#include "headers/domain/services/VaccinationCenterService.h"

class RegisterVaccinationCenterController {
private:
    std::shared_ptr<VaccinationCenterService> service;

public:
    explicit RegisterVaccinationCenterController(std::shared_ptr<VaccinationCenterService> svc);

    std::vector<std::shared_ptr<VaccineType>> listVaccineTypes();

    Result registerVaccinationCenter(const VaccinationCenterDTO& dto);
};

#endif //LETI_ESOFT_25_26_B1_REGISTERVACCINATIONCENTERCONTROLLER_H
