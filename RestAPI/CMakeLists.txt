project(RestAPI)

add_executable(RestAPI
        RestAPI.cpp
        sources/RouterConfig.cpp
        sources/TasksServer.cpp
        sources/VaccineTypeRouter.cpp
        sources/ServerStatusRouter.cpp
)

target_include_directories(RestAPI PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(RestAPI PRIVATE Core)

if(WIN32)
    target_link_libraries(RestAPI PRIVATE ws2_32)
endif()
