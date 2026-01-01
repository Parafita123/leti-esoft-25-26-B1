//
// Created by diogo on 01/01/2026.
//
#include "headers/domain/services/VaccineService.h"
#include <algorithm>

VaccineService::VaccineService(const VaccineContainer& repo)
        : repo(repo) {}

std::vector<Vaccine> VaccineService::getAllVaccines() const {
    std::vector<Vaccine> list = repo.getAll();

    // SD: sortByTypeThenBrand
    std::sort(list.begin(), list.end(),
              [](const Vaccine& a, const Vaccine& b) {
                  if (a.getTypeCode() != b.getTypeCode())
                      return a.getTypeCode() < b.getTypeCode();
                  return a.getBrand() < b.getBrand();
              });

    return list;
}
