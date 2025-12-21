// created by Guta on 2025-12-20
//
// Represents a single vaccination administration record.  Each record
// captures the SNS user number, the vaccine code and lot number used
// during the administration as well as the timestamp when it occurred.

#ifndef LETI_ESOFT_25_26_B1_VACCINATIONPROCESS_H
#define LETI_ESOFT_25_26_B1_VACCINATIONPROCESS_H

#include <string>
#include <memory>

class VaccinationProcess {
private:
    std::string snsUserNumber;
    std::string vaccineCode;
    std::string lotNumber;
    std::string administrationDateTime;

public:
    /**
     * Constructs a vaccination process with all required fields.
     *
     * @param snsUserNumber the SNS identifier of the citizen being vaccinated
     * @param vaccineCode   the code identifying the vaccine administered
     * @param lotNumber     the lot number of the vaccine used
     * @param administrationDateTime a date/time stamp in ISO 8601 format
     */
    VaccinationProcess(const std::string &snsUserNumber,
                       const std::string &vaccineCode,
                       const std::string &lotNumber,
                       const std::string &administrationDateTime);

    /**
     * Returns the SNS identifier of the vaccinated citizen.
     */
    const std::string &getSNSUserNumber() const;

    /**
     * Returns the vaccine code used.
     */
    const std::string &getVaccineCode() const;

    /**
     * Returns the lot number of the vaccine used.
     */
    const std::string &getLotNumber() const;

    /**
     * Returns the administration date/time in ISO 8601 format.
     */
    const std::string &getAdministrationDateTime() const;
};

#endif // LETI_ESOFT_25_26_B1_VACCINATIONPROCESS_H