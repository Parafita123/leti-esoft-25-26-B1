//
// Created by Filipe on 04/11/2025.
//

#ifndef LETI_ESOFT_25_26_B1_APP_H
#define LETI_ESOFT_25_26_B1_APP_H

#include "headers/domain/model/VaccineTypeContainer.h"
#include "headers/domain/model/VaccineContainer.h"

class App {
private:
    VaccineTypeContainer vaccineTypeContainer;
    VaccineContainer vaccineContainer;

public:
    App() = default;

    VaccineTypeContainer& getVaccineTypeContainer();

    /**
     * Returns a reference to the vaccine container.
     */
    VaccineContainer& getVaccineContainer();
};

#endif //LETI_ESOFT_25_26_B1_APP_H
