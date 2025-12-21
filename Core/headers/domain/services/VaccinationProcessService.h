// created by Guta on 2025-12-20
//
// Service responsible for orchestrating the vaccination administration
// process.  It performs the necessary interactions with the waiting
// room, vaccination process repository and recovery room repositories.

#ifndef LETI_ESOFT_25_26_B1_VACCINATIONPROCESSSERVICE_H
#define LETI_ESOFT_25_26_B1_VACCINATIONPROCESSSERVICE_H

#include <memory>
#include "headers/domain/shared/Result.h"
#include "headers/controllers/dto/VaccinationProcessDTO.h"

class VaccinationProcessRepository;
class WaitingRoomRepository;
class RecoveryRoomRepository;

class VaccinationProcessService {
private:
    std::shared_ptr<VaccinationProcessRepository> vaccinationProcessRepository;
    std::shared_ptr<WaitingRoomRepository> waitingRoomRepository;
    std::shared_ptr<RecoveryRoomRepository> recoveryRoomRepository;

public:
    VaccinationProcessService(std::shared_ptr<VaccinationProcessRepository> vaccinationProcessRepository,
                              std::shared_ptr<WaitingRoomRepository> waitingRoomRepository,
                              std::shared_ptr<RecoveryRoomRepository> recoveryRoomRepository);

    /**
     * Records a vaccination by removing the SNS user from the waiting room,
     * creating and persisting a VaccinationProcess record and assigning
     * the user to the recovery room.  Returns a Result describing the
     * outcome of the operation.
     */
    Result recordVaccination(const VaccinationProcessDTO &dto);
};

#endif // LETI_ESOFT_25_26_B1_VACCINATIONPROCESSSERVICE_H