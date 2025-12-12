//
// Created by Guta on 07/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_REGISTERSNSUSERVIEW_H
#define LETI_ESOFT_25_26_B1_REGISTERSNSUSERVIEW_H

#include "headers/controllers/ui/RegisterSNSUserController.h"

#include <memory>

/**
 * Console view responsible for interacting with the receptionist during
 * the SNS user registration process.  It gathers the necessary data
 * from the user, invokes the controller to create and persist the
 * SNS user and displays feedback messages.
 */
class RegisterSNSUserView {
private:
    RegisterSNSUserController controller;
    // Store the user object created by the controller so it can be
    // passed to the save method after confirmation.
    std::shared_ptr<SNSUser> pendingUser;

    // Helper to convert wide strings into standard strings for console output
    static std::string ws2s(const std::wstring& w);

public:
    explicit RegisterSNSUserView(RegisterSNSUserController controller);

    /**
     * Executes the user registration UI flow.  Reads all required
     * fields from the console, asks for confirmation and delegates
     * creation and persistence to the controller.
     */
    void run();
};

#endif // LETI_ESOFT_25_26_B1_REGISTERSNSUSERVIEW_H