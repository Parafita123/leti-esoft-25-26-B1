//
// Created by Guta on 18/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_VACCINATIONPROCESSREPOSITORY_H
#define LETI_ESOFT_25_26_B1_VACCINATIONPROCESSREPOSITORY_H

#include <memory>
#include <vector>
#include <optional>
#include "headers/domain/model/VaccinationProcess.h"
#include "headers/domain/shared/Result.h"

/**
 * Interface defining the persistence operations for VaccinationProcess
 * domain objects.  Concrete implementations can use in‑memory, file
 * or database storage.  Only the operations required by US41 are
 * declared here.
 */
class VaccinationProcessRepository {
public:
    virtual ~VaccinationProcessRepository() = default;

    /**
     * Persists a vaccination process.  Returns a Result indicating
     * success or failure.  Concrete implementations may enforce
     * additional validation rules (e.g. no duplicate processes on the same day).
     */
    virtual Result save(const VaccinationProcess &process) = 0;

    /**
     * Returns all stored vaccination processes.
     */
    virtual std::vector<VaccinationProcess> findAll() = 0;

    /**
     * Returns an optional vaccination process recorded for a given
     * SNS user on a given date.  This can be used to prevent
     * duplicate registrations on the same day.
     */
    virtual std::optional<VaccinationProcess> findBySNSUserAndDate(const std::string &snsUserNumber,
                                                                   const std::string &date) = 0;
};

#endif // LETI_ESOFT_25_26_B1_VACCINATIONPROCESSREPOSITORY_H