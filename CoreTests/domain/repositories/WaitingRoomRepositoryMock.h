// created by Guta on 2025-12-21
//
// Mock class for WaitingRoomRepository using Google Mock. It allows
// tests to specify the behavior of removing SNS users from the waiting
// room.

#ifndef LETI_ESOFT_25_26_B1_WAITINGROOMREPOSITORYMOCK_H
#define LETI_ESOFT_25_26_B1_WAITINGROOMREPOSITORYMOCK_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <headers/domain/repositories/WaitingRoomRepository.h>

class WaitingRoomRepositoryMock : public WaitingRoomRepository {
public:
    MOCK_METHOD(Result, removeSNSUser, (const std::string &snsUserNumber), (override));
};

#endif // LETI_ESOFT_25_26_B1_WAITINGROOMREPOSITORYMOCK_H