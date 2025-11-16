//
// Created by bergu on 16/11/2025.
//
#include "../ConsoleApp/headers/views/ListEmployeesByRoleView.h"

ListEmployeesByRoleView::ListEmployeesByRoleView(ListEmployeesByRoleController &controller)
        : controller(controller) {}

void ListEmployeesByRoleView::listEmployeesByRole() {
    std::cout << "Available roles: Nurse, Receptionist, Administrator\n";
    std::cout << "Enter role to search: ";
    std::string role;
    std::getline(std::cin, role);

    auto employees = controller.requestEmployeesByRole(role);

    if (employees.empty()) {
        std::cout << "No employees found with role: " << role << "\n";
    } else {
        std::cout << "\nEmployees with role '" << role << "':\n";
        for (const auto &e : employees) {
            std::cout << "\nName: " << e.getName()
                      << "\nPhone: " << e.getPhone()
                      << "\nCC: " << e.getCC()
                      << "\nEmail: " << e.getEmail()
                      << "\n---------------------------------\n";
        }
    }
}

