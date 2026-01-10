cmake_minimum_required(VERSION 3.27)
project(CoreTests)

include(FetchContent)
include(CTest)
enable_testing()

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# 1) Define o executável primeiro
add_executable(CoreTests
        domain/services/VaccinationProcessServiceTests.cpp

        # Se precisares mesmo disto nos testes (senão, remove)
        ../RestAPI/sources/RouterConfig.cpp
        ../RestAPI/sources/ServerStatusRouter.cpp
        ../RestAPI/sources/VaccineTypeRouter.cpp

        # Se os testes usam estes .cpp diretamente (senão, remove)
        ../Core/sources/controllers/restapi/HttpResult.cpp
        ../Core/sources/controllers/restapi/RestController.cpp
        ../Core/sources/controllers/restapi/VaccineTypeController.cpp
        domain/model/VaccinationCenterTests.cpp
        domain/repositories/RepositoryFactoryMock.h
        domain/repositories/UserArrivalRepositoryMock.h
        domain/repositories/VaccinationAppointmentRepositoryMock.h
        domain/services/UserArrivalServiceTests.cpp
        domain/repositories/SNSUserRepositoryMock.h
        domain/repositories/VaccinationCenterRepositoryMock.h
)

# 2) Includes
target_include_directories(CoreTests PRIVATE
        ${CMAKE_SOURCE_DIR}/Core
        ${CMAKE_SOURCE_DIR}/RestAPI
)

# 3) Link libs
target_link_libraries(CoreTests PRIVATE
        Core
        GTest::gtest
        GTest::gmock
        GTest::gtest_main
)

# 4) Winsock no Windows (porque tens httplib/RouterConfig nos testes)
if (WIN32)
    target_link_libraries(CoreTests PRIVATE ws2_32)
endif()

# 5) Registar no CTest
add_test(NAME CoreTests COMMAND CoreTests)
