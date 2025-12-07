//
// Created by ChatGPT on 07/12/2025.
//

#include "../../headers/views/RegisterSNSUserView.h"

#include <limits>
#include <iostream>
#include <locale>
#include <codecvt>

using std::string;

static string ws2s_internal(const std::wstring& w) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
    return conv.to_bytes(w);
}

// Local helper to avoid duplication of ws2s across multiple views
std::string RegisterSNSUserView::ws2s(const std::wstring &w) {
    return ws2s_internal(w);
}

RegisterSNSUserView::RegisterSNSUserView(RegisterSNSUserController controller)
        : controller(controller) {}

void RegisterSNSUserView::run() {
    // Gather all necessary information from the receptionist
    std::string name, dateOfBirth, sex, postalAddress, phone, email, cc, sns;

    std::cout << "Enter name: ";
    std::getline(std::cin, name);

    std::cout << "Enter date of birth (YYYY-MM-DD): ";
    std::getline(std::cin, dateOfBirth);

    std::cout << "Enter sex (M/F) [leave blank if not provided]: ";
    std::getline(std::cin, sex);

    std::cout << "Enter postal address: ";
    std::getline(std::cin, postalAddress);

    std::cout << "Enter phone number (9 digits): ";
    std::getline(std::cin, phone);

    std::cout << "Enter email address: ";
    std::getline(std::cin, email);

    std::cout << "Enter citizen card number: ";
    std::getline(std::cin, cc);

    std::cout << "Enter SNS user number (9 digits): ";
    std::getline(std::cin, sns);

    SNSUser user = controller.createSNSUser(name, dateOfBirth, sex, postalAddress, phone, email, cc, sns);

    // Show the collected data and confirm with the receptionist
    std::cout << "\nReview the entered data:\n";
    std::cout << "Name: " << name << "\n";
    std::cout << "Date of Birth: " << dateOfBirth << "\n";
    std::cout << "Sex: " << (sex.empty() ? "(not provided)" : sex) << "\n";
    std::cout << "Postal Address: " << postalAddress << "\n";
    std::cout << "Phone Number: " << phone << "\n";
    std::cout << "Email: " << email << "\n";
    std::cout << "Citizen Card Number: " << cc << "\n";
    std::cout << "SNS User Number: " << sns << "\n";

    std::cout << "\nConfirm registration? (y/n): ";
    char c;
    std::cin >> c;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (c == 'y' || c == 'Y') {
        Result r = controller.saveRegisteredSNSUser(user);
        std::cout << ws2s(r.getMessage()) << "\n";
    } else {
        std::cout << "Operation cancelled.\n";
    }
}
