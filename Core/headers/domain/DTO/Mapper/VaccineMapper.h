//
// Created by diogo on 01/01/2026.
//

#ifndef LETI_ESOFT_25_26_B1_VACCINEMAPPER_H
#define LETI_ESOFT_25_26_B1_VACCINEMAPPER_H

#include "headers/domain/model/Vaccine.h"
#include "headers/domain/DTO/Domain/VaccineDTO.h"

class VaccineMapper {
public:
    static VaccineDTO toDTO(const Vaccine& vaccine);
};



#endif //LETI_ESOFT_25_26_B1_VACCINEMAPPER_H
