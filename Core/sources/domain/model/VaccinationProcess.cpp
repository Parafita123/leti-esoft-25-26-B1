//
// Created by Guta on 18/12/2025.
//

#include "headers/domain/model/VaccinationProcess.h"
#include <chrono>
#include <iomanip>
#include <sstream>

using std::string;

// Helper to obtain the current date/time as ISO 8601 string
static string currentDateTime() {
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::tm tm = *std::localtime(&t);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

VaccinationProcess::VaccinationProcess(const string &snsUserNumber,
                                       const string &vaccineCode,
                                       const string &lotNumber,
                                       const string &nurseId)
        : snsUserNumber(snsUserNumber),
          vaccineCode(vaccineCode),
          lotNumber(lotNumber),
          administrationDateTime(currentDateTime()),
          nurseId(nurseId) {}

const string &VaccinationProcess::getSNSUserNumber() const {
    return snsUserNumber;
}

const string &VaccinationProcess::getVaccineCode() const {
    return vaccineCode;
}

const string &VaccinationProcess::getLotNumber() const {
    return lotNumber;
}

const string &VaccinationProcess::getAdministrationDateTime() const {
    return administrationDateTime;
}

const string &VaccinationProcess::getNurseId() const {
    return nurseId;
}