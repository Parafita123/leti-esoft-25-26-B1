#include <iostream>
#include <limits>

#include "../ConsoleApp/headers/views/MainView.h"
#include "../Core/headers/controllers/ui/CreateNewVaccineTypeController.h"
#include "../ConsoleApp/headers/views/CreateNewVaccineTypeView.h"
#include "../Core/headers/domain/model/VaccineTypeContainer.h"
#include "../Core/headers/controllers/ui/ListEmployeesByRoleController.h"
#include "../ConsoleApp/headers/views/ListEmployeesByRoleView.h"
#include "../Core/headers/controllers/ui/App.h"

// US20 - Register SNS user
#include "../Core/headers/controllers/ui/RegisterSNSUserController.h"
#include "../ConsoleApp/headers/views/RegisterSNSUserView.h"
#include "../Core/headers/domain/services/SNSUserService.h"
#include <memory>

// US11 - Register vaccine
#include "../Core/headers/controllers/ui/RegisterVaccineController.h"
#include "../ConsoleApp/headers/views/RegisterVaccineView.h"

MainView::MainView(App& app) : app(app) {}

void MainView::showMenu() const {
    std::cout << "\n=========== MAIN MENU ===========" << std::endl;
    std::cout << "1 - Create new vaccine type" << std::endl;
    std::cout << "2 - List employees by role" << std::endl;
    std::cout << "3 - Register new vaccine" << std::endl;   // US11
    std::cout << "4 - Register SNS user" << std::endl;      // US20
    std::cout << "0 - Exit" << std::endl;
    std::cout << "Choose an option: ";
}

void MainView::handleOption(int option) {
    switch (option) {
        case 1: {
            // US10 - Create new vaccine type
            VaccineTypeContainer& container = app.getVaccineTypeContainer();

            CreateNewVaccineTypeController controller(container);
            CreateNewVaccineTypeView view(controller);

            view.show();
            break;
        }
        case 2: {
            // List employees by role
            ListEmployeesByRoleController controller(app);
            ListEmployeesByRoleView view(controller);

            view.listEmployeesByRole();
            break;
        }
        case 3: {
            // US11 - Register a new vaccine
            VaccineContainer& vaccineContainer = app.getVaccineContainer();
            VaccineTypeContainer& typeContainer = app.getVaccineTypeContainer();

            RegisterVaccineController controller(vaccineContainer, typeContainer);
            RegisterVaccineView view(controller);

            view.show();
            break;
        }
        case 4: {
            // US20 - Register SNS user (using service/repository pattern)
            std::shared_ptr<SNSUserService> service = app.getSNSUserService();
            RegisterSNSUserController controller(service);
            RegisterSNSUserView view(controller);
            view.run();
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
