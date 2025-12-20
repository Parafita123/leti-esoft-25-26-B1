//
// Created by Filipe on 20/12/2025.
//
#include "headers/infrastructure/memory/VaccinationAppointmentMemoryRepository.h"

bool VaccinationAppointmentMemoryRepository::existsForDay(const std::string& snsUserNumber, int facilityId, const std::string& day) {
    for (const auto& k : data) {
        if (k.sns == snsUserNumber && k.facilityId == facilityId && k.day == day) return true;
    }
    return false;
}

void VaccinationAppointmentMemoryRepository::seed(const std::string& snsUserNumber, int facilityId, const std::string& day) {
    data.push_back({snsUserNumber, facilityId, day});
}
