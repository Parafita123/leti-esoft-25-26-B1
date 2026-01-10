//
// Created by bergu on 10/01/2026.
//

#ifndef CONSULTWAITINGROOMVIEW_H
#define CONSULTWAITINGROOMVIEW_H


#include <memory>

#include "headers/controllers/ui/ConsultWaitingRoomController.h"

class ConsultWaitingRoomView {
private:
    std::shared_ptr<ConsultWaitingRoomController> controller;
    void displayWaitingRoom(int facilityId);

public:
    ConsultWaitingRoomView();
    void run();
};

#endif //CONSULTWAITINGROOMVIEW_H
