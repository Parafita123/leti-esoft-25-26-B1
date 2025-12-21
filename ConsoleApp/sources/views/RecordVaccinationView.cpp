// created by Guta on 2025-12-20
//
// Implementation of RecordVaccinationView.  This view prompts the
// operator for the necessary information to record a vaccine
// administration and delegates the call to the controller.

#include "../ConsoleApp/headers/views/RecordVaccinationView.h"
#include <iostream>
#include <limits>
#include <cctype>

RecordVaccinationView::RecordVaccinationView(RecordVaccinationController controller)
        : controller(std::move(controller)) {}

std::string RecordVaccinationView::prompt(const std::string &message) {
    std::cout << message;
    std::string input;
    std::getline(std::cin, input);
    // Trim leading/trailing whitespace
    while (!input.empty() && std::isspace(input.front())) input.erase(input.begin());
    while (!input.empty() && std::isspace(input.back())) input.pop_back();
    return input;
}

void RecordVaccinationView::run() {


    std::string snsUserNumber = prompt("SNS user number: ");
    std::string vaccineCode   = prompt("Vaccine code: ");
    std::string lotNumber     = prompt("Lot number: ");

    // Confirm details with the user
    std::cout << "\nYou entered:\n";
    std::cout << "  SNS user number: " << snsUserNumber << '\n';
    std::cout << "  Vaccine code: " << vaccineCode << '\n';
    std::cout << "  Lot number: " << lotNumber << '\n';
    std::cout << "Confirm? (y/n): ";
    char confirm;
    std::cin >> confirm;
    // consume the remainder of the line
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (std::tolower(confirm) != 'y') {
        std::cout << "Operation cancelled by user." << std::endl;
        return;
    }

    VaccinationProcessDTO dto{snsUserNumber, vaccineCode, lotNumber};
    Result result = controller.recordVaccination(dto);
    if (result.isOK()) {
        std::cout << "Vaccination recorded successfully." << std::endl;
    } else {
        std::wcout << "Error recording vaccination: " << result.getMessage() << std::endl;
    }
}