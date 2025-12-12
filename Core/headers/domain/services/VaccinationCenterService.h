//
// Created by Filipe on 12/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_VACCINATIONCENTERSERVICE_H
#define LETI_ESOFT_25_26_B1_VACCINATIONCENTERSERVICE_H

#include <memory>
#include <vector>
#include "headers/controllers/dto/VaccinationCenterDTO.h"
#include "headers/domain/shared/Result.h"
#include "headers/domain/repositories/VaccinationCenterRepository.h"
#include "headers/domain/repositories/VaccineTypeRepository.h"

class VaccinationCenterService {
private:
    std::shared_ptr<VaccinationCenterRepository> centerRepo;
    std::shared_ptr<VaccineTypeRepository> vaccineTypeRepo;

public:
    VaccinationCenterService(std::shared_ptr<VaccinationCenterRepository> ctrRepo,
                             std::shared_ptr<VaccineTypeRepository> vtRepo);

    std::vector<std::shared_ptr<VaccineType>> listVaccineTypes();

    Result registerCenter(const VaccinationCenterDTO& dto);
};


#endif //LETI_ESOFT_25_26_B1_VACCINATIONCENTERSERVICE_H
