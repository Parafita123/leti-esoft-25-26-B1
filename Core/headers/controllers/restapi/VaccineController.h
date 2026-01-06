//
// Created by Guta on 2026-01-04.
//

#ifndef LETI_ESOFT_25_26_B1_VACCINECONTROLLER_H
#define LETI_ESOFT_25_26_B1_VACCINECONTROLLER_H

#include <string>
#include <optional>
#include <vector>
#include <memory>

#include "thirdparty/SimpleJson.hpp"
#include <headers/controllers/restapi/HttpResult.h>
#include <headers/controllers/restapi/HttpStatus.h>
#include <headers/domain/model/Vaccine.h>
#include <headers/domain/model/VaccineTechnology.h>
#include <headers/domain/repositories/VaccineTypeRepository.h>
#include <headers/infrastructure/memory/MemoryRepositoryFactory.h>

/**
 * REST controller for managing Vaccine resources.
 *
 * This controller exposes minimal CRUD operations required by the
 * REST API.  Currently only POST (create) and GET (list) are
 * supported.  All vaccines are stored in an in‑memory container
 * owned by the controller.  Validation of the vaccine type code
 * leverages the VaccineTypeRepository provided by the shared
 * RepositoryFactory.  Bearer token verification is limited to
 * checking that a non‑empty Authorization header is present,
 * following the pattern used in the VaccineTypeController.
 */
class VaccineController {
private:
    /**
     * Shared factory used to obtain repositories for validation.
     * Initialized on first construction of a controller instance.
     */
    static std::shared_ptr<RepositoryFactory> sharedFactory;

    /**
     * In‑memory container of persisted Vaccine instances.  A
     * std::vector is sufficient here since the REST API does not
     * support update or delete operations at this stage.  The
     * container persists across requests by virtue of being static.
     */
    static std::vector<Vaccine> vaccines;

    /**
     * Bearer token extracted from the request.  Stored for
     * potential future extensions (e.g. auditing).  Presently
     * unused beyond construction time validation.
     */
    std::wstring token;

public:
    /**
     * Constructs a VaccineController with the given bearer token.
     * Throws std::invalid_argument if the token is empty.
     *
     * @param bearerToken Authorization header value
     */
    explicit VaccineController(const std::wstring &bearerToken);

    /**
     * Lists all persisted vaccines.
     *
     * @return HttpResult containing a JSON array of vaccine objects
     */
    HttpResult getAll();

    /**
     * Creates a new vaccine from the provided parameters.  Mandatory
     * fields (commercialName, brand, typeCode, technology) are
     * validated.  The technology string is parsed into the
     * corresponding enumeration.  Type codes must exist in the
     * VaccineTypeRepository; otherwise a 400 error is returned.
     *
     * Optional attributes include the lot number and expiration
     * date.  These may be passed as empty strings to indicate
     * absence.
     *
     * @param commercialName commercial name of the vaccine
     * @param brand brand of the vaccine
     * @param typeCode vaccine type code (must exist)
     * @param technologyStr textual representation of the technology
     * @param lot optional lot number (empty string if not provided)
     * @param expirationDate optional expiration date (empty string if not provided)
     * @return HttpResult with appropriate status and message
     */
    HttpResult postVaccine(const std::string &commercialName,
                           const std::string &brand,
                           const std::string &typeCode,
                           const std::string &technologyStr,
                           const std::string &lot,
                           const std::string &expirationDate);
};

#endif //LETI_ESOFT_25_26_B1_VACCINECONTROLLER_H