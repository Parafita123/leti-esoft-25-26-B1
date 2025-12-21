// created by Guta on 2025-12-20
//
// Data transfer object used to capture data from the user interface when
// recording a vaccination administration.  It contains the SNS user
// number, vaccine code and lot number.

#ifndef LETI_ESOFT_25_26_B1_VACCINATIONPROCESSDTO_H
#define LETI_ESOFT_25_26_B1_VACCINATIONPROCESSDTO_H

#include <string>

struct VaccinationProcessDTO {
    std::string snsUserNumber;
    std::string vaccineCode;
    std::string lotNumber;
};

#endif // LETI_ESOFT_25_26_B1_VACCINATIONPROCESSDTO_H