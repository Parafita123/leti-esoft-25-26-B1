//
// Created by bergu on 10/01/2026.
//

#ifndef WAITING_ROOM_MAPPER_H
#define WAITING_ROOM_MAPPER_H

#include "headers/domain/model/UserArrival.h"
#include <memory>
#include <headers/controllers/dto/UserArrivalDTO.h>

class WaitingRoomMapper {
public:
    static UserArrivalDTO toDTO(const std::shared_ptr<UserArrival>& arrival);
};

#endif