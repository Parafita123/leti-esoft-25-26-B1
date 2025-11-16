//
// Created by diogo on 16/11/2025.
//

#ifndef LETI_ESOFT_25_26_B1_REGISTEREMPLOYEECONTROLLER_H
#define LETI_ESOFT_25_26_B1_REGISTEREMPLOYEECONTROLLER_H

#include <string>
#include "headers/domain/model/EmployeeContainer.h"
#include "headers/domain/shared/Result.h"

class RegisterEmployeeController {
private:
    EmployeeContainer* container;

public:
    RegisterEmployeeController(EmployeeContainer* container);

    Employee createEmployee(std::string name,
                            std::string postalAddress,
                            std::string phoneNumber,
                            std::string email,
                            std::string citizenCardNumber,
                            std::string role);

    Result saveRegisteredEmployee(const Employee& e);
};


#endif //LETI_ESOFT_25_26_B1_REGISTEREMPLOYEECONTROLLER_H
