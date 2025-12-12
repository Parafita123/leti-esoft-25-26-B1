//
// Created by Filipe on 12/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_FACILITY_H
#define LETI_ESOFT_25_26_B1_FACILITY_H

#include <string>

class Facility {
protected:
    std::string name;
    std::string postal_address;
    std::string phone_number;
    std::string email;
    std::string website_address;
    std::string opening_hours;
    std::string closing_hours;
    int max_vaccines_per_hour;

public:
    Facility(std::string name,
             std::string postal_address,
             std::string phone_number,
             std::string email,
             std::string website_address,
             std::string opening_hours,
             std::string closing_hours,
             int max_vaccines_per_hour);

    virtual ~Facility() = default;

    const std::string& getName() const;
};

#endif //LETI_ESOFT_25_26_B1_FACILITY_H
