//
// Created by Filipe on 13/11/2025.
//
#include "../ConsoleApp/headers/views/CreateNewVaccineTypeView.h"
#include "../Core/headers/controllers/ui/CreateNewVaccineTypeController.h"
#include "../Core/headers/domain/model/VaccineTypeContainer.h"
#include "../Core/headers/controllers/ui/App.h"

int main() {
    App app;

    auto repo = app.getVaccineTypeRepository();
    CreateNewVaccineTypeController controller(repo);
    CreateNewVaccineTypeView view(controller);

    view.show();
    return 0;
}