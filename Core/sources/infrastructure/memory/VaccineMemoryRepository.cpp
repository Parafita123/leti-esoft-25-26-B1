//
// Created by diogo on 01/01/2026.
//
#include "headers/infrastructure/memory/VaccineMemoryRepository.h"

VaccineMemoryRepository::VaccineMemoryRepository(VaccineContainer& container)
        : container(container) {}

std::vector<Vaccine> VaccineMemoryRepository::findAll() const {
    return container.getAll();
}