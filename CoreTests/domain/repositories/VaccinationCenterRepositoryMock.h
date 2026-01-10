//
// Created by Filipe on 10/01/2026.
//

#ifndef LETI_ESOFT_25_26_B1_VACCINATIONCENTERREPOSITORYMOCK_H
#define LETI_ESOFT_25_26_B1_VACCINATIONCENTERREPOSITORYMOCK_H

#pragma once

#include "gmock/gmock.h"
#include <headers/domain/repositories/VaccinationCenterRepository.h>

class VaccinationCenterRepositoryMock : public VaccinationCenterRepository {
public:
    MOCK_METHOD(Result, save, (std::shared_ptr<Facility> obj), (override));
    MOCK_METHOD(std::vector<std::shared_ptr<Facility>>, findAll, (), (override));
    MOCK_METHOD(std::optional<std::shared_ptr<Facility>>, findById, (int facilityID), (override));
};

#endif //LETI_ESOFT_25_26_B1_VACCINATIONCENTERREPOSITORYMOCK_H
