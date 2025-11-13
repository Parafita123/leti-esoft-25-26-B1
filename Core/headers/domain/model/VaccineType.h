//
// Created by Filipe on 04/11/2025.
//

#ifndef LETI_ESOFT_25_26_B1_VACCINETYPE_H
#define LETI_ESOFT_25_26_B1_VACCINETYPE_H

#include <string>

class VaccineType {
private:
    std::string type_code;
    std::string disease;
    std::string short_description;

public:
    VaccineType() = default;

    VaccineType(std::string type_code, std::string disease, std::string short_description);

    // Getters
    const std::string& getTypeCode() const;
    const std::string& getDisease() const;
    const std::string& getShortDescription() const;

    // Utility
    std::string toString() const;
};

#endif //LETI_ESOFT_25_26_B1_VACCINETYPE_H
