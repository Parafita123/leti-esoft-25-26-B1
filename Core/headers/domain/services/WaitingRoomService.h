//
// Created by bergu on 10/01/2026.
//

#ifndef WAITING_ROOM_SERVICE_H
#define WAITING_ROOM_SERVICE_H

#include <vector>
#include <memory>
#include <headers/domain/repositories/UserArrivalRepository.h>

class WaitingRoomService {
private:
    std::shared_ptr<UserArrivalRepository> repo;

public:
    WaitingRoomService(std::shared_ptr<UserArrivalRepository> r);
    std::vector<std::shared_ptr<UserArrival>> getWaitingRoomList(int facilityId);
};

#endif