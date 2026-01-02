//
// Created by diogo on 02/01/2026.
//
#include "headers/views/ListVaccinesView.h"
#include <iostream>

void ListVaccinesView::show(const std::vector<VaccineDTO>& vaccines) const {
    std::cout << "\n=== LIST OF VACCINES ===\n";

    std::string currentType;

    for (const auto& dto : vaccines) {
        if (dto.getTypeCode() != currentType) {
            currentType = dto.getTypeCode();
            std::cout << "\nVaccine Type: " << currentType << "\n";
        }

        std::cout << " - "
                  << dto.getCommercialName()
                  << " (" << dto.getBrand() << ")\n";
    }

    std::cout << "\n=======================\n";
}