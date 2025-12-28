//
// Created by Filipe on 28/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_VACCINETYPECONTROLLER_H
#define LETI_ESOFT_25_26_B1_VACCINETYPECONTROLLER_H

#include "thirdparty/SimpleJson.hpp"
#include <headers/controllers/restapi/HttpResult.h>
#include <headers/domain/repositories/VaccineTypeRepository.h>
#include <headers/infrastructure/memory/MemoryRepositoryFactory.h>


#include <memory>
#include <string>
#include "thirdparty/SimpleJson.hpp"

#include "headers/controllers/restapi/HttpResult.h"
#include "headers/domain/repositories/VaccineTypeRepository.h"
#include "headers/domain/repositories/RepositoryFactory.h"

class VaccineTypeController {
private:
    std::shared_ptr<VaccineTypeRepository> repo;

    static std::shared_ptr<RepositoryFactory> sharedFactory;

public:
    explicit VaccineTypeController(const std::wstring& bearerToken);

    HttpResult getAll();
    HttpResult postVaccineType(const std::string& code,
                               const std::string& disease,
                               const std::string& description);
};

#endif //LETI_ESOFT_25_26_B1_VACCINETYPECONTROLLER_H
