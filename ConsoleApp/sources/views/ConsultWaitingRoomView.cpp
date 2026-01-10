//
// Created by bergu on 10/01/2026.
//
#include "headers/views/ConsultWaitingRoomView.h"
#include <iostream>
#include <iomanip>

ConsultWaitingRoomView::ConsultWaitingRoomView() {
    controller = std::make_shared<ConsultWaitingRoomController>();
}

void ConsultWaitingRoomView::run() {
    int facilityId;
    std::cout << "\n--- Consult Waiting Room ---" << std::endl;

    // Na implementação real, aqui chamaria o controller para listar as facilities
    // e o utilizador escolheria de uma lista, tal como na US22.
    std::cout << "Enter Vaccination Center ID: ";
    std::cin >> facilityId;

    displayWaitingRoom(facilityId);
}

void ConsultWaitingRoomView::displayWaitingRoom(int facilityId) {
    // Obtém a lista de DTOs do controlador para garantir o desacoplamento
    auto waitingRoom = controller->getWaitingRoom(facilityId);

    if (waitingRoom.empty()) {
        std::cout << "\nThe waiting room is currently empty for this facility." << std::endl;
        return;
    }

    std::cout << "\nWaiting Room List (First-come, first-served):" << std::endl;
    std::cout << std::setw(20) << std::left << "SNS User Number"
              << std::setw(15) << "Facility ID" << std::endl;
    std::cout << "------------------------------------------" << std::endl;

    for (const auto& dto : waitingRoom) {
        std::cout << std::setw(20) << std::left << dto.sns_user_number
                  << std::setw(15) << dto.facilityID << std::endl;
    }
}