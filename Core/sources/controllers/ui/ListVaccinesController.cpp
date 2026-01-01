//
// Created by diogo on 01/01/2026.
//
#include "headers/controllers/ui/ListVaccinesController.h"
#include "headers/domain/DTO/Mapper/VaccineMapper.h"

ListVaccinesController::ListVaccinesController(const VaccineContainer& repo)
        : service(repo) {}

std::vector<VaccineDTO> ListVaccinesController::listAllVaccines() {
    auto vaccines = service.getAllVaccines();

    std::vector<VaccineDTO> dtoList;
    for (const auto& v : vaccines) {
        dtoList.push_back(VaccineMapper::toDTO(v));
    }
    return dtoList;
}