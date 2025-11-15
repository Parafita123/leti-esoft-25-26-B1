//
// Created by Filipe on 04/11/2025.
//
#include "../ConsoleApp/headers/views/CreateNewVaccineTypeView.h"
#include <iostream>

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

    Result result = controller.saveCreatedNewVaccineType();

    if (result.isOK()) {
        std::wcout << "\nVaccine Type created successfully.\n";
    } else {
        std::wcout << "\nError: " << result.getMessage() << "\n";
    }
}