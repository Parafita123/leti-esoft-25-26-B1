//
// Created by diogo on 01/01/2026.
//
#include "headers/domain/DTO/Mapper/VaccineMapper.h"
#include "headers/domain/model/VaccineTechnology.h"

VaccineDTO VaccineMapper::toDTO(const Vaccine& vaccine) {
    return {
            vaccine.getTypeCode(),
            vaccine.getBrand(),
            VaccineTechnologyUtils::toString(vaccine.getTechnology())
    };
}