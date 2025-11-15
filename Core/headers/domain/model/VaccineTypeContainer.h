//
// Created by Filipe on 13/11/2025.
//

#ifndef UNTITLED1_VACCINETYPECONTAINER_H
#define UNTITLED1_VACCINETYPECONTAINER_H

#include <vector>
#include <optional>
#include "VaccineType.h"
#include "headers/domain/shared/Result.h"

class VaccineTypeContainer {
private:
    std::vector<VaccineType> vaccineTypes;

    bool existsTypeCode(const std::string& code) const;

public:
    VaccineTypeContainer() = default;

    // cria um objeto em memória (sem guardar ainda)
    VaccineType create(const std::string& type_code,
                       const std::string& disease,
                       const std::string& short_description);

    // valida o objeto (regras de negócio)
    Result validate(const VaccineType& vaccineType) const;

    // valida + guarda se tudo ok
    Result save(const VaccineType& vaccineType);

    const std::vector<VaccineType>& getAll() const;
};

#endif //UNTITLED1_VACCINETYPECONTAINER_H
