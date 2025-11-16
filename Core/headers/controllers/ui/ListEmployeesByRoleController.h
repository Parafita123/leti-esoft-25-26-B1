//
// Created by bergu on 16/11/2025.
//

#ifndef LISTEMPLOYEESBYROLECONTROLLER_H
#define LISTEMPLOYEESBYROLECONTROLLER_H

#include <vector>
#include <string>
#include "App.h"
#include "headers/domain/model/Employee.h"

class ListEmployeesByRoleController {
private:
    App &app;

public:
    explicit ListEmployeesByRoleController(App &app);
    std::vector<Employee> requestEmployeesByRole(const std::string &role);
};



#endif //LISTEMPLOYEESBYROLECONTROLLER_H
