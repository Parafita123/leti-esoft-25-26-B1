//
// Created by bergu on 10/01/2026.
//

#ifndef CONSULTWAITINGROOMCONTROLLER_H
#define CONSULTWAITINGROOMCONTROLLER_H


#include <vector>
#include <memory>
#include <headers/controllers/dto/UserArrivalDTO.h>

#include "headers/domain/services/WaitingRoomService.h"

class ConsultWaitingRoomController {
private:
    std::shared_ptr<WaitingRoomService> service;

public:
    ConsultWaitingRoomController();
    std::vector<UserArrivalDTO> getWaitingRoom(int facilityId);
};

#endif //CONSULTWAITINGROOMCONTROLLER_H
