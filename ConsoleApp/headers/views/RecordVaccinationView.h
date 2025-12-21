// created by Guta on 2025-12-20
//
// Console view that interacts with a nurse to record the administration
// of a vaccine.  It prompts for the necessary data, delegates the
// operation to the controller and displays the outcome.

#ifndef LETI_ESOFT_25_26_B1_RECORDVACCINATIONVIEW_H
#define LETI_ESOFT_25_26_B1_RECORDVACCINATIONVIEW_H

#include "headers/controllers/ui/RecordVaccinationController.h"
#include <string>

class RecordVaccinationView {
private:
    RecordVaccinationController controller;

    /**
     * Prompts the user for a non‑empty string with the given message.
     */
    static std::string prompt(const std::string &message);

public:
    explicit RecordVaccinationView(RecordVaccinationController controller);

    /**
     * Runs the view interaction loop.  Collects the SNS user number,
     * vaccine code and lot number, confirms with the user and then
     * delegates to the controller.  Displays a success or error message.
     */
    void run();
};

#endif // LETI_ESOFT_25_26_B1_RECORDVACCINATIONVIEW_H