//
// Created by diogo on 01/01/2026.
//

#ifndef LETI_ESOFT_25_26_B1_VACCINEREPOSITORY_H
#define LETI_ESOFT_25_26_B1_VACCINEREPOSITORY_H
#include <vector>
#include "headers/domain/model/Vaccine.h"

/**
 * Repository interface for Vaccine entities.
 * Allows the application layer to retrieve persisted vaccines
 * independently of the persistence mechanism.
 */
class VaccineRepository {
public:
    virtual ~VaccineRepository() = default;

    /**
     * Returns all registered vaccines.
     */
    virtual std::vector<Vaccine> findAll() const = 0;
};
#endif //LETI_ESOFT_25_26_B1_VACCINEREPOSITORY_H
