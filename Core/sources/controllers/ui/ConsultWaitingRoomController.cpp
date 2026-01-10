//
// Created by bergu on 10/01/2026.
//
#include "headers/controllers/ui/ConsultWaitingRoomController.h"

#include <headers/controllers/ui/App.h>

#include "headers/controllers/ui/App.h" // Acesso ao Singleton App
#include "headers/domain/DTO/Mapper/WaitingRoomMapper.h"
#include "headers/domain/services/WaitingRoomService.h"

ConsultWaitingRoomController::ConsultWaitingRoomController() {
    // Protected Variation: Obtém repositório via Factory e injeta no serviço
    auto repo = App::getInstance().getRepositoryFactory()->getUserArrivalRepository();
    service = std::make_shared<WaitingRoomService>(repo);
}

std::vector<UserArrivalDTO> ConsultWaitingRoomController::getWaitingRoom(int facilityId) {
    auto arrivals = service->getWaitingRoomList(facilityId);
    std::vector<UserArrivalDTO> dtoList;

    for (const auto& arrival : arrivals) {
        dtoList.push_back(WaitingRoomMapper::toDTO(arrival));
    }
    return dtoList;
}