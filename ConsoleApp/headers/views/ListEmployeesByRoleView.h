//
// Created by bergu on 16/11/2025.
//

#ifndef LISTEMPLOYEESBYROLEVIEW_H
#define LISTEMPLOYEESBYROLEVIEW_H

#include <iostream>
#include "../Core/headers/controllers/ui/ListEmployeesByRoleController.h"

class ListEmployeesByRoleView {
private:
    ListEmployeesByRoleController &controller;

public:
    explicit ListEmployeesByRoleView(ListEmployeesByRoleController &controller);
    void listEmployeesByRole();
};

#endif //LISTEMPLOYEESBYROLEVIEW_H
