project(ConsoleApp)

add_library(ConsoleAppLib
        headers/views/MainView.h
        sources/views/MainView.cpp

        headers/views/CreateNewVaccineTypeView.h
        sources/views/CreateNewVaccineTypeView.cpp

        headers/views/RegisterVaccineView.h
        sources/views/RegisterVaccineView.cpp

        headers/views/ListEmployeesByRoleView.h
        sources/views/ListEmployeesByRoleView.cpp

        sources/views/RegisterEmployeeView.cpp

        headers/views/RegisterVaccinationCenterView.h
        sources/views/RegisterVaccinationCenterView.cpp

        headers/views/RegisterSNSUserView.h
        sources/views/RegisterSNSUserView.cpp

        headers/views/RecordVaccinationView.h
        sources/views/RecordVaccinationView.cpp
        headers/views/ListVaccinesView.h
        sources/views/ListVaccinesView.cpp
)

target_include_directories(ConsoleAppLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(ConsoleAppLib PUBLIC Core)
