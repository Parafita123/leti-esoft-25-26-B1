//
// Created by Filipe on 04/11/2025.
//
#include "../Core/headers/controllers/ui/CreateNewVaccineTypeController.h"
#include <stdexcept>

CreateNewVaccineTypeController::CreateNewVaccineTypeController(std::shared_ptr<VaccineTypeRepository> repo)
        : repo(std::move(repo)) {}

void CreateNewVaccineTypeController::createNewVaccineType(const std::string& type_code,
                                                          const std::string& disease,
                                                          const std::string& short_description) {
    // cria o objeto em memória (ainda não guarda)
    current = std::make_shared<VaccineType>(type_code, disease, short_description);
}

Result CreateNewVaccineTypeController::save() {
    if (!current) {
        return Result::NOK(L"No vaccine type to save.");
    }
    // guarda no repository (que é partilhado pela app e por US13)
    return repo->save(current);
}

const VaccineType& CreateNewVaccineTypeController::getCurrentVaccineType() const {
    if (!current) {
        throw std::logic_error("No current VaccineType. Call createNewVaccineType() first.");
    }
    return *current;
}