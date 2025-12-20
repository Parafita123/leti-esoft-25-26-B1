//
// Created by Filipe on 12/12/2025.
//

#include "headers/domain/services/VaccinationCenterService.h"
#include "headers/domain/model/HealthcareCenter.h"
#include "headers/domain/model/CommunityMassVaccinationCenter.h"

namespace {
    // Simple in-memory ID generator
    int nextFacilityId() {
        static int nextId = 1;
        return nextId++;
    }
}

VaccinationCenterService::VaccinationCenterService(
        std::shared_ptr<VaccinationCenterRepository> ctrRepo,
        std::shared_ptr<VaccineTypeRepository> vtRepo
) : centerRepo(std::move(ctrRepo)), vaccineTypeRepo(std::move(vtRepo)) {}

std::vector<std::shared_ptr<VaccineType>> VaccinationCenterService::listVaccineTypes() {
    return vaccineTypeRepo->findAll();
}

Result VaccinationCenterService::registerCenter(const VaccinationCenterDTO& dto) {
    // basic validations
    if (dto.name.empty()) return Result::NOK(L"Name cannot be empty.");
    if (dto.max_vaccines_per_hour <= 0) return Result::NOK(L"max_vaccines_per_hour must be > 0.");

    const int facilityID = nextFacilityId();

    if (dto.facilityType == FacilityType::HEALTHCARE) {
        auto center = std::make_shared<HealthcareCenter>(
                facilityID,
                dto.name,
                dto.postal_address,
                dto.phone_number,
                dto.email,
                dto.website_address,
                dto.opening_hours,
                dto.closing_hours,
                dto.max_vaccines_per_hour
        );
        return centerRepo->save(center);
    }

    // COMMUNITY
    if (dto.vaccineTypeCode.empty()) {
        return Result::NOK(L"Community centers must include a vaccine type (AC13-3).");
    }

    auto vt = vaccineTypeRepo->findByCode(dto.vaccineTypeCode);
    if (!vt) return Result::NOK(L"Selected vaccine type does not exist.");

    auto center = std::make_shared<CommunityMassVaccinationCenter>(
            facilityID,
            dto.name,
            dto.postal_address,
            dto.phone_number,
            dto.email,
            dto.website_address,
            dto.opening_hours,
            dto.closing_hours,
            dto.max_vaccines_per_hour,
            vt
    );
    return centerRepo->save(center);
}
