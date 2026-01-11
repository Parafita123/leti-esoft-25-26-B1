 //
// Created by Filipe on 20/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_VACCINATIONAPPOINTMENTMEMORYREPOSITORY_H
#define LETI_ESOFT_25_26_B1_VACCINATIONAPPOINTMENTMEMORYREPOSITORY_H

#pragma once
#include <vector>
#include <string>
#include "headers/domain/repositories/VaccinationAppointmentRepository.h"
#include "headers/domain/shared/Result.h"

struct AppointmentKey {
    std::string sns;
    int facilityId;
    std::string day;
};

class VaccinationAppointmentMemoryRepository : public VaccinationAppointmentRepository {
private:
    std::vector<AppointmentKey> data;
    std::vector<VaccinationAppointment> appointments;

public:
    bool existsForDay(const std::string& snsUserNumber, int facilityId, const std::string& day) override;

    // helper to seed appointments while US21 is not implemented
    void seed(const std::string& snsUserNumber, int facilityId, const std::string& day);

    void save(const VaccinationAppointment& appointment) override;

    std::vector<VaccinationAppointment> findAll() const override;
};

#endif //LETI_ESOFT_25_26_B1_VACCINATIONAPPOINTMENTMEMORYREPOSITORY_H
