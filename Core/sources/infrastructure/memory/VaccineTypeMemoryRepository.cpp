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

    // Verifica se é uma atualização ou inserção nova
    for (size_t i = 0; i < data.size(); ++i) {
        if (data[i]->getTypeCode() == obj->getTypeCode()) {
            data[i] = std::move(obj); // Atualiza
            return Result::OK(L"Vaccine Type updated successfully.");
        }
    }
    // Se chegou aqui, é novo
    if (obj->getTypeCode().size() != 5) return Result::NOK(L"Type code must have 5 chars.");
    data.push_back(std::move(obj));
    return Result::OK(L"Vaccine Type saved successfully.");
}
Result VaccineTypeMemoryRepository::remove(const std::string& code) {
    for (auto it = data.begin(); it != data.end(); ++it) {
        if ((*it)->getTypeCode() == code) {
            data.erase(it);
            return Result::OK(L"Vaccine type removed successfully.");
        }
    }
    return Result::NOK(L"Vaccine type not found.");
}