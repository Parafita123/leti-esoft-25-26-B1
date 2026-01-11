//
// Created by diogo on 11/01/2026.
//
#include "headers/domain/model/vaccinationAppointment.h"


VaccinationAppointment::VaccinationAppointment(
        const std::string& snsUserNumber,
        const std::string& facilityId,
        const std::string& vaccineTypeCode,
        const std::string& date,
        const std::string& time)
        : snsUserNumber(snsUserNumber),
          facilityId(facilityId),
          vaccineTypeCode(vaccineTypeCode),
          date(date),
          time(time) {}

const std::string& VaccinationAppointment::getSnsUserNumber() const { return snsUserNumber; }
const std::string& VaccinationAppointment::getFacilityId() const { return facilityId; }
const std::string& VaccinationAppointment::getVaccineTypeCode() const { return vaccineTypeCode; }
const std::string& VaccinationAppointment::getDate() const { return date; }
const std::string& VaccinationAppointment::getTime() const { return time; }