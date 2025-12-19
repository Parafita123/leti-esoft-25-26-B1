//
// Created by Guta on 19/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_VACCINATIONPROCESSSERVICE_H
#define LETI_ESOFT_25_26_B1_VACCINATIONPROCESSSERVICE_H

#include <memory>
#include "headers/domain/repositories/VaccinationProcessRepository.h"
#include "headers/domain/repositories/WaitingRoomRepository.h"
#include "headers/domain/repositories/RecoveryRoomRepository.h"
#include "headers/domain/model/VaccinationProcess.h"
#include "headers/domain/shared/Result.h"

/**
 * Service responsible for coordinating the recording of a vaccination
 * process.  It encapsulates the business logic for removing the
 * patient from the waiting room, creating a vaccination process
 * record, persisting it and assigning the user to the recovery room.
 */
class VaccinationProcessService {
private:
    std::shared_ptr<VaccinationProcessRepository> processRepo;
    std::shared_ptr<WaitingRoomRepository> waitingRepo;
    std::shared_ptr<RecoveryRoomRepository> recoveryRepo;

public:
    VaccinationProcessService(std::shared_ptr<VaccinationProcessRepository> processRepo,
                              std::shared_ptr<WaitingRoomRepository> waitingRepo,
                              std::shared_ptr<RecoveryRoomRepository> recoveryRepo);

    /**
     * Removes the SNS user from the waiting room.  If the user is not
     * found in the waiting room, the method does nothing.  This
     * operation has no return value because the caller cannot change
     * course based on the result; it always proceeds to record the
     * vaccination.
     */
    void removeFromWaitingRoom(const std::string &snsUserNumber);

    /**
     * Creates a VaccinationProcess domain object from the provided
     * details.  Does not persist the object.
     */
    VaccinationProcess createVaccinationProcess(const std::string &snsUserNumber,
                                                const std::string &vaccineCode,
                                                const std::string &lotNumber,
                                                const std::string &nurseId = "");

    /**
     * Persists the given vaccination process using the repository.
     */
    Result addOrUpdate(const VaccinationProcess &process);

    /**
     * Assigns the SNS user to the recovery room.  If the user is
     * already assigned, the method returns false.  Otherwise the user
     * is added to the recovery room and the method returns true.
     */
    bool assignToRecoveryRoom(const std::string &snsUserNumber);
};

#endif // LETI_ESOFT_25_26_B1_VACCINATIONPROCESSSERVICE_H
