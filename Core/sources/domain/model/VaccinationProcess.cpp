// created by Guta on 2025-12-20
//
// Implementation of VaccinationProcess.

#include "headers/domain/model/VaccinationProcess.h"

VaccinationProcess::VaccinationProcess(const std::string &snsUserNumber,
                                       const std::string &vaccineCode,
                                       const std::string &lotNumber,
                                       const std::string &administrationDateTime)
        : snsUserNumber(snsUserNumber),
          vaccineCode(vaccineCode),
          lotNumber(lotNumber),
          administrationDateTime(administrationDateTime) {}

const std::string &VaccinationProcess::getSNSUserNumber() const {
    return snsUserNumber;
}

const std::string &VaccinationProcess::getVaccineCode() const {
    return vaccineCode;
}

const std::string &VaccinationProcess::getLotNumber() const {
    return lotNumber;
}

const std::string &VaccinationProcess::getAdministrationDateTime() const {
    return administrationDateTime;
}