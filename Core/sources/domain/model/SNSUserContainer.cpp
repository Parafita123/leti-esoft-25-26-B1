//
// Created by ChatGPT on 07/12/2025.
//

#include "headers/domain/model/SNSUserContainer.h"

#include <regex>

using std::string;

SNSUser SNSUserContainer::create(const string &name,
                                 const string &dateOfBirth,
                                 const string &sex,
                                 const string &postalAddress,
                                 const string &phoneNumber,
                                 const string &email,
                                 const string &citizenCardNumber,
                                 const string &snsUserNumber) {
    return SNSUser(name, dateOfBirth, sex, postalAddress, phoneNumber, email, citizenCardNumber, snsUserNumber);
}

bool SNSUserContainer::isValidPhoneNumber(const string &phone) {
    // Portuguese telephone numbers contain exactly 9 digits【988867083390475†L40-L43】.
    static const std::regex pattern("^\\d{9}$");
    return std::regex_match(phone, pattern);
}

bool SNSUserContainer::isValidCitizenCardNumber(const string &cc) {
    // Pattern: 8 digits, optional separator, 1 digit, optional separator, 2 letters, 1 digit【432736622680631†L580-L596】.
    static const std::regex pattern("^[0-9]{8}([ -]?[0-9])([ -]?[A-Za-z]{2}[0-9])$");
    return std::regex_match(cc, pattern);
}

bool SNSUserContainer::isValidSNSUserNumber(const string &sns) {
    // SNS user number consists of 9 digits【988867083390475†L40-L43】.
    static const std::regex pattern("^\\d{9}$");
    return std::regex_match(sns, pattern);
}

bool SNSUserContainer::isValidEmail(const string &email) {
    // A simple email pattern: one '@' and at least one '.' after '@'.
    static const std::regex pattern("^[^@\n]+@[^@\n]+\\.[^@\n]+$");
    return std::regex_match(email, pattern);
}

bool SNSUserContainer::hasDuplicate(const SNSUser &user) const {
    for (const auto &u : users) {
        if (u.getPhoneNumber() == user.getPhoneNumber() ||
            u.getEmail() == user.getEmail() ||
            u.getCitizenCardNumber() == user.getCitizenCardNumber() ||
            u.getSNSUserNumber() == user.getSNSUserNumber()) {
            return true;
        }
    }
    return false;
}

Result SNSUserContainer::validate(const SNSUser &user) const {
    // Mandatory field check (sex is optional)
    if (!user.isValid()) {
        return Result::NOK(L"Invalid SNS user data (mandatory fields missing)");
    }

    // Check phone format
    if (!isValidPhoneNumber(user.getPhoneNumber())) {
        return Result::NOK(L"Invalid phone number format (must be 9 digits)");
    }

    // Check citizen card number format
    if (!isValidCitizenCardNumber(user.getCitizenCardNumber())) {
        return Result::NOK(L"Invalid citizen card number format");
    }

    // Check SNS user number format
    if (!isValidSNSUserNumber(user.getSNSUserNumber())) {
        return Result::NOK(L"Invalid SNS user number format (must be 9 digits)");
    }

    // Check email format
    if (!isValidEmail(user.getEmail())) {
        return Result::NOK(L"Invalid email address");
    }

    // Check duplicates
    if (hasDuplicate(user)) {
        return Result::NOK(L"Duplicate SNS user (phone, email, citizen card or SNS number already registered)");
    }

    return Result::OK(L"SNS user validation successful");
}

Result SNSUserContainer::save(const SNSUser &user) {
    Result validation = validate(user);
    if (validation.isNOK()) {
        return validation;
    }
    users.push_back(user);
    return Result::OK(L"SNS user registered successfully");
}

const std::vector<SNSUser> &SNSUserContainer::getAll() const {
    return users;
}
