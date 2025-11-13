//
// Created by Filipe on 13/11/2025.
//

#include "headers/domain/model/VaccineTypeContainer.h"
#include <algorithm>

using std::string;
using std::vector;
using std::wstring;

bool VaccineTypeContainer::existsTypeCode(const string& code) const {
    return std::any_of(vaccineTypes.begin(), vaccineTypes.end(),
                       [&](const VaccineType& vt) {
                           return vt.getTypeCode() == code;
                       });
}

VaccineType VaccineTypeContainer::create(const string& type_code,
                                         const string& disease,
                                         const string& short_description) {
    return VaccineType(type_code, disease, short_description);
}

Result VaccineTypeContainer::validate(const VaccineType& vaccineType) const {
    if (vaccineType.getTypeCode().empty()) {
        return Result::NOK(L"Type code cannot be empty.");
    }

    if (existsTypeCode(vaccineType.getTypeCode())) {
        return Result::NOK(L"Type code already exists.");
    }

    if (vaccineType.getDisease().empty()) {
        return Result::NOK(L"Disease name cannot be empty.");
    }

    if (vaccineType.getShortDescription().empty()) {
        return Result::NOK(L"Short description cannot be empty.");
    }

    if (vaccineType.getShortDescription().size() > 100) {
        return Result::NOK(L"Short description must be under 100 characters.");
    }

    return Result::OK(L"Validation successful.");
}

Result VaccineTypeContainer::save(const VaccineType& vaccineType) {
    Result validation = validate(vaccineType);

    if (validation.isNOK()) {
        // devolve o erro tal como veio da validação
        return validation;
    }

    vaccineTypes.push_back(vaccineType);
    return Result::OK(L"Vaccine Type saved successfully.");
}

const vector<VaccineType>& VaccineTypeContainer::getAll() const {
    return vaccineTypes;
}
