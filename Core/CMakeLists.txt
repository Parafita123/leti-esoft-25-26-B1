project(Core)

add_library(Core
        # shared
        headers/domain/shared/Result.h
        sources/domain/shared/Result.cpp
        headers/domain/shared/StringUtils.h
        sources/domain/shared/StringUtils.cpp

        # domain models
        headers/domain/model/VaccineType.h
        sources/domain/model/VaccineType.cpp
        sources/domain/model/VaccineTypeContainer.cpp

        headers/domain/model/VaccineTechnology.h
        sources/domain/model/VaccineTechnology.cpp

        headers/domain/model/Vaccine.h
        sources/domain/model/Vaccine.cpp
        headers/domain/model/VaccineContainer.h
        sources/domain/model/VaccineContainer.cpp

        headers/domain/model/SNSUser.h
        sources/domain/model/SNSUser.cpp
        headers/domain/model/SNSUserContainer.h
        sources/domain/model/SNSUserContainer.cpp

        headers/domain/model/Employee.h
        sources/domain/model/Employee.cpp

        headers/domain/model/EmployeeContainer.h
        sources/domain/model/EmployeeContainer.cpp


        headers/domain/model/VaccinationProcess.h
        sources/domain/model/VaccinationProcess.cpp

        headers/domain/model/UserArrival.h
        sources/domain/model/UserArrival.cpp

        headers/domain/model/CommunityMassVaccinationCenter.h
        sources/domain/model/CommunityMassVaccinationCenter.cpp
        headers/domain/model/Facility.h
        sources/domain/model/Faclity.cpp

        headers/domain/shared/Result.h
        sources/domain/shared/Result.cpp
        headers/domain/shared/StringUtils.h
        sources/domain/shared/StringUtils.cpp


        # services
        headers/domain/services/SNSUserService.h
        sources/domain/services/SNSUserService.cpp
        headers/domain/services/VaccinationProcessService.h
        sources/domain/services/VaccinationProcessService.cpp
        headers/domain/services/UserArrivalService.h
        sources/domain/services/UserArrivalService.cpp
        headers/domain/services/VaccinationCenterService.h
        sources/domain/services/VaccinationCenterService.cpp

        # repositories + memory
        headers/infrastructure/memory/MemoryRepositoryFactory.h
        sources/infrastructure/memory/MemoryRepositoryFactory.cpp
        headers/infrastructure/memory/SNSUserMemoryRepository.h
        sources/infrastructure/memory/SNSUserMemoryRepository.cpp
        headers/infrastructure/memory/VaccinationProcessMemoryRepository.h
        sources/infrastructure/memory/VaccinationProcessMemoryRepository.cpp
        headers/infrastructure/memory/WaitingRoomMemoryRepository.h
        sources/infrastructure/memory/WaitingRoomMemoryRepository.cpp
        headers/infrastructure/memory/RecoveryRoomMemoryRepository.h
        sources/infrastructure/memory/RecoveryRoomMemoryRepository.cpp
        headers/infrastructure/memory/UserArrivalMemoryRepository.h
        sources/infrastructure/memory/UserArrivalMemoryRepository.cpp
        headers/infrastructure/memory/VaccinationAppointmentMemoryRepository.h
        sources/infrastructure/memory/VaccinationAppointmentMemoryRepository.cpp
        headers/infrastructure/memory/VaccinationCenterMemoryRepository.h
        sources/infrastructure/memory/VaccinationCenterMemoryRepository.cpp
        headers/infrastructure/memory/VaccineTypeMemoryRepository.h
        sources/infrastructure/memory/VaccineTypeMemoryRepository.cpp

        # ui controllers
        headers/controllers/ui/CreateNewVaccineTypeController.h
        sources/controllers/ui/CreateNewVaccineTypeController.cpp
        sources/controllers/ui/RegisterVaccineController.cpp
        sources/controllers/ui/ListEmployeesByRoleController.cpp
        sources/controllers/ui/RegisterEmployeeController.cpp
        sources/controllers/ui/RegisterSNSUserController.cpp
        sources/controllers/ui/RegisterVaccinationCenterController.cpp
        sources/controllers/ui/RecordVaccinationController.cpp
        sources/controllers/ui/RegisterUserArrivalController.cpp
        sources/controllers/ui/App.cpp

        # rest api controllers
        headers/controllers/restapi/HttpStatus.h
        headers/controllers/restapi/HttpResult.h
        sources/controllers/restapi/HttpResult.cpp
        headers/controllers/restapi/RestController.h
        sources/controllers/restapi/RestController.cpp
        headers/controllers/restapi/VaccineTypeController.h
        sources/controllers/restapi/VaccineTypeController.cpp

        # Vaccine REST controller
        headers/controllers/restapi/VaccineController.h
        sources/controllers/restapi/VaccineController.cpp
        headers/controllers/restapi/SharedRepositoryFactory.h
)

target_include_directories(Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
