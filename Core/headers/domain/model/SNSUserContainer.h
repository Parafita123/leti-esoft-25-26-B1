//
// Created by Guta on 07/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_SNSUSERCONTAINER_H
#define LETI_ESOFT_25_26_B1_SNSUSERCONTAINER_H

#include <vector>
#include <string>
#include "SNSUser.h"
#include "headers/domain/shared/Result.h"

/**
 * Container responsible for creating, validating and storing SNSUser
 * entities.  Besides instantiation, it performs format validation for
 * phone numbers, citizen card numbers and SNS user numbers according to
 * the Portuguese formats and checks for duplicates across its
 * collection based on phone, email, citizen card number and SNS user
 * number.
 */
class SNSUserContainer {
private:
    std::vector<SNSUser> users;

    /**
     * Validates Portuguese phone numbers.  A valid phone number must
     * contain exactly nine digits.  This covers both landline and
     * mobile numbers as defined in the Portuguese closed numbering
     * plan【988867083390475†L40-L43】.
     */
    static bool isValidPhoneNumber(const std::string &phone);

    /**
     * Validates Portuguese citizen card numbers.  According to
     * Portuguese specifications, a citizen card number is composed of
     * eight digits, an optional space or hyphen, one digit, an optional
     * space, two letters and a final check digit【432736622680631†L580-L596】.
     */
    static bool isValidCitizenCardNumber(const std::string &cc);

    /**
     * Validates SNS user numbers (Número de Utente).  A valid SNS
     * number consists of exactly nine digits and is distinct from
     * social security numbers【988867083390475†L40-L43】.
     */
    static bool isValidSNSUserNumber(const std::string &sns);

    /**
     * Performs a very simple validation of e‑mail addresses by checking
     * for the presence of a single '@' and at least one '.' after the
     * '@'.  This is not exhaustive but sufficient for demonstration.
     */
    static bool isValidEmail(const std::string &email);

    /**
     * Checks whether a new user conflicts with existing users based on
     * unique fields: phone number, email, citizen card number and SNS
     * user number.  Returns true if a conflict is found.
     */
    bool hasDuplicate(const SNSUser &user) const;

public:
    /**
     * Instantiates a new SNSUser object from the provided attributes.
     * The created object may be invalid; validation is performed when
     * saving.
     */
    SNSUser create(const std::string &name,
                   const std::string &dateOfBirth,
                   const std::string &sex,
                   const std::string &postalAddress,
                   const std::string &phoneNumber,
                   const std::string &email,
                   const std::string &citizenCardNumber,
                   const std::string &snsUserNumber);

    /**
     * Validates the provided user and returns a Result representing
     * whether the user can be persisted.  Validation comprises
     * mandatory field checks, format checks and duplicate checks.
     */
    Result validate(const SNSUser &user) const;

    /**
     * Validates and, upon success, stores the given SNSUser.  When
     * validation fails, the user is not stored and a descriptive
     * Result is returned.
     */
    Result save(const SNSUser &user);

    /**
     * Returns all registered users.  Useful for queries in future
     * iterations.
     */
    const std::vector<SNSUser> &getAll() const;
};

#endif // LETI_ESOFT_25_26_B1_SNSUSERCONTAINER_H