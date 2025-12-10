//
// SNSUserService.cpp
//
// Implements the service responsible for creating and registering SNS
// users.  Validation logic is centralized here to ensure that
// business rules (mandatory fields, format compliance and uniqueness)
// are enforced before persisting data.  Persistence is delegated to
// an injected repository instance.
//

#include "headers/domain/services/SNSUserService.h"

using std::string;
using std::shared_ptr;
using std::list;
using std::optional;

SNSUserService::SNSUserService(shared_ptr<SNSUserRepository> repo) : repo(std::move(repo)) {}

shared_ptr<SNSUser> SNSUserService::create(const string &name,
                                           const string &dateOfBirth,
                                           const string &sex,
                                           const string &postalAddress,
                                           const string &phoneNumber,
                                           const string &email,
                                           const string &citizenCardNumber,
                                           const string &snsUserNumber) {
    return std::make_shared<SNSUser>(name, dateOfBirth, sex, postalAddress, phoneNumber, email, citizenCardNumber, snsUserNumber);
}

bool SNSUserService::isValidPhoneNumber(const string &phone) {
    // Portuguese phone numbers consist of exactly nine digits【988867083390475†L40-L43】.
    static const std::regex pattern("^\\d{9}$");
    return std::regex_match(phone, pattern);
}

bool SNSUserService::isValidCitizenCardNumber(const string &cc) {
    // Pattern: 8 digits, optional space or hyphen, 1 digit, optional space, 2 letters, 1 digit【432736622680631†L580-L596】.
    static const std::regex pattern("^[0-9]{8}([ -]?[0-9])([ -]?[A-Za-z]{2}[0-9])$");
    return std::regex_match(cc, pattern);
}

bool SNSUserService::isValidSNSUserNumber(const string &sns) {
    // SNS user number consists of nine digits【988867083390475†L40-L43】.
    static const std::regex pattern("^\\d{9}$");
    return std::regex_match(sns, pattern);
}

bool SNSUserService::isValidEmail(const string &email) {
    // Simple email validation: one '@' and at least one '.' after it.
    static const std::regex pattern("^[^@\n]+@[^@\n]+\\.[^@\n]+$");
    return std::regex_match(email, pattern);
}

Result SNSUserService::add(shared_ptr<SNSUser> user) {
    if (!user) {
        return Result::NOK(L"No SNS user provided");
    }
    // Check mandatory fields; sex is optional.
    if (!user->isValid()) {
        return Result::NOK(L"Invalid SNS user data (mandatory fields missing)");
    }
    // Validate phone format
    if (!isValidPhoneNumber(user->getPhoneNumber())) {
        return Result::NOK(L"Invalid phone number format (must be 9 digits)");
    }
    // Validate citizen card number
    if (!isValidCitizenCardNumber(user->getCitizenCardNumber())) {
        return Result::NOK(L"Invalid citizen card number format");
    }
    // Validate SNS user number
    if (!isValidSNSUserNumber(user->getSNSUserNumber())) {
        return Result::NOK(L"Invalid SNS user number format (must be 9 digits)");
    }
    // Validate e‑mail format
    if (!isValidEmail(user->getEmail())) {
        return Result::NOK(L"Invalid email address");
    }
    // Enforce uniqueness across phone, email, citizen card and SNS user number
    if (repo->getByPhoneNumber(user->getPhoneNumber()).has_value()) {
        return Result::NOK(L"Duplicate phone number already registered");
    }
    if (repo->getByEmail(user->getEmail()).has_value()) {
        return Result::NOK(L"Duplicate email address already registered");
    }
    if (repo->getByCitizenCardNumber(user->getCitizenCardNumber()).has_value()) {
        return Result::NOK(L"Duplicate citizen card number already registered");
    }
    if (repo->getBySNSUserNumber(user->getSNSUserNumber()).has_value()) {
        return Result::NOK(L"Duplicate SNS user number already registered");
    }
    // Persist the user
    return repo->save(user);
}

list<shared_ptr<SNSUser>> SNSUserService::getAll() {
    return repo->getAll();
}