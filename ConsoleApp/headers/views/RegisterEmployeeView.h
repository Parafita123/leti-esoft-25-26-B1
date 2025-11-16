//
// Created by diogo on 16/11/2025.
//

#ifndef LETI_ESOFT_25_26_B1_REGISTEREMPLOYEEVIEW_H
#define LETI_ESOFT_25_26_B1_REGISTEREMPLOYEEVIEW_H

#include "headers/controllers/ui/RegisterEmployeeController.h"

class RegisterEmployeeView {
private:
    RegisterEmployeeController controller;

public:
    RegisterEmployeeView(RegisterEmployeeController controller);
    void run();
};

#endif //LETI_ESOFT_25_26_B1_REGISTEREMPLOYEEVIEW_H
