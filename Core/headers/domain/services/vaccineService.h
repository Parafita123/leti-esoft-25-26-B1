#ifndef VACCINESERVICE_H
#define VACCINESERVICE_H

#include "headers/domain/model/VaccineContainer.h"
#include <vector>

class VaccineService {
private:
    const VaccineContainer& repo;

public:
    explicit VaccineService(const VaccineContainer& repo);

    std::vector<Vaccine> getAllVaccines() const;
};

#endif
