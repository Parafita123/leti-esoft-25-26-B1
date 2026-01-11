//
// Created by Filipe on 20/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_VACCINATIONAPPOINTMENTREPOSITORY_H
#define LETI_ESOFT_25_26_B1_VACCINATIONAPPOINTMENTREPOSITORY_H

#pragma once

#include <string>
#include "headers/domain/model/vaccinationAppointment.h"
#include <vector>

class VaccinationAppointmentRepository {
public:
    virtual ~VaccinationAppointmentRepository() = default;

    // dependency with US21
    virtual bool existsForDay(const std::string& snsUserNumber,
                              int facilityID,
                              const std::string& day) = 0;


    virtual void save(const VaccinationAppointment& appointment) = 0;
    virtual std::vector<VaccinationAppointment> findAll() const = 0;

};


#endif //LETI_ESOFT_25_26_B1_VACCINATIONAPPOINTMENTREPOSITORY_H
