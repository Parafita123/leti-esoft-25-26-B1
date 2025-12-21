// created by Guta on 2025-12-20
//
// Controller responsible for coordinating the recording of a vaccination
// administration between the user interface and the domain service.

#ifndef LETI_ESOFT_25_26_B1_RECORDVACCINATIONCONTROLLER_H
#define LETI_ESOFT_25_26_B1_RECORDVACCINATIONCONTROLLER_H

#include <memory>
#include "headers/domain/services/VaccinationProcessService.h"
#include "headers/controllers/dto/VaccinationProcessDTO.h"

class RecordVaccinationController {
private:
    std::shared_ptr<VaccinationProcessService> service;
public:
    explicit RecordVaccinationController(std::shared_ptr<VaccinationProcessService> service);

    /**
     * Delegates the recording of a vaccination to the service.  Returns
     * the Result object from the service.
     */
    Result recordVaccination(const VaccinationProcessDTO &dto);
};

#endif // LETI_ESOFT_25_26_B1_RECORDVACCINATIONCONTROLLER_H