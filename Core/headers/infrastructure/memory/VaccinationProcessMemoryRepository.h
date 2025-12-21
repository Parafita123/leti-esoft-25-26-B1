// created by Guta on 2025-12-20
//
// In-memory implementation of the VaccinationProcessRepository.  Uses a
// simple vector to store vaccination records for the lifetime of the
// application.

#ifndef LETI_ESOFT_25_26_B1_VACCINATIONPROCESSMEMORYREPOSITORY_H
#define LETI_ESOFT_25_26_B1_VACCINATIONPROCESSMEMORYREPOSITORY_H

#include <vector>
#include <memory>
#include "headers/domain/repositories/VaccinationProcessRepository.h"
#include "headers/domain/model/VaccinationProcess.h"

class VaccinationProcessMemoryRepository : public VaccinationProcessRepository {
private:
    std::vector<std::shared_ptr<VaccinationProcess>> processes;
public:
    Result save(const std::shared_ptr<VaccinationProcess> &process) override;
};

#endif // LETI_ESOFT_25_26_B1_VACCINATIONPROCESSMEMORYREPOSITORY_H