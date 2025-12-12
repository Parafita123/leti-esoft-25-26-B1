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
        sources/views/MainView.cpp
        # US11 - Register Vaccine
        headers/views/RegisterVaccineView.h
        sources/views/RegisterVaccineView.cpp
        headers/views/ListEmployeesByRoleView.h
        sources/views/ListEmployeesByRoleView.cpp
        sources/views/RegisterEmployeeView.cpp
        ../Core/headers/domain/model/FacilityType.h
        ../Core/headers/controllers/dto/VaccinationCenterDTO.h
        ../Core/headers/domain/model/Facility.h
        ../Core/sources/domain/model/Faclity.cpp
        ../Core/headers/domain/model/HealthcareCenter.h
        ../Core/headers/domain/model/CommunityMassVaccinationCenter.h
        ../Core/sources/domain/model/CommunityMassVaccinationCenter.cpp
        ../Core/headers/domain/repositories/VaccinationCenterRepository.h
        ../Core/headers/domain/repositories/VaccineTypeRepository.h
        ../Core/headers/domain/repositories/VaccineTypeRepository.h
        ../Core/headers/infrastructure/memory/VaccinationCenterMemoryRepository.h
        ../Core/sources/infrastructure/memory/VaccinationCenterMemoryRepository.cpp
        ../Core/headers/infrastructure/memory/VaccineTypeMemoryRepository.h
        ../Core/sources/infrastructure/memory/VaccineTypeMemoryRepository.cpp
        ../Core/headers/domain/services/VaccinationCenterService.h
        ../Core/sources/domain/services/VaccinationCenterService.cpp
        ../Core/headers/controllers/ui/RegisterVaccinationCenterController.h
        headers/views/RegisterVaccinationCenterView.h
        headers/views/RegisterVaccinationCenterView.h
        sources/views/RegisterVaccinationCenterView.cpp
        sources/views/RegisterVaccinationCenterView.cpp
)

target_link_libraries(ConsoleApp Core)