//
// Created by diogo on 02/01/2026.
//

#ifndef LETI_ESOFT_25_26_B1_LISTVACCINESVIEW_H
#define LETI_ESOFT_25_26_B1_LISTVACCINESVIEW_H



#include <vector>
#include "headers/domain/DTO/domain/VaccineDTO.h"

class ListVaccinesView {
public:
    void show(const std::vector<VaccineDTO>& vaccines) const;
};


#endif //LETI_ESOFT_25_26_B1_LISTVACCINESVIEW_H
