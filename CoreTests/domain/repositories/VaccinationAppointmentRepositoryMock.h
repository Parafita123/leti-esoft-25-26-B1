//
// Created by Filipe on 10/01/2026.
//

#ifndef LETI_ESOFT_25_26_B1_VACCINATIONAPPOINTMENTREPOSITORYMOCK_H
#define LETI_ESOFT_25_26_B1_VACCINATIONAPPOINTMENTREPOSITORYMOCK_H

#include "gmock/gmock.h"
#include "headers/domain/repositories/VaccinationAppointmentRepository.h"
#include "headers/domain/model/vaccinationAppointment.h"
#include <vector>

class VaccinationAppointmentRepositoryMock : public VaccinationAppointmentRepository {
public:
    MOCK_METHOD(bool, existsForDay,
                (const std::string& snsUserNumber, int facilityID, const std::string& day),
                (override));

    MOCK_METHOD(void, save,
                (const VaccinationAppointment& appointment),
                (override));

    MOCK_METHOD(std::vector<VaccinationAppointment>, findAll,
                (),
                (const, override));
};



#endif //LETI_ESOFT_25_26_B1_VACCINATIONAPPOINTMENTREPOSITORYMOCK_H
