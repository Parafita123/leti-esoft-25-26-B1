//
// Created by Guta on 19/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_VACCINATIONPROCESSDTO_H
#define LETI_ESOFT_25_26_B1_VACCINATIONPROCESSDTO_H

#include <string>

/**
 * Simple data transfer object used by the view layer to collect the
 * data required for recording a vaccination process.  Keeping this
 * structure separate from the domain model decouples the UI from
 * domain classes and facilitates validation at the service layer.
 */
struct VaccinationProcessDTO {
    std::string snsUserNumber;
    std::string vaccineCode;
    std::string lotNumber;
};

#endif // LETI_ESOFT_25_26_B1_VACCINATIONPROCESSDTO_H
