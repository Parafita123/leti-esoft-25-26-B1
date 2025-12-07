//
// Created by ChatGPT on 07/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_SNSUSER_H
#define LETI_ESOFT_25_26_B1_SNSUSER_H

#include <string>

/**
 * Represents a National Health Service (SNS) user registered in the system.
 *
 * Each SNS user is identified by a unique SNS user number and contains
 * personal details such as name, date of birth, sex (optional), postal
 * address, phone number, email and citizen card number.  The class
 * encapsulates only the data and provides simple validation on required
 * fields.  Format validation and uniqueness constraints are delegated to
 * the SNSUserContainer.
 */
class SNSUser {
private:
    std::string name;
    std::string dateOfBirth;
    std::string sex;
    std::string postalAddress;
    std::string phoneNumber;
    std::string email;
    std::string citizenCardNumber;
    std::string snsUserNumber;

public:
    SNSUser(std::string name,
            std::string dateOfBirth,
            std::string sex,
            std::string postalAddress,
            std::string phoneNumber,
            std::string email,
            std::string citizenCardNumber,
            std::string snsUserNumber);

    /**
     * Checks whether all mandatory fields are populated.  The sex
     * attribute is optional, so its absence does not invalidate the
     * user object at this level.  Additional format checks are
     * performed by the SNSUserContainer.
     */
    bool isValid() const;

    // Accessors
    const std::string &getName() const;
    const std::string &getDateOfBirth() const;
    const std::string &getSex() const;
    const std::string &getPostalAddress() const;
    const std::string &getPhoneNumber() const;
    const std::string &getEmail() const;
    const std::string &getCitizenCardNumber() const;
    const std::string &getSNSUserNumber() const;
};

#endif // LETI_ESOFT_25_26_B1_SNSUSER_H