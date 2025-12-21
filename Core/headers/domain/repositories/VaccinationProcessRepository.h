// created by Guta on 2025-12-20
//
// Interface definition for repositories capable of persisting vaccination
// process records.  Concrete implementations decide where the data is
// stored (e.g. in-memory or database) and how it is persisted.

#ifndef LETI_ESOFT_25_26_B1_VACCINATIONPROCESSREPOSITORY_H
#define LETI_ESOFT_25_26_B1_VACCINATIONPROCESSREPOSITORY_H

#include <memory>
#include "headers/domain/model/VaccinationProcess.h"
#include "headers/domain/shared/Result.h"

class VaccinationProcessRepository {
public:
    virtual ~VaccinationProcessRepository() = default;

    /**
     * Persists the given vaccination process.  On success a Result::ok()
     * should be returned; otherwise a failure Result describing the error.
     */
    virtual Result save(const std::shared_ptr<VaccinationProcess> &process) = 0;
};

#endif // LETI_ESOFT_25_26_B1_VACCINATIONPROCESSREPOSITORY_H