// created by Guta on 2025-12-21
//
// Mock class for VaccinationProcessRepository using Google Mock. This
// allows unit tests to verify interactions with the repository
// interface defined for recording vaccination processes. The mock
// returns Result values according to test expectations.

#ifndef LETI_ESOFT_25_26_B1_VACCINATIONPROCESSREPOSITORYMOCK_H
#define LETI_ESOFT_25_26_B1_VACCINATIONPROCESSREPOSITORYMOCK_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <headers/domain/repositories/VaccinationProcessRepository.h>

class VaccinationProcessRepositoryMock : public VaccinationProcessRepository {
public:
    MOCK_METHOD(Result, save, (const std::shared_ptr<VaccinationProcess>& process), (override));
};

#endif // LETI_ESOFT_25_26_B1_VACCINATIONPROCESSREPOSITORYMOCK_H