//
// Created by Filipe on 04/11/2025.
//

#ifndef LETI_ESOFT_25_26_B1_APP_H
#define LETI_ESOFT_25_26_B1_APP_H

#include "headers/domain/model/VaccineTypeContainer.h"

class App {
private:
    VaccineTypeContainer vaccineTypeContainer;

public:
    App() = default;

    VaccineTypeContainer& getVaccineTypeContainer();
};

#endif //LETI_ESOFT_25_26_B1_APP_H
