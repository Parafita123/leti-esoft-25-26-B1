//
// Created by Filipe on 10/01/2026.
//

#include <gtest/gtest.h>
#include <memory>


#include "headers/domain/shared/Result.h"
#include "headers/domain/model/HealthcareCenter.h"
#include "headers/domain/model/CommunityMassVaccinationCenter.h"
#include "headers/infrastructure/memory/VaccinationCenterMemoryRepository.h"


#include "headers/domain/model/VaccineType.h"

// --------------------
// Fixture 1: model tests
// --------------------
class VaccinationCenterFixture : public ::testing::Test {
protected:
    std::shared_ptr<VaccineType> vaccineType;

    void SetUp() override {
        vaccineType = nullptr;
    }
};

// --------------------
// Fixture 2: repository tests
// --------------------
class VaccinationCenterMemoryRepositoryFixture : public ::testing::Test {
protected:
    std::unique_ptr<VaccinationCenterMemoryRepository> repo;

    void SetUp() override {
        repo = std::make_unique<VaccinationCenterMemoryRepository>();
    }
};

/**
 * Test 1:
 * Check that it is not possible to create a CommunityMassVaccinationCenter without an associated vaccine type (AC13-3).
 */
TEST_F(VaccinationCenterFixture, CreateCommunityCenterWithoutVaccineType) {
    // ⚠️ Ajusta os argumentos conforme o teu construtor.
    // Muitos projetos têm (id, name, address, phone, email, website, opening, closing, maxPerHour, vaccineType)
    EXPECT_THROW({
                     auto center = std::make_shared<CommunityMassVaccinationCenter>(
                             /* id */ 1,
                             /* name */ "Center A",
                             /* address */ "Street X",
                             /* phone */ "912345678",
                             /* email */ "a@center.pt",
                             /* website */ "https://center.pt",
                             /* opening */ "08:00",
                             /* closing */ "20:00",
                             /* maxPerHour */ 50,
                             /* vaccineType */ nullptr
                     );
                     (void)center;
                 }, std::invalid_argument);
}

/**
 * Test 2:
 * Check that it is possible to create a HealthcareCenter with valid data.
 */
TEST_F(VaccinationCenterFixture, CreateHealthcareCenterWithValidData) {
    // ⚠️ Ajusta os argumentos conforme o teu construtor.
    // Muitos projetos têm (id, name, address, phone, email, website, opening, closing, maxPerHour)
    EXPECT_NO_THROW({
                        auto hc = std::make_shared<HealthcareCenter>(
                                /* id */ 1,
                                         "Health Center 1",
                                         "Street Y",
                                         "912345678",
                                         "hc@center.pt",
                                         "https://hc.pt",
                                         "08:00",
                                         "20:00",
                                         40
                        );
                        (void)hc;
                    });
}

/**
 * Test 3:
 * Check that it is possible to register and save a vaccination center using VaccinationCenterMemoryRepository.
 */
TEST_F(VaccinationCenterMemoryRepositoryFixture, SaveOneVaccinationCenter) {
    ASSERT_TRUE(this->repo != nullptr);

    EXPECT_TRUE(this->repo->isEmpty());

    // ⚠️ Ajusta os argumentos conforme o teu construtor.
    auto center = std::make_shared<HealthcareCenter>(
            /* id */ 2,
                     "Health Center Repo",
                     "Street Z",
                     "912345678",
                     "repo@hc.pt",
                     "https://repo-hc.pt",
                     "08:00",
                     "20:00",
                     30
    );

    Result r = this->repo->save(center);

    EXPECT_TRUE(r.isOK());
    EXPECT_FALSE(this->repo->isEmpty());
}
