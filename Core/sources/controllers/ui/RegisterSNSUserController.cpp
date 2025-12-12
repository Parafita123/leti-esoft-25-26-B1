//
// Created by Guta on 07/12/2025.
//

#include "headers/controllers/ui/RegisterSNSUserController.h"

RegisterSNSUserController::RegisterSNSUserController(std::shared_ptr<SNSUserService> service)
        : service(std::move(service)) {}

std::shared_ptr<SNSUser> RegisterSNSUserController::createSNSUser(const std::string &name,
                                                                  const std::string &dateOfBirth,
                                                                  const std::string &sex,
                                                                  const std::string &postalAddress,
                                                                  const std::string &phoneNumber,
                                                                  const std::string &email,
                                                                  const std::string &citizenCardNumber,
                                                                  const std::string &snsUserNumber) {
    return service->create(name, dateOfBirth, sex, postalAddress, phoneNumber, email, citizenCardNumber, snsUserNumber);
}

Result RegisterSNSUserController::saveRegisteredSNSUser(std::shared_ptr<SNSUser> user) {
    return service->add(user);
}
