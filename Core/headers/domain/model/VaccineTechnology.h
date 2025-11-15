//
// Created by ChatGPT on 2025-11-15.
//

#ifndef LETI_ESOFT_25_26_B1_VACCINETECHNOLOGY_H
#define LETI_ESOFT_25_26_B1_VACCINETECHNOLOGY_H

#include <string>
#include <vector>
#include <optional>

/**
 * Enum representing the available vaccine technology platforms.
 *
 * According to Pfizer, there are six main types of vaccine technologies:
 *  - Live‑attenuated vaccines
 *  - Inactivated vaccines
 *  - Protein subunit vaccines (we refer to these simply as Subunit)
 *  - Toxoid vaccines
 *  - Viral vector vaccines
 *  - mRNA vaccines
 *
 * See: https://www.pfizer.com/news/articles/understanding_six_types_of_vaccine_technologies
 */
enum class VaccineTechnology {
    LiveAttenuated,
    Inactivated,
    Subunit,
    Toxoid,
    ViralVector,
    mRNA
};

namespace VaccineTechnologyUtils {
    /**
     * Returns a list with all allowed vaccine technologies.
     * Use this list to populate selection menus in the UI.
     */
    const std::vector<VaccineTechnology>& getAllowedTechnologies();

    /**
     * Converts a VaccineTechnology enum to a human readable string.
     */
    std::string toString(VaccineTechnology technology);

    /**
     * Attempts to parse a string into a VaccineTechnology enum.
     * The comparison is case-insensitive. Returns std::nullopt if no match is found.
     */
    std::optional<VaccineTechnology> parse(const std::string& value);

    /**
     * Validates if the given technology is part of the allowed list.
     */
    bool isAllowed(VaccineTechnology technology);
}

#endif //LETI_ESOFT_25_26_B1_VACCINETECHNOLOGY_H