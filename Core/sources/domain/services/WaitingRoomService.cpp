//
// Created by bergu on 10/01/2026.
//
#include "headers/domain/services/WaitingRoomService.h"
#include <algorithm>
#include <headers/domain/repositories/UserArrivalRepository.h>

WaitingRoomService::WaitingRoomService(std::shared_ptr<UserArrivalRepository> r)
    : repo(std::move(r)) {}

std::vector<std::shared_ptr<UserArrival>> WaitingRoomService::getWaitingRoomList(int facilityId) {
    // Information Expert: O repositório fornece todos os registos
    auto allArrivals = repo->findAll();
    std::vector<std::shared_ptr<UserArrival>> filtered;

    for (const auto& a : allArrivals) {
        if (a && a->getFacility() && a->getFacility()->getFacilityID() == facilityId) {
            filtered.push_back(a);
        }
    }

    // AC40-1: First-come, first-served (ordenação cronológica)
    std::sort(filtered.begin(), filtered.end(), [](const auto& a, const auto& b) {
        return a->getArrivalTime() < b->getArrivalTime();
    });

    return filtered;
}