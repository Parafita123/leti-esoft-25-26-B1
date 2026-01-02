//
// Created by diogo on 01/01/2026.
//
#include "headers/domain/DTO/Mapper/VaccineMapper.h"
#include "headers/domain/model/VaccineTechnology.h"

VaccineDTO VaccineMapper::toDTO(const Vaccine& v) {
    return VaccineDTO(
            v.getCommercialName(),
            v.getBrand(),
            v.getTypeCode()
    );
}