//
// Created by Guta on 2026-01-04.
//

#include "headers/controllers/restapi/VaccineController.h"

#include <stdexcept>
#include "headers/domain/shared/StringUtils.h"
#include "headers/domain/model/VaccineTechnology.h"
#include "headers/controllers/restapi/SharedRepositoryFactory.h"

using json::JSON;

/**
 * Static definitions for the shared repository factory and the
 * in‑memory vaccine storage.  These must be defined in a single
 * translation unit to avoid duplicate symbols at link time.
 */
std::shared_ptr<RepositoryFactory> VaccineController::sharedFactory = nullptr;
std::vector<Vaccine> VaccineController::vaccines;

VaccineController::VaccineController(const std::wstring &bearerToken) : token(bearerToken) {
    // Validate the bearer token.  The API requires a non‑empty token
    // for all requests, mirroring the behaviour in VaccineTypeController.
    if (bearerToken.empty()) {
        throw std::invalid_argument("Missing bearer token");
    }
    // Lazily initialize the shared factory.  This ensures that
    // repositories exist even if multiple controllers are created.
    if (!sharedFactory) {
        sharedFactory = getSharedRepositoryFactory();
    }
}

HttpResult VaccineController::getAll() {
    HttpResult result(HttpStatus::HTTP_OK);

    // Build a JSON array containing all persisted vaccines.  Each
    // vaccine is converted into a JSON object with its key
    // attributes.  Optional fields are only included when present.
    JSON jsonArr = JSON::Make(JSON::Class::Array);
    for (const auto &v : vaccines) {
        JSON obj = json::Object();
        obj["commercialName"] = v.getCommercialName();
        obj["brand"] = v.getBrand();
        obj["typeCode"] = v.getTypeCode();
        obj["technology"] = VaccineTechnologyUtils::toString(v.getTechnology());
        obj["lot"] = v.getLot();
        // Expiration date is optional; include only if defined.
        if (v.getExpirationDate().has_value()) {
            obj["expirationDate"] = v.getExpirationDate().value();
        }
        jsonArr.append(obj);
    }

    result.setJsonResult(jsonArr);
    return result;
}

HttpResult VaccineController::postVaccine(const std::string &commercialName,
                                          const std::string &brand,
                                          const std::string &typeCode,
                                          const std::string &technologyStr,
                                          const std::string &lot,
                                          const std::string &expirationDate) {
    HttpResult result;

    // Validate mandatory fields.  All are required except lot and
    // expirationDate; empty values result in a 400 response.
    if (commercialName.empty() || brand.empty() || typeCode.empty() || technologyStr.empty()) {
        result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST);
        result.setMessage("Invalid data: commercialName, brand, typeCode and technology are required.");
        return result;
    }

    // Parse the technology string to the enumeration.  The parser
    // performs a case‑insensitive match against the allowed list.
    auto techOpt = VaccineTechnologyUtils::parse(technologyStr);
    if (!techOpt.has_value()) {
        result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST);
        result.setMessage("Invalid vaccine technology.");
        return result;
    }
    if (!sharedFactory) {
        sharedFactory = getSharedRepositoryFactory();
    }

    // Validate the vaccine type code exists.  The VaccineType
    // repository is obtained from the shared factory.  If the type
    // does not exist, return a 400 error.
    auto typeRepo = sharedFactory->getVaccineTypeRepository();
    if (!typeRepo->exists(typeCode)) {
        result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST);
        result.setMessage("Vaccine type code does not exist.");
        return result;
    }

    // Create a new vaccine instance.  The expiration date is
    // optionally wrapped into a std::optional if provided; an
    // empty string indicates absence.
    std::optional<std::string> expiry = std::nullopt;
    if (!expirationDate.empty()) {
        expiry = expirationDate;
    }
    Vaccine v(commercialName, brand, typeCode, techOpt.value(), lot, expiry);

    // Persist the vaccine in memory by adding to the static
    // container.  No duplicates check is performed, but this could
    // be added later if needed.
    vaccines.push_back(v);

    // Return a success response.  Status 200 is used to align with
    // existing VaccineType API responses.
    result.setHttpStatus(HttpStatus::HTTP_OK);
    result.setMessage("Vaccine created successfully.");
    return result;
}