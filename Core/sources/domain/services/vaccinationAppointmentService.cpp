//
// Created by diogo on 11/01/2026.
//
#include "headers/domain/services/vaccinationAppointmentService.h"
#include <stdexcept>

VaccinationAppointmentService::VaccinationAppointmentService(
        std::shared_ptr<VaccinationAppointmentRepository> repo)
        : repo(repo) {}

bool VaccinationAppointmentService::hasConflict(
        const std::string& sns,
        const std::string& date,
        const std::string& time) const {

    for (const auto& a : repo->findAll()) {
        if (a.getSnsUserNumber() == sns &&
            a.getDate() == date &&
            a.getTime() == time) {
            return true;
        }
    }
    return false;
}

void VaccinationAppointmentService::create(
        const std::string& snsUserNumber,
        const std::string& facilityId,
        const std::string& vaccineTypeCode,
        const std::string& date,
        const std::string& time) {

    if (hasConflict(snsUserNumber, date, time)) {
        throw std::runtime_error("SNS user already has an appointment at this time.");
    }

    VaccinationAppointment appointment(
            snsUserNumber, facilityId, vaccineTypeCode, date, time);

    repo->save(appointment);
}
