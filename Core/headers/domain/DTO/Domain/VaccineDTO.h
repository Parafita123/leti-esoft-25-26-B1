//
// Created by diogo on 01/01/2026.
//

#ifndef LETI_ESOFT_25_26_B1_VACCINEDTO_H
#define LETI_ESOFT_25_26_B1_VACCINEDTO_H


#include <string>

class VaccineDTO {
private:
    std::string commercialName;
    std::string brand;
    std::string typeCode;

public:
    VaccineDTO(std::string commercialName,
               std::string brand,
               std::string typeCode)
            : commercialName(std::move(commercialName)),
              brand(std::move(brand)),
              typeCode(std::move(typeCode)) {}

    const std::string& getCommercialName() const {
        return commercialName;
    }

    const std::string& getBrand() const {
        return brand;
    }

    const std::string& getTypeCode() const {
        return typeCode;
    }
};

#endif //LETI_ESOFT_25_26_B1_VACCINEDTO_H
