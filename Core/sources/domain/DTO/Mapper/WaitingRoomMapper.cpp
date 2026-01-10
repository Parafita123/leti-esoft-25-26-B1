//
// Created by bergu on 10/01/2026.
//
#include "headers/domain/DTO/Mapper/WaitingRoomMapper.h"
#include <headers/controllers/dto/UserArrivalDTO.h>
#include "headers/domain/model/UserArrival.h"

UserArrivalDTO WaitingRoomMapper::toDTO(const std::shared_ptr<UserArrival>& arrival) {
    if (!arrival) return {0, 0};

    return {
        arrival->getFacility()->getFacilityID(),
        std::stoi(arrival->getUser()->getSNSUserNumber())
    };
}
