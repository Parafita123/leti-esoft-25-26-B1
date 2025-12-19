//
// Created by Guta on 19/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_RECORDVACCINATIONVIEW_H
#define LETI_ESOFT_25_26_B1_RECORDVACCINATIONVIEW_H

#include <memory>
#include "headers/controllers/ui/RecordVaccinationController.h"

/**
 * View responsible for interacting with the nurse to record a
 * vaccination administration.  It collects the necessary data,
 * delegates business logic to the controller and displays the
 * outcome.
 */
class RecordVaccinationView {
private:
    RecordVaccinationController controller;

    /**
     * Helper to trim whitespace from a string (both ends).  Used to
     * sanitize user input.
     */
    static std::string trim(const std::string &s);

public:
    explicit RecordVaccinationView(RecordVaccinationController controller);

    /**
     * Executes the user interaction loop to record a vaccination.
     */
    void run();
};

#endif // LETI_ESOFT_25_26_B1_RECORDVACCINATIONVIEW_H
