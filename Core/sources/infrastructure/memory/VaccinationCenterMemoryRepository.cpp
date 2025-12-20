//
// Created by Filipe on 12/12/2025.
//
#include "headers/infrastructure//memory/VaccinationCenterMemoryRepository.h"

Result VaccinationCenterMemoryRepository::save(std::shared_ptr<Facility> obj) {
    if (!obj) return Result::NOK(L"Null facility.");
    data.push_back(std::move(obj));
    return Result::OK(L"Vaccination center saved.");
}

std::vector<std::shared_ptr<Facility>> VaccinationCenterMemoryRepository::findAll() {
    return data;
}

std::optional<std::shared_ptr<Facility>> VaccinationCenterMemoryRepository::findById(int facilityID) {
    for (const auto& f : data) {
        if (f && f->getFacilityID() == facilityID) {  // assumes Facility::getId()
            return f;
        }
    }
    return std::nullopt;
}
