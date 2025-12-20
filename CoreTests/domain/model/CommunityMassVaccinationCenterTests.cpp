//
// Created by Filipe on 18/12/2025.
//
/*
#include <gtest/gtest.h>
#include <memory>
#include <stdexcept>

#include "headers/domain/model/CommunityMassVaccinationCenter.h"
#include "headers/domain/model/VaccineType.h"

TEST(CommunityMassVaccinationCenterTests, CreateWithoutVaccineTypeThrows) {
EXPECT_THROW(
        CommunityMassVaccinationCenter(
        "Center A",
        "Street X",
        "912345678",
        "a@center.pt",
        "https://center.pt",
        "08:00",
        "20:00",
        50,
        nullptr
),
        std::invalid_argument
);
}

TEST(CommunityMassVaccinationCenterTests, CreateWithVaccineTypeSucceeds) {
auto vt = std::make_shared<VaccineType>("12345", "Malaria", "Effective vaccine type");

EXPECT_NO_THROW(
        CommunityMassVaccinationCenter(
        "Center B",
        "Street Y",
        "912345679",
        "b@center.pt",
        "https://center-b.pt",
        "08:00",
        "20:00",
        50,
        vt
)
);
}
*/