//
// Created by diogo on 11/01/2026.
//

#ifndef LETI_ESOFT_25_26_B1_VACCINATIONAPPOINTMENT_H
#define LETI_ESOFT_25_26_B1_VACCINATIONAPPOINTMENT_H



#include <string>

class VaccinationAppointment {
private:
    std::string snsUserNumber;
    std::string facilityId;
    std::string vaccineTypeCode;
    std::string date;
    std::string time;

public:
    VaccinationAppointment(const std::string& snsUserNumber,
                           const std::string& facilityId,
                           const std::string& vaccineTypeCode,
                           const std::string& date,
                           const std::string& time);

    const std::string& getSnsUserNumber() const;
    const std::string& getFacilityId() const;
    const std::string& getVaccineTypeCode() const;
    const std::string& getDate() const;
    const std::string& getTime() const;
};



#endif //LETI_ESOFT_25_26_B1_VACCINATIONAPPOINTMENT_H
