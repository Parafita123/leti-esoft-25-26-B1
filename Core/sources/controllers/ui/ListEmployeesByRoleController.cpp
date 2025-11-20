//
// Created by bergu on 16/11/2025.
//
#include "headers/controllers/ui/ListEmployeesByRoleController.h"

ListEmployeesByRoleController::ListEmployeesByRoleController(App &app)
    : app(app) {}

std::vector<Employee> ListEmployeesByRoleController::requestEmployeesByRole(const std::string &role) {
    return app.getEmployeeContainer().getEmployeesByRole(role);
}