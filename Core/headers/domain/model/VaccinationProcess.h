//
// Created by Guta on 18/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_VACCINATIONPROCESS_H
#define LETI_ESOFT_25_26_B1_VACCINATIONPROCESS_H

#include <string>
#include <chrono>

/**
 * Domain entity representing the administration of a vaccine to a given
 * SNS user.  Each vaccination process records the basic data needed to
 * identify the event: the SNS user number, the vaccine code, the lot
 * number of the administered dose and a timestamp indicating when the
 * administration occurred.  The nurse that performs the vaccination
 * may optionally be recorded via the nurse identifier.
 */
class VaccinationProcess {
private:
    std::string snsUserNumber;
    std::string vaccineCode;
    std::string lotNumber;
    std::string administrationDateTime;
    std::string nurseId;

public:
    VaccinationProcess() = default;
    VaccinationProcess(const std::string &snsUserNumber,
                       const std::string &vaccineCode,
                       const std::string &lotNumber,
                       const std::string &nurseId = "");

    const std::string &getSNSUserNumber() const;
    const std::string &getVaccineCode() const;
    const std::string &getLotNumber() const;
    const std::string &getAdministrationDateTime() const;
    const std::string &getNurseId() const;
};

#endif // LETI_ESOFT_25_26_B1_VACCINATIONPROCESS_H