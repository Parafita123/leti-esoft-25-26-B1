//
// SNSUserService.h
//
// Provides the business logic for registering SNS users.  The service
// layer is responsible for creating domain objects, performing
// mandatory field checks, validating formats according to the
// Portuguese numbering and card schemes and enforcing uniqueness of
// phone number, email, citizen card number and SNS user number.
// This class delegates persistence to an SNSUserRepository.  The
// separation of concerns between validation and storage adheres to
// the Service and Repository patterns【687714786585861†L587-L596】.
//

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