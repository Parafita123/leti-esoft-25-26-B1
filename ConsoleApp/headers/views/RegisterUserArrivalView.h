//
// Created by Filipe on 20/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_REGISTERUSERARRIVALVIEW_H
#define LETI_ESOFT_25_26_B1_REGISTERUSERARRIVALVIEW_H

#include "headers/controllers/ui/RegisterUserArrivalController.h"

class RegisterUserArrivalView {
private:
    RegisterUserArrivalController& controller;

    static bool askYesNo(const std::string& prompt);
    static void printNowTimestamp();

public:
    explicit RegisterUserArrivalView(RegisterUserArrivalController& controller);

    void show();
};

#endif //LETI_ESOFT_25_26_B1_REGISTERUSERARRIVALVIEW_H
