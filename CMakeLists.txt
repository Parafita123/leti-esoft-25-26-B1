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
        ConsoleApp/sources/views/MainView.cpp
        Core/headers/domain/model/VaccineTechnology.h
        Core/sources/domain/model/VaccineTechnology.cpp
        Core/headers/domain/model/Vaccine.h
        Core/sources/domain/model/Vaccine.cpp
        Core/headers/domain/model/VaccineContainer.h
        Core/sources/domain/model/VaccineContainer.cpp
        Core/headers/controllers/ui/RegisterVaccineController.h
        Core/sources/controllers/ui/RegisterVaccineController.cpp
        ConsoleApp/headers/views/RegisterVaccineView.h
        ConsoleApp/sources/views/RegisterVaccineView.cpp
        Core/headers/domain/model/FacilityType.h
        Core/headers/controllers/dto/VaccinationCenterDTO.h
        Core/headers/domain/model/Facility.h
        Core/sources/domain/model/Faclity.cpp
        Core/headers/domain/model/HealthcareCenter.h
        Core/headers/domain/model/CommunityMassVaccinationCenter.h
        Core/sources/domain/model/CommunityMassVaccinationCenter.cpp
        Core/headers/domain/repositories/VaccinationCenterRepository.h
        Core/headers/domain/repositories/VaccineTypeRepository.h
        Core/headers/domain/repositories/VaccineTypeRepository.h
        Core/headers/infrastructure/memory/VaccinationCenterMemoryRepository.h
        Core/sources/infrastructure/memory/VaccinationCenterMemoryRepository.cpp
        Core/headers/infrastructure/memory/VaccineTypeMemoryRepository.h
        Core/sources/infrastructure/memory/VaccineTypeMemoryRepository.cpp
        Core/headers/domain/services/VaccinationCenterService.h
        Core/sources/domain/services/VaccinationCenterService.cpp
        Core/headers/controllers/ui/RegisterVaccinationCenterController.h
        ConsoleApp/headers/views/RegisterVaccinationCenterView.h
        ConsoleApp/sources/views/RegisterVaccinationCenterView.cpp)

# US20 - Register SNS user
target_sources(leti-esoft-25-26-B1 PRIVATE
        Core/headers/domain/model/SNSUser.h
        Core/sources/domain/model/SNSUser.cpp
        Core/headers/domain/model/SNSUserContainer.h
        Core/sources/domain/model/SNSUserContainer.cpp
        Core/headers/controllers/ui/RegisterSNSUserController.h
        Core/sources/controllers/ui/RegisterSNSUserControllerRegisterSNSUserController.cpp
        ConsoleApp/headers/views/RegisterSNSUserView.h
        ConsoleApp/sources/views/RegisterSNSUserView.cpp)

include_directories(Core)
add_subdirectory(Core)
add_subdirectory(ConsoleApp)

target_link_libraries(leti-esoft-25-26-B1 Core)