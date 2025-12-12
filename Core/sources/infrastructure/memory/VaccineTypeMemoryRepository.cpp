//
// Created by Filipe on 12/12/2025.
//
#include "headers/infrastructure/memory/VaccineTypeMemoryRepository.h"
#include "headers/domain/model/VaccineType.h"
#include "headers/domain/shared/Result.h"

std::vector<std::shared_ptr<VaccineType>> VaccineTypeMemoryRepository::findAll() {
    return data;
}

std::shared_ptr<VaccineType> VaccineTypeMemoryRepository::findByCode(const std::string& code) {
    for (auto& vt : data) {
        if (vt && vt->getTypeCode() == code) return vt;
    }
    return nullptr;
}

bool VaccineTypeMemoryRepository::exists(const std::string& code) {
    return static_cast<bool>(findByCode(code));
}

Result VaccineTypeMemoryRepository::save(std::shared_ptr<VaccineType> obj) {
    if (!obj) return Result::NOK(L"Null VaccineType.");

    //validar 5 chars + unique
    if (obj->getTypeCode().size() != 5) return Result::NOK(L"Type code must have exactly 5 characters.");
    if (exists(obj->getTypeCode())) return Result::NOK(L"Type code already exists.");

    data.push_back(std::move(obj));
    return Result::OK(L"Vaccine Type saved successfully.");
}