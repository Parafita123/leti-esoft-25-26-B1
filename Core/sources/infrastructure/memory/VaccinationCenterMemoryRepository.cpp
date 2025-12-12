//
// Created by Filipe on 12/12/2025.
//
#include "headers/infrastructure//memory/VaccinationCenterMemoryRepository.h"

Result VaccinationCenterMemoryRepository::save(std::shared_ptr<Facility> obj) {
    data.push_back(std::move(obj));
    return Result::OK(L"Vaccination center saved.");
}
