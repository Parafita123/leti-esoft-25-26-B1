//
// Created by diogo on 16/11/2025.
//

#ifndef LETI_ESOFT_25_26_B1_EMPLOYEE_H
#define LETI_ESOFT_25_26_B1_EMPLOYEE_H


#include <string>

class Employee {
private:
    std::string name;
    std::string postalAddress;
    std::string phoneNumber;
    std::string email;
    std::string citizenCardNumber;
    std::string role;

public:
    Employee(std::string name,
             std::string postalAddress,
             std::string phoneNumber,
             std::string email,
             std::string citizenCardNumber,
             std::string role);

    bool isValid() const;

    std::string getId() const;
    std::string getName() const;
    std::string getPhone() const;
    std::string getEmail() const;
    std::string getCC() const;
    std::string getRole() const;
};


#endif //LETI_ESOFT_25_26_B1_EMPLOYEE_H
