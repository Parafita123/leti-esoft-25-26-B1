//
// Created by Filipe on 10/01/2026.
//

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <cctype>

#include <headers/domain/services/UserArrivalService.h>
#include <headers/controllers/dto/UserArrivalDTO.h>

#include <headers/domain/repositories/RepositoryFactory.h>
#include <headers/domain/repositories/UserArrivalRepository.h>
#include <headers/domain/repositories/SNSUserRepository.h>
#include <headers/domain/repositories/VaccinationCenterRepository.h>
#include <headers/domain/repositories/VaccinationAppointmentRepository.h>

// Domain models
#include <headers/domain/model/SNSUser.h>
#include <headers/domain/model/Facility.h>

#include <headers/domain/shared/Result.h>

// ✅ Use the complete mock implementation (existsForDay + save + findAll)
#include "../repositories/VaccinationAppointmentRepositoryMock.h"

using ::testing::_;
using ::testing::Return;
using ::testing::Truly;

// -------------------- Mocks --------------------

class UserArrivalRepositoryMock : public UserArrivalRepository {
public:
    MOCK_METHOD(Result, save, (std::shared_ptr<UserArrival> obj), (override));
    MOCK_METHOD(bool, exists,
                (const std::string& snsUserNumber, int facilityID, const std::string& day),
                (override));
    MOCK_METHOD(std::vector<std::shared_ptr<UserArrival>>, findAll, (), (override));
};

class SNSUserRepositoryMock : public SNSUserRepository {
public:
    MOCK_METHOD(Result, save, (std::shared_ptr<SNSUser> user), (override));
    MOCK_METHOD(std::list<std::shared_ptr<SNSUser>>, getAll, (), (override));
    MOCK_METHOD(std::optional<std::shared_ptr<SNSUser>>, getByPhoneNumber, (const std::string& phone), (override));
    MOCK_METHOD(std::optional<std::shared_ptr<SNSUser>>, getByEmail, (const std::string& email), (override));
    MOCK_METHOD(std::optional<std::shared_ptr<SNSUser>>, getByCitizenCardNumber, (const std::string& cc), (override));
    MOCK_METHOD(std::optional<std::shared_ptr<SNSUser>>, getBySNSUserNumber, (const std::string& sns), (override));
};

class VaccinationCenterRepositoryMock : public VaccinationCenterRepository {
public:
    MOCK_METHOD(Result, save, (std::shared_ptr<Facility> obj), (override));
    MOCK_METHOD(std::vector<std::shared_ptr<Facility>>, findAll, (), (override));
    MOCK_METHOD(std::optional<std::shared_ptr<Facility>>, findById, (int facilityID), (override));
};

class RepositoryFactoryMock : public RepositoryFactory {
public:
    MOCK_METHOD(std::shared_ptr<SNSUserRepository>, getSNSUserRepository, (), (override));
    MOCK_METHOD(std::shared_ptr<VaccinationCenterRepository>, getVaccinationCenterRepository, (), (override));
    MOCK_METHOD(std::shared_ptr<VaccineTypeRepository>, getVaccineTypeRepository, (), (override));
    MOCK_METHOD(std::shared_ptr<VaccinationAppointmentRepository>, getVaccinationAppointmentRepository, (), (override));
    MOCK_METHOD(std::shared_ptr<UserArrivalRepository>, getUserArrivalRepository, (), (override));
    MOCK_METHOD(std::shared_ptr<VaccineRepository>, getVaccineRepository, (), (override));
    MOCK_METHOD(std::shared_ptr<VaccinationProcessRepository>, getVaccinationProcessRepository, (), (override));
    MOCK_METHOD(std::shared_ptr<WaitingRoomRepository>, getWaitingRoomRepository, (), (override));
    MOCK_METHOD(std::shared_ptr<RecoveryRoomRepository>, getRecoveryRoomRepository, (), (override));
};

// -------------------- Fixture --------------------

class UserArrivalServiceFixture : public ::testing::Test {
protected:
    std::shared_ptr<RepositoryFactoryMock> repoFactory;

    std::shared_ptr<VaccinationAppointmentRepositoryMock> apptRepo;
    std::shared_ptr<UserArrivalRepositoryMock> arrivalRepo;
    std::shared_ptr<SNSUserRepositoryMock> userRepo;
    std::shared_ptr<VaccinationCenterRepositoryMock> centerRepo;

    std::shared_ptr<UserArrivalService> service;

    void SetUp() override {
        repoFactory = std::make_shared<RepositoryFactoryMock>();
        apptRepo = std::make_shared<VaccinationAppointmentRepositoryMock>();
        arrivalRepo = std::make_shared<UserArrivalRepositoryMock>();
        userRepo = std::make_shared<SNSUserRepositoryMock>();
        centerRepo = std::make_shared<VaccinationCenterRepositoryMock>();

        EXPECT_CALL(*repoFactory, getVaccinationAppointmentRepository())
                .WillRepeatedly(Return(apptRepo));
        EXPECT_CALL(*repoFactory, getUserArrivalRepository())
                .WillRepeatedly(Return(arrivalRepo));
        EXPECT_CALL(*repoFactory, getSNSUserRepository())
                .WillRepeatedly(Return(userRepo));
        EXPECT_CALL(*repoFactory, getVaccinationCenterRepository())
                .WillRepeatedly(Return(centerRepo));

        service = std::make_shared<UserArrivalService>(repoFactory);
    }

    static bool LooksLikeYYYYMMDD(const std::string& s) {
        if (s.size() != 10) return false;
        return (std::isdigit((unsigned char)s[0]) && std::isdigit((unsigned char)s[1]) &&
                std::isdigit((unsigned char)s[2]) && std::isdigit((unsigned char)s[3]) &&
                s[4] == '-' &&
                std::isdigit((unsigned char)s[5]) && std::isdigit((unsigned char)s[6]) &&
                s[7] == '-' &&
                std::isdigit((unsigned char)s[8]) && std::isdigit((unsigned char)s[9]));
    }
};

// -------------------- Tests --------------------

TEST_F(UserArrivalServiceFixture, RegisterArrival_NoAppointment_ShouldFail_AndNotProceed) {
    UserArrivalDTO dto{1, 123};
    const std::string sns = std::to_string(dto.sns_user_number);

    EXPECT_CALL(*apptRepo, existsForDay(sns, dto.facilityID, _))
            .Times(1)
            .WillOnce(Return(false));

    EXPECT_CALL(*arrivalRepo, exists(_, _, _)).Times(0);
    EXPECT_CALL(*userRepo, getBySNSUserNumber(_)).Times(0);
    EXPECT_CALL(*centerRepo, findById(_)).Times(0);
    EXPECT_CALL(*arrivalRepo, save(_)).Times(0);

    Result res = service->registerArrival(dto);
    EXPECT_TRUE(res.isNOK());
}

TEST_F(UserArrivalServiceFixture, RegisterArrival_DuplicateArrival_ShouldFail_AndNotSave) {
    UserArrivalDTO dto{1, 123};
    const std::string sns = std::to_string(dto.sns_user_number);

    EXPECT_CALL(*apptRepo, existsForDay(sns, dto.facilityID, _))
            .Times(1)
            .WillOnce(Return(true));

    EXPECT_CALL(*arrivalRepo, exists(sns, dto.facilityID, _))
            .Times(1)
            .WillOnce(Return(true));

    EXPECT_CALL(*userRepo, getBySNSUserNumber(_)).Times(0);
    EXPECT_CALL(*centerRepo, findById(_)).Times(0);
    EXPECT_CALL(*arrivalRepo, save(_)).Times(0);

    Result res = service->registerArrival(dto);
    EXPECT_TRUE(res.isNOK());
}

TEST_F(UserArrivalServiceFixture, RegisterArrival_UserNotFound_EmptyOptional_ShouldFail) {
    UserArrivalDTO dto{1, 123};
    const std::string sns = std::to_string(dto.sns_user_number);

    EXPECT_CALL(*apptRepo, existsForDay(sns, dto.facilityID, _))
            .WillOnce(Return(true));
    EXPECT_CALL(*arrivalRepo, exists(sns, dto.facilityID, _))
            .WillOnce(Return(false));

    EXPECT_CALL(*userRepo, getBySNSUserNumber(sns))
            .WillOnce(Return(std::optional<std::shared_ptr<SNSUser>>{}));

    EXPECT_CALL(*centerRepo, findById(_)).Times(0);
    EXPECT_CALL(*arrivalRepo, save(_)).Times(0);

    Result res = service->registerArrival(dto);
    EXPECT_TRUE(res.isNOK());
}

TEST_F(UserArrivalServiceFixture, RegisterArrival_FacilityNotFound_EmptyOptional_ShouldFail) {
    UserArrivalDTO dto{1, 123};
    const std::string sns = std::to_string(dto.sns_user_number);

    EXPECT_CALL(*apptRepo, existsForDay(sns, dto.facilityID, _))
            .WillOnce(Return(true));
    EXPECT_CALL(*arrivalRepo, exists(sns, dto.facilityID, _))
            .WillOnce(Return(false));

    auto user = std::make_shared<SNSUser>(
            "Ana Silva", "2000-01-01", "F", "Rua X", "912345678",
            "ana@teste.pt", "12345678", sns
    );
    EXPECT_CALL(*userRepo, getBySNSUserNumber(sns))
            .WillOnce(Return(std::optional<std::shared_ptr<SNSUser>>(user)));

    EXPECT_CALL(*centerRepo, findById(dto.facilityID))
            .WillOnce(Return(std::optional<std::shared_ptr<Facility>>{}));

    EXPECT_CALL(*arrivalRepo, save(_)).Times(0);

    Result res = service->registerArrival(dto);
    EXPECT_TRUE(res.isNOK());
}

TEST_F(UserArrivalServiceFixture, RegisterArrival_SaveReturnsNOK_ShouldPropagate) {
    UserArrivalDTO dto{1, 123};
    const std::string sns = std::to_string(dto.sns_user_number);

    EXPECT_CALL(*apptRepo, existsForDay(sns, dto.facilityID, _))
            .WillOnce(Return(true));
    EXPECT_CALL(*arrivalRepo, exists(sns, dto.facilityID, _))
            .WillOnce(Return(false));

    auto user = std::make_shared<SNSUser>(
            "Ana Silva", "2000-01-01", "F", "Rua X", "912345678",
            "ana@teste.pt", "12345678", sns
    );
    EXPECT_CALL(*userRepo, getBySNSUserNumber(sns))
            .WillOnce(Return(std::optional<std::shared_ptr<SNSUser>>(user)));

    auto facility = std::make_shared<Facility>(
            dto.facilityID, "HC Test", "Street X", "912345678",
            "hc@test.pt", "https://hc.pt", "08:00", "20:00", 40
    );
    EXPECT_CALL(*centerRepo, findById(dto.facilityID))
            .WillOnce(Return(std::optional<std::shared_ptr<Facility>>(facility)));

    EXPECT_CALL(*arrivalRepo, save(_))
            .Times(1)
            .WillOnce(Return(Result::NOK(L"save failed")));

    Result res = service->registerArrival(dto);
    EXPECT_TRUE(res.isNOK());
}

TEST_F(UserArrivalServiceFixture, RegisterArrival_ShouldUseDateInYYYYMMDDFormat) {
    UserArrivalDTO dto{1, 123};
    const std::string sns = std::to_string(dto.sns_user_number);

    EXPECT_CALL(*apptRepo, existsForDay(sns, dto.facilityID,
                                        Truly([](const std::string& day) { return LooksLikeYYYYMMDD(day); })))
            .WillOnce(Return(false));

    Result res = service->registerArrival(dto);
    EXPECT_TRUE(res.isNOK());
}

TEST_F(UserArrivalServiceFixture, RegisterArrivalSuccessful) {
    UserArrivalDTO dto{1, 123};
    const std::string sns = std::to_string(dto.sns_user_number);

    EXPECT_CALL(*apptRepo, existsForDay(sns, dto.facilityID, _))
            .Times(1)
            .WillOnce(Return(true));

    EXPECT_CALL(*arrivalRepo, exists(sns, dto.facilityID, _))
            .Times(1)
            .WillOnce(Return(false));

    auto user = std::make_shared<SNSUser>(
            "Ana Silva", "2000-01-01", "F", "Rua X, Porto", "912345678",
            "ana@teste.pt", "12345678", sns
    );
    EXPECT_CALL(*userRepo, getBySNSUserNumber(sns))
            .Times(1)
            .WillOnce(Return(std::optional<std::shared_ptr<SNSUser>>(user)));

    auto facility = std::make_shared<Facility>(
            dto.facilityID, "HC Test", "Street X", "912345678",
            "hc@test.pt", "https://hc.pt", "08:00", "20:00", 40
    );
    EXPECT_CALL(*centerRepo, findById(dto.facilityID))
            .Times(1)
            .WillOnce(Return(std::optional<std::shared_ptr<Facility>>(facility)));

    EXPECT_CALL(*arrivalRepo, save(_))
            .Times(1)
            .WillOnce(Return(Result::OK()));

    Result res = service->registerArrival(dto);
    EXPECT_TRUE(res.isOK());
}
