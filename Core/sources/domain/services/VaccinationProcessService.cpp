//
// Created by Guta on 19/12/2025.
//
#include "../Core/headers/domain/shared/Result.h"

#include "headers/domain/services/VaccinationProcessService.h"

VaccinationProcessService::VaccinationProcessService(std::shared_ptr<VaccinationProcessRepository> processRepo,
                                                     std::shared_ptr<WaitingRoomRepository> waitingRepo,
                                                     std::shared_ptr<RecoveryRoomRepository> recoveryRepo)
        : processRepo(std::move(processRepo)), waitingRepo(std::move(waitingRepo)), recoveryRepo(std::move(recoveryRepo)) {}

void VaccinationProcessService::removeFromWaitingRoom(const std::string &snsUserNumber) {
    if (waitingRepo) {
        waitingRepo->removeSNSUser(snsUserNumber);
    }
}

VaccinationProcess VaccinationProcessService::createVaccinationProcess(const std::string &snsUserNumber,
                                                                      const std::string &vaccineCode,
                                                                      const std::string &lotNumber,
                                                                      const std::string &nurseId) {
    return VaccinationProcess(snsUserNumber, vaccineCode, lotNumber, nurseId);
}

Result VaccinationProcessService::addOrUpdate(const VaccinationProcess &process) {
    if (!processRepo) {
        return Result::NOK(L"Vaccination process repository not configured.");
    }

    return processRepo->save(process);
}

bool VaccinationProcessService::assignToRecoveryRoom(const std::string &snsUserNumber) {
    if (!recoveryRepo) return false;
    return recoveryRepo->assignSNSUser(snsUserNumber);
}
