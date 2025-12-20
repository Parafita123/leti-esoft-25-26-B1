//
// Created by Filipe on 20/12/2025.
//
#include "headers/controllers/ui/RegisterUserArrivalController.h"
#include "headers/controllers/ui/App.h"
#include "headers/domain/services/UserArrivalService.h"
#include "headers/domain/repositories/RepositoryFactory.h"
#include "headers/domain/repositories/VaccinationCenterRepository.h"
#include "headers/domain/repositories/SNSUserRepository.h"

RegisterUserArrivalController::RegisterUserArrivalController(App& app)
        : app(app), service(app.getUserArrivalService()) {}

std::vector<FacilityDto> RegisterUserArrivalController::listFacilities() {
    auto factory = app.getRepositoryFactory();
    auto repo = factory->getVaccinationCenterRepository();

    auto facilities = repo->findAll();

    std::vector<FacilityDto> out;
    out.reserve(facilities.size());

    for (auto& f : facilities) {
        if (!f) continue;

        FacilityDto dto;
        dto.facilityID = f->getFacilityID();
        dto.name = f->getName();
        out.push_back(dto);
    }
    return out;
}

std::optional<SNSUserDto> RegisterUserArrivalController::getSNSUserSummary(int snsNumber) {
    auto factory = app.getRepositoryFactory();
    auto repo = factory->getSNSUserRepository();

    const std::string sns = std::to_string(snsNumber);
    auto userOpt = repo->getBySNSUserNumber(sns);

    if (!userOpt.has_value() || !userOpt.value()) return std::nullopt;

    SNSUserDto dto;
    dto.name = userOpt.value()->getName();
    dto.snsUserNumber = userOpt.value()->getSNSUserNumber();
    return dto;
}

Result RegisterUserArrivalController::registerArrival(const UserArrivalDTO& dto) {
    return service->registerArrival(dto);
}

