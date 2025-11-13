cmake_minimum_required(VERSION 3.27)
project(leti_esoft_25_26_B1)

set(CMAKE_CXX_STANDARD 17)

add_executable(leti-esoft-25-26-B1 main.cpp
        Core/headers/controllers/ui/App.h
        Core/headers/controllers/ui/CreateNewVaccineTypeController.h
        Core/headers/controllers/ui/App.h
        Core/headers/domain/model/VaccineType.h
        Core/sources/controllers/ui/App.cpp
        Core/sources/controllers/ui/CreateNewVaccineTypeController.cpp
        Core/sources/domain/model/VaccineType.cpp
        ConsoleApp/headers/views/CreateNewVaccineTypeView.h
        ConsoleApp/sources/views/CreateNewVaccineTypeView.cpp
        Core/sources/domain/model/VaccineTypeContainer.cpp
        ConsoleApp/headers/views/MainView.h
        ConsoleApp/sources/views/MainView.cpp)

include_directories(Core)
add_subdirectory(Core)
add_subdirectory(ConsoleApp)

target_link_libraries(leti-esoft-25-26-B1 Core)