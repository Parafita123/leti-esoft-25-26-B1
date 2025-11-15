//
// Created by ChatGPT on 2025-11-15.
//

#ifndef LETI_ESOFT_25_26_B1_REGISTERVACCINEVIEW_H
#define LETI_ESOFT_25_26_B1_REGISTERVACCINEVIEW_H

#include "../Core/headers/controllers/ui/RegisterVaccineController.h"

/**
 * Console view for registering a new vaccine (US11).
 *
 * This view prompts the user for the required information, delegates to
 * the controller to build and save the vaccine, and displays the outcome.
 */
class RegisterVaccineView {
private:
    RegisterVaccineController controller;

    /**
     * Helper to display the list of allowed technologies and ask the user to pick one.
     */
    VaccineTechnology askTechnology() const;

public:
    explicit RegisterVaccineView(RegisterVaccineController controller);

    /**
     * Entry point for the view. Handles the entire workflow.
     */
    void show();
};

#endif //LETI_ESOFT_25_26_B1_REGISTERVACCINEVIEW_H