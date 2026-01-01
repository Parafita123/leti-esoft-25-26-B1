//
// Created by diogo on 01/01/2026.
//

#ifndef LETI_ESOFT_25_26_B1_VACCINEMEMORYREPOSITORY_H
#define LETI_ESOFT_25_26_B1_VACCINEMEMORYREPOSITORY_H


#include "headers/domain/repositories/VaccineRepository.h"
#include "headers/domain/model/VaccineContainer.h"

/**
 * In-memory implementation of VaccineRepository.
 */
class VaccineMemoryRepository : public VaccineRepository {
private:
    VaccineContainer& container;

public:
    explicit VaccineMemoryRepository(VaccineContainer& container);

    std::vector<Vaccine> findAll() const override;
};



#endif //LETI_ESOFT_25_26_B1_VACCINEMEMORYREPOSITORY_H
