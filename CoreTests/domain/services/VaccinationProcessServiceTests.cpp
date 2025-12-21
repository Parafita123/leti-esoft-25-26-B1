// created by Guta on 2025-12-21
//
// Unit tests for VaccinationProcessService. These tests verify that
// the service correctly orchestrates the removal from the waiting room,
// persistence of the vaccination process and assignment to the
// recovery room. They also verify that the service validates input
// fields and propagates error results from the underlying
// repositories.

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <headers/domain/services/VaccinationProcessService.h>
#include <headers/controllers/dto/VaccinationProcessDTO.h>
#include <headers/domain/model/VaccinationProcess.h>
#include "../repositories/VaccinationProcessRepositoryMock.h"
#include "../repositories/WaitingRoomRepositoryMock.h"
#include "../repositories/RecoveryRoomRepositoryMock.h"

using ::testing::Return;
using ::testing::_;

class VaccinationProcessServiceFixture : public ::testing::Test {
protected:
    std::shared_ptr<VaccinationProcessRepositoryMock> vpRepo;
    std::shared_ptr<WaitingRoomRepositoryMock> wrRepo;
    std::shared_ptr<RecoveryRoomRepositoryMock> rrRepo;
    std::shared_ptr<VaccinationProcessService> service;

    void SetUp() override {
        vpRepo = std::make_shared<VaccinationProcessRepositoryMock>();
        wrRepo = std::make_shared<WaitingRoomRepositoryMock>();
        rrRepo = std::make_shared<RecoveryRoomRepositoryMock>();
        service = std::make_shared<VaccinationProcessService>(vpRepo, wrRepo, rrRepo);
    }
};

TEST_F(VaccinationProcessServiceFixture, RecordVaccinationWithEmptyFieldsShouldFail) {
    VaccinationProcessDTO dto{"", "", ""};
    Result res = service->recordVaccination(dto);
    EXPECT_TRUE(res.isNOK());
}

TEST_F(VaccinationProcessServiceFixture, RemovalFromWaitingRoomFails) {
    VaccinationProcessDTO dto{"123", "VAC01", "LOT01"};
    EXPECT_CALL(*wrRepo, removeSNSUser(dto.snsUserNumber))
            .Times(1)
            .WillOnce(Return(Result::NOK(L"user not found")));
    // vpRepo and rrRepo should not be called when waiting room fails
    EXPECT_CALL(*vpRepo, save(_)).Times(0);
    EXPECT_CALL(*rrRepo, assignSNSUser(_)).Times(0);
    Result res = service->recordVaccination(dto);
    EXPECT_TRUE(res.isNOK());
}

TEST_F(VaccinationProcessServiceFixture, PersistVaccinationFails) {
    VaccinationProcessDTO dto{"123", "VAC01", "LOT01"};
    EXPECT_CALL(*wrRepo, removeSNSUser(dto.snsUserNumber))
            .Times(1)
            .WillOnce(Return(Result::OK()));
    EXPECT_CALL(*vpRepo, save(_))
            .Times(1)
            .WillOnce(Return(Result::NOK(L"save error")));
    // recovery room should not be called
    EXPECT_CALL(*rrRepo, assignSNSUser(_)).Times(0);
    Result res = service->recordVaccination(dto);
    EXPECT_TRUE(res.isNOK());
}

TEST_F(VaccinationProcessServiceFixture, AssignToRecoveryRoomFails) {
    VaccinationProcessDTO dto{"123", "VAC01", "LOT01"};
    EXPECT_CALL(*wrRepo, removeSNSUser(dto.snsUserNumber))
            .Times(1)
            .WillOnce(Return(Result::OK()));
    EXPECT_CALL(*vpRepo, save(_))
            .Times(1)
            .WillOnce(Return(Result::OK()));
    EXPECT_CALL(*rrRepo, assignSNSUser(dto.snsUserNumber))
            .Times(1)
            .WillOnce(Return(Result::NOK(L"recovery error")));
    Result res = service->recordVaccination(dto);
    EXPECT_TRUE(res.isNOK());
}

TEST_F(VaccinationProcessServiceFixture, SuccessfulVaccinationProcess) {
    VaccinationProcessDTO dto{"123", "VAC01", "LOT01"};
    EXPECT_CALL(*wrRepo, removeSNSUser(dto.snsUserNumber))
            .Times(1)
            .WillOnce(Return(Result::OK()));
    EXPECT_CALL(*vpRepo, save(_))
            .Times(1)
            .WillOnce(Return(Result::OK()));
    EXPECT_CALL(*rrRepo, assignSNSUser(dto.snsUserNumber))
            .Times(1)
            .WillOnce(Return(Result::OK()));
    Result res = service->recordVaccination(dto);
    EXPECT_TRUE(res.isOK());
}