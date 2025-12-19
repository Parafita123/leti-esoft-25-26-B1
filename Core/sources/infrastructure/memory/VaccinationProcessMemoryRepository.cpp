//
// Created by Guta on 18/12/2025.
//
#include "../Core/headers/domain/shared/Result.h"
#include "headers/infrastructure/memory/VaccinationProcessMemoryRepository.h"
#include <ctime>

Result VaccinationProcessMemoryRepository::save(const VaccinationProcess &process) {
    // Check for duplicate: same SNS user on same date (YYYY-MM-DD)
    // Extract date part from administrationDateTime (first 10 characters)
    std::string date = process.getAdministrationDateTime().substr(0, 10);
    for (const auto &p : data) {
        if (p.getSNSUserNumber() == process.getSNSUserNumber() &&
            p.getAdministrationDateTime().substr(0, 10) == date) {
            return Result::NOK(L"Duplicate vaccination process for this SNS user on this date.");


        }
    }
    data.push_back(process);
    return Result::OK(L"Vaccination process recorded successfully.");


}

std::vector<VaccinationProcess> VaccinationProcessMemoryRepository::findAll() {
    return std::vector<VaccinationProcess>(data.begin(), data.end());
}

std::optional<VaccinationProcess> VaccinationProcessMemoryRepository::findBySNSUserAndDate(const std::string &snsUserNumber,
                                                                                           const std::string &date) {
    for (const auto &p : data) {
        if (p.getSNSUserNumber() == snsUserNumber &&
            p.getAdministrationDateTime().substr(0, 10) == date) {
            return p;
        }
    }
    return std::nullopt;
}