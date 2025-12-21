// created by Guta on 2025-12-20
//
// Implementation of the in-memory vaccination process repository.

#include "headers/infrastructure/memory/VaccinationProcessMemoryRepository.h"

Result VaccinationProcessMemoryRepository::save(const std::shared_ptr<VaccinationProcess> &process) {
    // Simply push the process into the vector.  No further validation
    // occurs here; validation is performed at the service layer.
    processes.push_back(process);
    return Result::OK();
}