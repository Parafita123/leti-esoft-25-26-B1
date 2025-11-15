//
// Created by ChatGPT on 2025-11-15.
//

#include "headers/domain/model/VaccineContainer.h"
#include <algorithm>

using std::string;
using std::vector;
using std::optional;
using std::wstring;

// Converts a std::string to std::wstring
static inline wstring toWString(const string& s) {
    return wstring(s.begin(), s.end());
}

bool VaccineContainer::existsTypeCode(const string& typeCode, const VaccineTypeContainer& typeContainer) const {
    const auto& types = typeContainer.getAll();
    return std::any_of(types.begin(), types.end(),
                       [&typeCode](const VaccineType& vt){
                           return vt.getTypeCode() == typeCode;
                       });
}

Vaccine VaccineContainer::create(const string& commercialName,
                                 const string& brand,
                                 const string& typeCode,
                                 VaccineTechnology technology,
                                 const string& lot,
                                 optional<string> expirationDate) const {
    // Constructor will perform minimal validation (non-empty mandatory fields, allowed technology).
    return Vaccine(commercialName, brand, typeCode, technology, lot, expirationDate);
}

Result VaccineContainer::validate(const Vaccine& vaccine,
                                  const VaccineTypeContainer& typeContainer) const {
    // 1. Technology must be allowed (redundant since checked in constructor).
    if (!VaccineTechnologyUtils::isAllowed(vaccine.getTechnology())) {
        return Result::NOK(L"Technology is not in the allowed list.");
    }

    // 2. Type code must exist in VaccineTypeContainer.
    if (!existsTypeCode(vaccine.getTypeCode(), typeContainer)) {
        wstring msg = L"Unknown vaccine type code: " + toWString(vaccine.getTypeCode());
        return Result::NOK(msg);
    }

    // Additional validations (uniqueness, lot format, expiration) could be added in future sprints.

    return Result::OK(L"Vaccine validation successful.");
}

Result VaccineContainer::save(const Vaccine& vaccine,
                              const VaccineTypeContainer& typeContainer) {
    // Validate first
    Result validation = validate(vaccine, typeContainer);
    if (validation.isNOK()) {
        return validation;
    }
    vaccines.push_back(vaccine);
    return Result::OK(L"Vaccine saved successfully.");
}

const vector<Vaccine>& VaccineContainer::getAll() const {
    return vaccines;
}