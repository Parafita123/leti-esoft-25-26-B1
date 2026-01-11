cmake_minimum_required(VERSION 3.27)
project(leti_esoft_25_26_B1)

set(CMAKE_CXX_STANDARD 17)

# Subprojetos/libraries
add_subdirectory(Core)
add_subdirectory(ConsoleApp)
add_subdirectory(RestAPI)
add_subdirectory(CoreTests)

enable_testing()

# Executável da consola (MainView)
add_executable(app_console main.cpp
        ConsoleApp/headers/views/RegisterUserArrivalView.h)
target_link_libraries(app_console PRIVATE Core ConsoleAppLib)


if (WIN32)
    target_link_libraries(app_console PRIVATE ws2_32)
endif()
