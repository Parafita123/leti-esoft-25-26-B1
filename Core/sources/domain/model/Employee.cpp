//
// Created by diogo on 16/11/2025.
//
#include "headers/domain/model/Employee.h"

Employee::Employee(std::string name,
                   std::string postalAddress,
                   std::string phoneNumber,
                   std::string email,
                   std::string citizenCardNumber,
                   std::string role)
        : name(name),
          postalAddress(postalAddress),
          phoneNumber(phoneNumber),
          email(email),
          citizenCardNumber(citizenCardNumber),
          role(role) {}

bool Employee::isValid() const {
    return !name.empty() &&
           !postalAddress.empty() &&
           !phoneNumber.empty() &&
           !email.empty() &&
           !citizenCardNumber.empty() &&
           !role.empty();
}

std::string Employee::getId() const { return citizenCardNumber; }
std::string Employee::getName() const { return name; }
std::string Employee::getPhone() const { return phoneNumber; }
std::string Employee::getEmail() const { return email; }
std::string Employee::getCC() const { return citizenCardNumber; }
std::string Employee::getRole() const { return role; }
