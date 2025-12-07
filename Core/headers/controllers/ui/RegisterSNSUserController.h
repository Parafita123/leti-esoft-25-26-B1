//
// Created by ChatGPT on 07/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_REGISTERSNSUSERCONTROLLER_H
#define LETI_ESOFT_25_26_B1_REGISTERSNSUSERCONTROLLER_H

#include <string>
#include "headers/domain/model/SNSUserContainer.h"

/**
 * Controller class that mediates between the view and the SNSUserContainer
 * during the registration of an SNS user.  It encapsulates the
 * application logic needed to create a new user and to request its
 * persistence.
 */
class RegisterSNSUserController {
private:
    SNSUserContainer *container;

public:
    explicit RegisterSNSUserController(SNSUserContainer *container);

    /**
     * Creates an SNSUser instance based on the provided user input.
     */
    SNSUser createSNSUser(const std::string &name,
                          const std::string &dateOfBirth,
                          const std::string &sex,
                          const std::string &postalAddress,
                          const std::string &phoneNumber,
                          const std::string &email,
                          const std::string &citizenCardNumber,
                          const std::string &snsUserNumber);

    /**
     * Persists a registered SNS user.  Validation and duplicate checks
     * are performed by the SNSUserContainer.
     */
    Result saveRegisteredSNSUser(const SNSUser &user);
};

#endif // LETI_ESOFT_25_26_B1_REGISTERSNSUSERCONTROLLER_H