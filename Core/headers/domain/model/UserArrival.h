//
// Created by Filipe on 20/12/2025.
//

#ifndef LETI_ESOFT_25_26_B1_USERARRIVAL_H
#define LETI_ESOFT_25_26_B1_USERARRIVAL_H

#pragma once
#include <memory>
#include <chrono>
#include "headers/domain/model/SNSUser.h"
#include "headers/domain/model/Facility.h"

class UserArrival {
private:
    std::chrono::system_clock::time_point arrival_time;
    std::shared_ptr<SNSUser> user;
    std::shared_ptr<Facility> facility;
    bool assigned_to_waiting_room;

public:
    UserArrival(std::chrono::system_clock::time_point arrivalTime,
                std::shared_ptr<SNSUser> user,
                std::shared_ptr<Facility> facility);

    std::chrono::system_clock::time_point getArrivalTime() const;
    const std::shared_ptr<SNSUser> & getUser() const;
    const std::shared_ptr<Facility> & getFacility() const;
    bool isAssignedToWaitingRoom() const;
};
#endif //LETI_ESOFT_25_26_B1_USERARRIVAL_H
