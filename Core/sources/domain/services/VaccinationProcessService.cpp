// created by Guta on 2025-12-20
//
// Implementation of VaccinationProcessService.

#include "headers/domain/services/VaccinationProcessService.h"

#include "headers/domain/repositories/VaccinationProcessRepository.h"
#include "headers/domain/repositories/WaitingRoomRepository.h"
#include "headers/domain/repositories/RecoveryRoomRepository.h"
#include "headers/domain/model/VaccinationProcess.h"
#include <chrono>
#include <ctime>
#include <sstream>

VaccinationProcessService::VaccinationProcessService(
        std::shared_ptr<VaccinationProcessRepository> vaccinationProcessRepository,
        std::shared_ptr<WaitingRoomRepository> waitingRoomRepository,
        std::shared_ptr<RecoveryRoomRepository> recoveryRoomRepository)
        : vaccinationProcessRepository(std::move(vaccinationProcessRepository)),
          waitingRoomRepository(std::move(waitingRoomRepository)),
          recoveryRoomRepository(std::move(recoveryRoomRepository)) {}

// Helper to obtain current date/time in ISO 8601 format.
static std::string currentDateTimeISO() {
    using namespace std::chrono;
    auto now     = system_clock::now();
    auto now_time_t = system_clock::to_time_t(now);
    std::tm tm{};
    // Use localtime_r when available
#ifdef _WIN32
    localtime_s(&tm, &now_time_t);
#else
    localtime_r(&now_time_t, &tm);
#endif
    char buffer[20];
    // Format as YYYY-MM-DD HH:MM:SS
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &tm);
    return std::string(buffer);
}

Result VaccinationProcessService::recordVaccination(const VaccinationProcessDTO &dto) {
    // Validate input fields
    if (dto.snsUserNumber.empty() || dto.vaccineCode.empty() || dto.lotNumber.empty()) {
        return Result::NOK(L"All fields must be provided.");
    }

    // Remove from waiting room
    auto removeResult = waitingRoomRepository->removeSNSUser(dto.snsUserNumber);
    if (!removeResult.isOK()) {
        return removeResult;
    }

    // Create vaccination process record with current date/time
    auto process = std::make_shared<VaccinationProcess>(
            dto.snsUserNumber,
            dto.vaccineCode,
            dto.lotNumber,
            currentDateTimeISO());

    // Persist record
    auto saveResult = vaccinationProcessRepository->save(process);
    if (!saveResult.isOK()) {
        return saveResult;
    }

    // Assign to recovery room
    auto assignResult = recoveryRoomRepository->assignSNSUser(dto.snsUserNumber);
    if (!assignResult.isOK()) {
        return assignResult;
    }

    return Result::OK();
}