//
// Created by diogo on 01/01/2026.
//

#ifndef LETI_ESOFT_25_26_B1_LISTVACCINESCONTROLLER_H
#define LETI_ESOFT_25_26_B1_LISTVACCINESCONTROLLER_H

#include "headers/domain/services/VaccineService.h"
#include "headers/domain/DTO/Domain/VaccineDTO.h"
#include <vector>

class ListVaccinesController {
private:
    VaccineService service;

public:
    explicit ListVaccinesController(const VaccineContainer& repo);

    std::vector<VaccineDTO> listAllVaccines();
};


#endif //LETI_ESOFT_25_26_B1_LISTVACCINESCONTROLLER_H
