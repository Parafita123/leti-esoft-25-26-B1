//
// Created by Filipe on 20/12/2025.
//
#include "headers/domain/model/UserArrival.h"
#include <stdexcept>

UserArrival::UserArrival(std::chrono::system_clock::time_point arrivalTime,
                         std::shared_ptr<SNSUser> user,
                         std::shared_ptr<Facility> facility)
        : arrival_time(arrivalTime),
          user(std::move(user)),
          facility(std::move(facility)),
          assigned_to_waiting_room(true) // check-in implies waiting room assignment
{
    if (!this->user) throw std::invalid_argument("UserArrival requires a SNSUser.");
    if (!this->facility) throw std::invalid_argument("UserArrival requires a Facility.");
}

std::chrono::system_clock::time_point UserArrival::getArrivalTime() const { return arrival_time; }
const std::shared_ptr<SNSUser> & UserArrival::getUser() const { return user; }
const std::shared_ptr<Facility> & UserArrival::getFacility() const { return facility; }
bool UserArrival::isAssignedToWaitingRoom() const { return assigned_to_waiting_room; }