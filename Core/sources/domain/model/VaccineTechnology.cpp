//
// Created by Guta on 2025-11-15.
//

#include "headers/domain/model/VaccineTechnology.h"
#include <algorithm>
#include <cctype>

using std::vector;
using std::string;
using std::optional;

namespace {
    // Static vector containing all allowed technologies.
    const vector<VaccineTechnology> ALLOWED_TECHS = {
        VaccineTechnology::LiveAttenuated,
        VaccineTechnology::Inactivated,
        VaccineTechnology::Subunit,
        VaccineTechnology::Toxoid,
        VaccineTechnology::ViralVector,
        VaccineTechnology::mRNA
    };
}

const vector<VaccineTechnology>& VaccineTechnologyUtils::getAllowedTechnologies() {
    return ALLOWED_TECHS;
}

string VaccineTechnologyUtils::toString(VaccineTechnology technology) {
    switch (technology) {
        case VaccineTechnology::LiveAttenuated: return "Live-attenuated";
        case VaccineTechnology::Inactivated:    return "Inactivated";
        case VaccineTechnology::Subunit:        return "Subunit";
        case VaccineTechnology::Toxoid:         return "Toxoid";
        case VaccineTechnology::ViralVector:    return "Viral vector";
        case VaccineTechnology::mRNA:           return "mRNA";
        default:                                return "";
    }
}

// Helper to convert string to lower-case.
static inline string toLower(const string& s) {
    string out = s;
    std::transform(out.begin(), out.end(), out.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return out;
}

optional<VaccineTechnology> VaccineTechnologyUtils::parse(const string& value) {
    auto normalized = toLower(value);
    if (normalized == "live-attenuated" || normalized == "liveattenuated" || normalized == "live attenuated")
        return VaccineTechnology::LiveAttenuated;
    if (normalized == "inactivated")
        return VaccineTechnology::Inactivated;
    if (normalized == "subunit" || normalized == "protein subunit")
        return VaccineTechnology::Subunit;
    if (normalized == "toxoid")
        return VaccineTechnology::Toxoid;
    if (normalized == "viral vector" || normalized == "viralvector")
        return VaccineTechnology::ViralVector;
    if (normalized == "mrna")
        return VaccineTechnology::mRNA;
    return std::nullopt;
}

bool VaccineTechnologyUtils::isAllowed(VaccineTechnology technology) {
    return std::find(ALLOWED_TECHS.begin(), ALLOWED_TECHS.end(), technology) != ALLOWED_TECHS.end();
}