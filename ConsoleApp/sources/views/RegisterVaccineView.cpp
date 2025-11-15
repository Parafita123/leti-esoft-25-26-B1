//
// Created by ChatGPT on 2025-11-15.
//

#include "../ConsoleApp/headers/views/RegisterVaccineView.h"
#include <iostream>
#include <limits>

RegisterVaccineView::RegisterVaccineView(RegisterVaccineController controller)
        : controller(std::move(controller)) {}

static void printTechnologies() {
    std::cout << "Available vaccine technologies:" << std::endl;
    int idx = 1;
    for (auto t : VaccineTechnologyUtils::getAllowedTechnologies()) {
        std::cout << "  " << idx++ << " - " << VaccineTechnologyUtils::toString(t) << std::endl;
    }
}

VaccineTechnology RegisterVaccineView::askTechnology() const {
    printTechnologies();
    size_t total = VaccineTechnologyUtils::getAllowedTechnologies().size();
    while (true) {
        std::cout << "Select technology [1.." << total << "]: ";
        int idx = 0;
        if (!(std::cin >> idx)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number." << std::endl;
            continue;
        }
        if (idx >= 1 && (size_t)idx <= total) {
            // flush the line break left by std::cin
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return VaccineTechnologyUtils::getAllowedTechnologies()[static_cast<size_t>(idx) - 1];
        }
        std::cout << "Invalid selection. Try again." << std::endl;
    }
}

void RegisterVaccineView::show() {
    std::string commercialName, brand, typeCode, lot, expDate;

    std::cout << "=== Register a New Vaccine ===" << std::endl;

    std::cout << "Commercial name: ";
    std::getline(std::cin, commercialName);

    std::cout << "Brand: ";
    std::getline(std::cin, brand);

    std::cout << "Type code (existing): ";
    std::getline(std::cin, typeCode);

    VaccineTechnology tech = askTechnology();

    std::cout << "Lot number (optional): ";
    std::getline(std::cin, lot);

    std::cout << "Expiration date (optional): ";
    std::getline(std::cin, expDate);

    std::optional<std::string> expiration;
    if (!expDate.empty()) {
        expiration = expDate;
    }

    // Build the vaccine
    try {
        controller.createNewVaccine(commercialName, brand, typeCode, tech, lot, expiration);
    } catch (const std::exception& ex) {
        std::cout << "[ERROR] " << ex.what() << std::endl;
        return;
    }

    // Confirm with user
    std::cout << "\nReview your input:\n";
    std::cout << "  Name: " << commercialName << "\n";
    std::cout << "  Brand: " << brand << "\n";
    std::cout << "  Type code: " << typeCode << "\n";
    std::cout << "  Technology: " << VaccineTechnologyUtils::toString(tech) << "\n";
    std::cout << "  Lot: " << lot << "\n";
    std::cout << "  Expiration: " << expDate << "\n";

    std::cout << "Confirm registration? (y/n): ";
    char confirm = 'n';
    std::cin >> confirm;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (confirm != 'y' && confirm != 'Y') {
        std::cout << "Operation cancelled." << std::endl;
        return;
    }

    // Save
    Result result = controller.saveCreatedNewVaccine();
    if (result.isOK()) {
        std::wcout << L"\nVaccine registered successfully.\n";
    } else {
        std::wcout << L"\nError: " << result.getMessage() << L"\n";
    }
}