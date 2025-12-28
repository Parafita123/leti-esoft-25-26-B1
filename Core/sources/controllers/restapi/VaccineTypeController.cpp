//
// Created by Filipe on 28/12/2025.
//
#include "headers/controllers/restapi/VaccineTypeController.h"

#include <stdexcept>
#include "headers/domain/model/VaccineType.h"
#include "headers/domain/shared/StringUtils.h"
#include "headers/infrastructure/memory/MemoryRepositoryFactory.h"
#include "headers/controllers/restapi/HttpStatus.h"

using json::JSON;

std::shared_ptr<RepositoryFactory> VaccineTypeController::sharedFactory = nullptr;

VaccineTypeController::VaccineTypeController(const std::wstring& bearerToken) {
    if (bearerToken.empty())
        throw std::invalid_argument("Missing bearer token");

    if (!sharedFactory) {
        sharedFactory = std::make_shared<MemoryRepositoryFactory>();
    }

    repo = sharedFactory->getVaccineTypeRepository();
}

HttpResult VaccineTypeController::getAll() {
    HttpResult result(HttpStatus::HTTP_OK);

    auto list = repo->findAll();
    JSON jsonArr = JSON::Make(JSON::Class::Array);

    for (const auto& vt : list) {
        if (!vt) continue;
        JSON obj = json::Object();
        obj["typeCode"] = vt->getTypeCode();
        obj["disease"] = vt->getDisease();
        obj["description"] = vt->getShortDescription();
        jsonArr.append(obj);
    }

    // ✅ agora é setJsonResult
    result.setJsonResult(jsonArr);
    return result;
}

HttpResult VaccineTypeController::postVaccineType(const std::string& code,
                                                  const std::string& disease,
                                                  const std::string& description) {
    HttpResult result;

    if (code.empty() || disease.empty() || description.empty()) {
        result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST);
        result.setMessage("Invalid data: typeCode, disease and description are required.");
        return result;
    }

    if (repo->exists(code)) {
        result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST);
        result.setMessage("VaccineType already exists.");
        return result;
    }

    auto vt = std::make_shared<VaccineType>(code, disease, description);
    Result r = repo->save(vt);

    if (r.isOK()) {
        // Podias usar 201, mas para ficar igual ao prof e ao teu HttpStatus, deixo 200
        result.setHttpStatus(HttpStatus::HTTP_OK);
        result.setMessage("VaccineType created successfully.");
    } else {
        result.setHttpStatus(HttpStatus::HTTP_SERVER_ERROR);
        result.setMessage(StringUtils::toString(r.getMessage()));
    }

    return result;
}
