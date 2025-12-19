//
// Created by Guta on 19/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_RECORDVACCINATIONCONTROLLER_H
#define LETI_ESOFT_25_26_B1_RECORDVACCINATIONCONTROLLER_H

#include <memory>
#include "headers/domain/services/VaccinationProcessService.h"
#include "../Core/headers/controllers/dto//VaccinationProcessDTO.h"

/**
 * Controller responsible for orchestrating the recording of a vaccination
 * process between the view and the service.  It exposes operations to
 * remove the patient from the waiting room, create and persist the
 * vaccination process and assign the patient to a recovery room.
 */
class RecordVaccinationController {
private:
    std::shared_ptr<VaccinationProcessService> service;

public:
    explicit RecordVaccinationController(std::shared_ptr<VaccinationProcessService> service);

    /**
     * Removes the SNS user from the waiting room.  See
     * VaccinationProcessService::removeFromWaitingRoom.
     */
    void removeFromWaitingRoom(const std::string &snsUserNumber);

    /**
     * Registers a vaccination process using the information contained
     * in the DTO.  This method creates a VaccinationProcess domain
     * object, persists it via the service and assigns the user to
     * the recovery room.  The nurse identifier is not captured by
     * this controller and is left empty.
     */
    Result registerVaccination(const VaccinationProcessDTO &dto);
};

#endif // LETI_ESOFT_25_26_B1_RECORDVACCINATIONCONTROLLER_H
