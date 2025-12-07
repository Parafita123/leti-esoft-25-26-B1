//
// Created by ChatGPT on 07/12/2025.
//

#include "headers/controllers/ui/RegisterSNSUserController.h"

RegisterSNSUserController::RegisterSNSUserController(SNSUserContainer *container)
        : container(container) {}

SNSUser RegisterSNSUserController::createSNSUser(const std::string &name,
                                                  const std::string &dateOfBirth,
                                                  const std::string &sex,
                                                  const std::string &postalAddress,
                                                  const std::string &phoneNumber,
                                                  const std::string &email,
                                                  const std::string &citizenCardNumber,
                                                  const std::string &snsUserNumber) {
    return container->create(name, dateOfBirth, sex, postalAddress, phoneNumber, email, citizenCardNumber, snsUserNumber);
}

Result RegisterSNSUserController::saveRegisteredSNSUser(const SNSUser &user) {
    return container->save(user);
}
