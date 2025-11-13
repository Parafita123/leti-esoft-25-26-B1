//
// Created by Filipe on 04/11/2025.
//

#ifndef LETI_ESOFT_25_26_B1_CREATENEWVACCINETYPEVIEW_H
#define LETI_ESOFT_25_26_B1_CREATENEWVACCINETYPEVIEW_H

#include <string>
#include "../Core/headers/controllers/ui/CreateNewVaccineTypeController.h"

class CreateNewVaccineTypeView {
private:
    CreateNewVaccineTypeController controller;

public:
    CreateNewVaccineTypeView(CreateNewVaccineTypeController controller);

    void show();  // ponto de entrada principal
};

#endif //LETI_ESOFT_25_26_B1_CREATENEWVACCINETYPEVIEW_H
