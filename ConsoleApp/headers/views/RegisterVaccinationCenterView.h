//
// Created by Filipe on 12/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_REGISTERVACCINATIONCENTERVIEW_H
#define LETI_ESOFT_25_26_B1_REGISTERVACCINATIONCENTERVIEW_H

#include "headers/controllers/ui/RegisterVaccinationCenterController.h"

class RegisterVaccinationCenterView {
private:
    RegisterVaccinationCenterController controller;

public:
    explicit RegisterVaccinationCenterView(RegisterVaccinationCenterController controller);

    void show();
};

#endif //LETI_ESOFT_25_26_B1_REGISTERVACCINATIONCENTERVIEW_H
