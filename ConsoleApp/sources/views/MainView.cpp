//
// Created by Filipe on 13/11/2025.
//


#include <iostream>
#include <limits>

#include "../ConsoleApp/headers/views/MainView.h"
#include "../Core/headers/controllers/ui/CreateNewVaccineTypeController.h"
#include "../ConsoleApp/headers/views/CreateNewVaccineTypeView.h"
#include "../Core/headers/domain/model/VaccineTypeContainer.h"

MainView::MainView(App& app) : app(app) {}

void MainView::showMenu() const {
    std::cout << "\n=========== MAIN MENU ===========" << std::endl;
    std::cout << "1 - Create new vaccine type" << std::endl;
    std::cout << "0 - Exit" << std::endl;
    std::cout << "Choose an option: ";
}

void MainView::handleOption(int option) {
    switch (option) {
        case 1: {
            VaccineTypeContainer& container = app.getVaccineTypeContainer();

            CreateNewVaccineTypeController controller(container);
            CreateNewVaccineTypeView view(controller);

            view.show();
            break;
        }
        case 0:
            std::cout << "Exiting application..." << std::endl;
            break;
        default:
            std::cout << "Invalid option. Please try again." << std::endl;
            break;
    }
}

void MainView::show() {
    bool running = true;

    while (running) {
        showMenu();

        int option;
        if (!(std::cin >> option)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number." << std::endl;
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        handleOption(option);

        if (option == 0) {
            running = false;
        }
    }
}