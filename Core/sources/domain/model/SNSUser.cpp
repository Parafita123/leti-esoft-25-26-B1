//
// Created by Guta on 07/12/2025.
//

#include "headers/domain/model/SNSUser.h"

SNSUser::SNSUser(std::string name,
                 std::string dateOfBirth,
                 std::string sex,
                 std::string postalAddress,
                 std::string phoneNumber,
                 std::string email,
                 std::string citizenCardNumber,
                 std::string snsUserNumber)
        : name(std::move(name)),
          dateOfBirth(std::move(dateOfBirth)),
          sex(std::move(sex)),
          postalAddress(std::move(postalAddress)),
          phoneNumber(std::move(phoneNumber)),
          email(std::move(email)),
          citizenCardNumber(std::move(citizenCardNumber)),
          snsUserNumber(std::move(snsUserNumber)) {}

bool SNSUser::isValid() const {
    // Sex is optional; all other attributes must be non-empty
    return !name.empty() &&
           !dateOfBirth.empty() &&
           !postalAddress.empty() &&
           !phoneNumber.empty() &&
           !email.empty() &&
           !citizenCardNumber.empty() &&
           !snsUserNumber.empty();
}

const std::string &SNSUser::getName() const { return name; }

const std::string &SNSUser::getDateOfBirth() const { return dateOfBirth; }

const std::string &SNSUser::getSex() const { return sex; }

const std::string &SNSUser::getPostalAddress() const { return postalAddress; }

const std::string &SNSUser::getPhoneNumber() const { return phoneNumber; }

const std::string &SNSUser::getEmail() const { return email; }

const std::string &SNSUser::getCitizenCardNumber() const { return citizenCardNumber; }

const std::string &SNSUser::getSNSUserNumber() const { return snsUserNumber; }
