//
// Created by diogo on 16/11/2025.
//
#include "headers/domain/model/EmployeeContainer.h"

Employee EmployeeContainer::create(std::string name,
                                   std::string postalAddress,
                                   std::string phoneNumber,
                                   std::string email,
                                   std::string citizenCardNumber,
                                   std::string role)
{
    return Employee(name, postalAddress, phoneNumber, email, citizenCardNumber, role);
}

Result EmployeeContainer::save(const Employee& e) {

    if (!e.isValid())
        return Result::NOK(L"Invalid employee data");

    if (checkDuplicates(e))
        return Result::NOK(L"Duplicate employee (Citizen Card already exists)");

    employees.push_back(e);
    return Result::OK(L"Employee registered successfully");
}

bool EmployeeContainer::checkDuplicates(const Employee& e) const {
    for (const auto& emp : employees) {
        if (emp.getId() == e.getId()) {
            return true;
        }
    }
    return false;
}