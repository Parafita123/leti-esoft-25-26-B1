//
// Created by Filipe on 04/11/2025.
//
#include "../ConsoleApp/headers/views/CreateNewVaccineTypeView.h"
#include <iostream>
#include <limits>

CreateNewVaccineTypeView::CreateNewVaccineTypeView(CreateNewVaccineTypeController controller)
        : controller(std::move(controller)) {}

void CreateNewVaccineTypeView::show() {
    std::string type_code, disease, short_description;

    std::cout << "=== Specify New Vaccine Type ===" << std::endl;
    std::cout << "Type code: ";
    std::getline(std::cin, type_code);

    std::cout << "Disease: ";
    std::getline(std::cin, disease);

    std::cout << "Short description: ";
    std::getline(std::cin, short_description);

    controller.createNewVaccineType(type_code, disease, short_description);

    const VaccineType& vt = controller.getCurrentVaccineType();

    std::cout << "\nYou entered:\n";
    std::cout << "  Type code       : " << vt.getTypeCode() << "\n";
    std::cout << "  Disease         : " << vt.getDisease() << "\n";
    std::cout << "  Short desc.     : " << vt.getShortDescription() << "\n";

    std::cout << "\nConfirm creation? (Y/N): ";
    char answer;
    std::cin >> answer;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (answer != 'Y' && answer != 'y') {
        std::cout << "Operation cancelled by user.\n";
        return;
    }

    Result result = controller.save();

    if (result.isOK()) {
        std::wcout << "\nVaccine Type created successfully.\n";
    } else {
        std::wcout << "\nError: " << result.getMessage() << "\n";
    }
}