//
// Created by Filipe on 12/12/2025.
//

#include "../../headers/views/RegisterVaccinationCenterView.h"
#include <iostream>
#include <limits>

RegisterVaccinationCenterView::RegisterVaccinationCenterView(RegisterVaccinationCenterController controller)
        : controller(std::move(controller)) {}

void RegisterVaccinationCenterView::show() {
    VaccinationCenterDTO dto;

    std::cout << "=== Register Vaccination Center (US13) ===\n";
    std::cout << "Select facility type:\n";
    std::cout << "  1 - Healthcare Center\n";
    std::cout << "  2 - Community Mass Vaccination Center\n";
    std::cout << "Option: ";

    int opt;
    std::cin >> opt;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    dto.facilityType = (opt == 2) ? FacilityType::COMMUNITY : FacilityType::HEALTHCARE;

    // base data (after facility type)
    std::cout << "Name: "; std::getline(std::cin, dto.name);
    std::cout << "Postal address: "; std::getline(std::cin, dto.postal_address);
    std::cout << "Phone number: "; std::getline(std::cin, dto.phone_number);
    std::cout << "Email: "; std::getline(std::cin, dto.email);
    std::cout << "Website address: "; std::getline(std::cin, dto.website_address);
    std::cout << "Opening hours: "; std::getline(std::cin, dto.opening_hours);
    std::cout << "Closing hours: "; std::getline(std::cin, dto.closing_hours);
    std::cout << "Max vaccines per hour: ";
    std::cin >> dto.max_vaccines_per_hour;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // community branch: list + choose vaccine type
    if (dto.facilityType == FacilityType::COMMUNITY) {
        auto list = controller.listVaccineTypes();

        if (list.empty()) {
            std::wcout << L"\n No vaccine types available. Create one first (dependency on US10).\n";
            return;
        }

        std::cout << "\nAvailable vaccine types:\n";
        for (const auto& vt : list) {
            std::cout << " - " << vt->getTypeCode() << " (" << vt->getDisease() << ")\n";
        }

        std::cout << "Select vaccine type code: ";
        std::getline(std::cin, dto.vaccineTypeCode);
    }

    // confirmation (common)
    std::cout << "\n--- Confirmation ---\n";
    std::cout << "Type: " << ((dto.facilityType == FacilityType::COMMUNITY) ? "COMMUNITY" : "HEALTHCARE") << "\n";
    std::cout << "Name: " << dto.name << "\n";
    std::cout << "Max/hour: " << dto.max_vaccines_per_hour << "\n";
    if (dto.facilityType == FacilityType::COMMUNITY) {
        std::cout << "VaccineType: " << dto.vaccineTypeCode << "\n";
    }
    std::cout << "Confirm? (Y/N): ";

    char ans;
    std::cin >> ans;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (ans != 'Y' && ans != 'y') {
        std::cout << "Operation cancelled.\n";
        return;
    }

    Result r = controller.registerVaccinationCenter(dto);
    if (r.isOK()) std::wcout << L"\n Ok. " << r.getMessage() << L"\n";
    else          std::wcout << L"\n Not Ok. " << r.getMessage() << L"\n";
}