//
// Created by Filipe on 20/12/2025.
//
#include "headers/domain/services/UserArrivalService.h"

#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>

#include "headers/domain/repositories/RepositoryFactory.h"
#include "headers/domain/repositories/UserArrivalRepository.h"
#include "headers/domain/repositories/SNSUserRepository.h"
#include "headers/domain/repositories/VaccinationCenterRepository.h"
#include "headers/domain/repositories/VaccinationAppointmentRepository.h"

#include "headers/domain/model/UserArrival.h"

UserArrivalService::UserArrivalService(std::shared_ptr<RepositoryFactory> repoFactory)
        : repoFactory(std::move(repoFactory)) {}

std::string UserArrivalService::getTodayDate() const {
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::tm tm{};
#ifdef _WIN32
    localtime_s(&tm, &t);
#else
    localtime_r(&t, &tm);
#endif
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d");
    return oss.str();
}

Result UserArrivalService::registerArrival(const UserArrivalDTO& dto) {
    const std::string day = getTodayDate();
    const std::string sns = std::to_string(dto.sns_user_number);

    auto apptRepo = repoFactory->getVaccinationAppointmentRepository();
    auto arrivalRepo = repoFactory->getUserArrivalRepository();
    auto userRepo = repoFactory->getSNSUserRepository();
    auto facilityRepo = repoFactory->getVaccinationCenterRepository();

    // Dependency on US21 (prof answer): must have appointment today and for this center
    if (!apptRepo->existsForDay(sns, dto.facilityID, day)) {
        return Result::NOK(L"No appointment exists for this SNS user on this day and center.");
    }

    // AC22-1: no duplicate arrival same day & center
    if (arrivalRepo->exists(sns, dto.facilityID, day)) {
        return Result::NOK(L"Arrival already registered for this SNS user on this day and center.");
    }

    auto userOpt = userRepo->getBySNSUserNumber(sns);
    if (!userOpt.has_value() || !userOpt.value()) {
        return Result::NOK(L"SNS User not found.");
    }

    auto facOpt = facilityRepo->findById(dto.facilityID);
    if (!facOpt.has_value() || !facOpt.value()) {
        return Result::NOK(L"Facility not found.");
    }

    auto now = std::chrono::system_clock::now();
    auto arrival = std::make_shared<UserArrival>(now, userOpt.value(), facOpt.value());

    return arrivalRepo->save(arrival);
}

