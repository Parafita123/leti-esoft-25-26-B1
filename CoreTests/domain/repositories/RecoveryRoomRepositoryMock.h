// created by Guta on 2025-12-21
//
// Mock class for RecoveryRoomRepository using Google Mock. It allows
// tests to specify the behavior of assigning SNS users to the recovery
// room.

#ifndef LETI_ESOFT_25_26_B1_RECOVERYROOMREPOSITORYMOCK_H
#define LETI_ESOFT_25_26_B1_RECOVERYROOMREPOSITORYMOCK_H

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <headers/domain/repositories/RecoveryRoomRepository.h>

class RecoveryRoomRepositoryMock : public RecoveryRoomRepository {
public:
    MOCK_METHOD(Result, assignSNSUser, (const std::string &snsUserNumber), (override));
};

#endif // LETI_ESOFT_25_26_B1_RECOVERYROOMREPOSITORYMOCK_H