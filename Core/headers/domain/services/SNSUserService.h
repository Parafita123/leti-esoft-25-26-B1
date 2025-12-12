

#ifndef LETI_ESOFT_25_26_B1_SNSUSERSERVICE_H
#define LETI_ESOFT_25_26_B1_SNSUSERSERVICE_H

#include <memory>
#include <string>
#include <regex>
#include "headers/domain/model/SNSUser.h"
#include "headers/domain/repositories/SNSUserRepository.h"
#include "headers/domain/shared/Result.h"

class SNSUserService {
private:
    std::shared_ptr<SNSUserRepository> repo;

    // Validation helpers
    static bool isValidPhoneNumber(const std::string &phone);
    static bool isValidCitizenCardNumber(const std::string &cc);
    static bool isValidSNSUserNumber(const std::string &sns);
    static bool isValidEmail(const std::string &email);

public:
    explicit SNSUserService(std::shared_ptr<SNSUserRepository> repo);

    /**
     * Creates a new SNSUser object with the provided attributes.  The
     * object is returned wrapped in a shared_ptr so that ownership can
     * be shared between the controller, view and repository.
     */
    std::shared_ptr<SNSUser> create(const std::string &name,
                                    const std::string &dateOfBirth,
                                    const std::string &sex,
                                    const std::string &postalAddress,
                                    const std::string &phoneNumber,
                                    const std::string &email,
                                    const std::string &citizenCardNumber,
                                    const std::string &snsUserNumber);

    /**
     * Validates and persists an SNS user.  Validation includes
     * checking mandatory fields (sex is optional), verifying that
     * phone, citizen card and SNS numbers match the Portuguese
     * formats, ensuring that the email has a valid basic format and
     * enforcing uniqueness of phone, email, citizen card and SNS user
     * numbers across all existing users.  On success, the user is
     * saved through the repository.
     */
    Result add(std::shared_ptr<SNSUser> user);

    /**
     * Returns all users currently stored.  Exposed for future
     * functionality (e.g. listing users).
     */
    std::list<std::shared_ptr<SNSUser>> getAll();
};

#endif // LETI_ESOFT_25_26_B1_SNSUSERSERVICE_H