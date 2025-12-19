//
// Created by Guta on 19/12/2025.
//

#include "../ConsoleApp/headers/views/RecordVaccinationView.h"
#include "../Core/headers/controllers/dto/VaccinationProcessDTO.h"
#include <iostream>
#include <limits>
#include <algorithm>

using std::string;

static inline string trim_copy(string s) {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
        return !std::isspace(ch);
    }));
    s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
        return !std::isspace(ch);
    }).base(), s.end());
    return s;
}

RecordVaccinationView::RecordVaccinationView(RecordVaccinationController controller)
        : controller(std::move(controller)) {}

void RecordVaccinationView::run() {
    std::string snsUserNumber;
    std::string vaccineCode;
    std::string lotNumber;

    std::cout << "\n=== Record Vaccination ===" << std::endl;
    std::cout << "SNS user number: ";
    std::getline(std::cin, snsUserNumber);
    snsUserNumber = trim_copy(snsUserNumber);
    
    std::cout << "Vaccine code: ";
    std::getline(std::cin, vaccineCode);
    vaccineCode = trim_copy(vaccineCode);

    std::cout << "Lot number: ";
    std::getline(std::cin, lotNumber);
    lotNumber = trim_copy(lotNumber);

    // Remove from waiting room before confirmation
    controller.removeFromWaitingRoom(snsUserNumber);

    // Show confirmation
    std::cout << "\nYou entered:\n";
    std::cout << "  SNS user number: " << snsUserNumber << std::endl;
    std::cout << "  Vaccine code: " << vaccineCode << std::endl;
    std::cout << "  Lot number: " << lotNumber << std::endl;
    std::cout << "Confirm registration? (y/n): ";
    std::string confirm;
    std::getline(std::cin, confirm);
    if (!confirm.empty() && (confirm[0] == 'y' || confirm[0] == 'Y')) {
        VaccinationProcessDTO dto{snsUserNumber, vaccineCode, lotNumber};
        Result result = controller.registerVaccination(dto);
        if (result.isOK()) {
            std::wcout << L"Vaccination recorded successfully." << std::endl;
        } else {
            std::wcout << result.getMessage() << std::endl;
        }


    } else {
        std::cout << "Operation cancelled." << std::endl;
    }
}
