//
// Created by diogo on 11/01/2026.
//

#ifndef LETI_ESOFT_25_26_B1_VACCINATIONAPPOINTMENTSERVICE_H
#define LETI_ESOFT_25_26_B1_VACCINATIONAPPOINTMENTSERVICE_H


#include <memory>
#include "headers/domain/repositories/vaccinationAppointmentRepository.h"

class VaccinationAppointmentService {
private:
    std::shared_ptr<VaccinationAppointmentRepository> repo;

    bool hasConflict(const std::string& sns,
                     const std::string& date,
                     const std::string& time) const;

public:
    explicit VaccinationAppointmentService(
            std::shared_ptr<VaccinationAppointmentRepository> repo);

    void create(const std::string& snsUserNumber,
                const std::string& facilityId,
                const std::string& vaccineTypeCode,
                const std::string& date,
                const std::string& time);
};



#endif //LETI_ESOFT_25_26_B1_VACCINATIONAPPOINTMENTSERVICE_H
