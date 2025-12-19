//
// Created by Guta on 18/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_VACCINATIONPROCESSMEMORYREPOSITORY_H
#define LETI_ESOFT_25_26_B1_VACCINATIONPROCESSMEMORYREPOSITORY_H

#include "headers/domain/repositories/VaccinationProcessRepository.h"
#include <list>

/**
 * In‑memory implementation of the VaccinationProcessRepository.
 * Stores vaccination processes in a std::list.  Duplicate
 * processes (same SNS user and same day) are rejected.
 */
class VaccinationProcessMemoryRepository : public VaccinationProcessRepository {
private:
    std::list<VaccinationProcess> data;

public:
    Result save(const VaccinationProcess &process) override;
    std::vector<VaccinationProcess> findAll() override;
    std::optional<VaccinationProcess> findBySNSUserAndDate(const std::string &snsUserNumber,
                                                           const std::string &date) override;
};

#endif // LETI_ESOFT_25_26_B1_VACCINATIONPROCESSMEMORYREPOSITORY_H