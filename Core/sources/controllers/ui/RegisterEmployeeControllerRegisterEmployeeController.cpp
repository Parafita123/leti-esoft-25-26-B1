//
// Created by diogo on 16/11/2025.
//
#include "headers/controllers/ui/RegisterEmployeeController.h"

RegisterEmployeeController::RegisterEmployeeController(EmployeeContainer* container)
        : container(container) {}

Employee RegisterEmployeeController::createEmployee(std::string name,
                                                    std::string postalAddress,
                                                    std::string phoneNumber,
                                                    std::string email,
                                                    std::string citizenCardNumber,
                                                    std::string role)
{
    return container->create(name, postalAddress, phoneNumber, email, citizenCardNumber, role);
}

Result RegisterEmployeeController::saveRegisteredEmployee(const Employee& e)
{
    return container->save(e);
}