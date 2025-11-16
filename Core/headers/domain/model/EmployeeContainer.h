//
// Created by diogo on 16/11/2025.
//

#ifndef LETI_ESOFT_25_26_B1_EMPLOYEECONTAINER_H
#define LETI_ESOFT_25_26_B1_EMPLOYEECONTAINER_H

#include <vector>
#include "Employee.h"
#include "../shared/Result.h"

class EmployeeContainer {
private:
    std::vector<Employee> employees;

public:
    Employee create(std::string name,
                    std::string postalAddress,
                    std::string phoneNumber,
                    std::string email,
                    std::string citizenCardNumber,
                    std::string role);

    Result save(const Employee& e);

    bool checkDuplicates(const Employee& e) const;
};


#endif //LETI_ESOFT_25_26_B1_EMPLOYEECONTAINER_H
