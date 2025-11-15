project(ConsoleApp)

add_executable(ConsoleApp ConsoleApp.cpp
        ../Core/headers/domain/model/VaccineType.h
        ../Core/sources/controllers/ui/App.cpp
        ../Core/sources/controllers/ui/CreateNewVaccineTypeController.cpp
        ../Core/sources/domain/model/VaccineType.cpp
        headers/views/CreateNewVaccineTypeView.h
        sources/views/CreateNewVaccineTypeView.cpp
        ../Core/sources/domain/model/VaccineTypeContainer.cpp
        headers/views/MainView.h
        sources/views/MainView.cpp)

target_link_libraries(ConsoleApp Core)