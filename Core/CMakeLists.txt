project(Core)

add_library(Core
        headers/domain/shared/Result.h
        headers/domain/shared/StringUtils.h
        sources/domain/shared/Result.cpp
        sources/domain/shared/StringUtils.cpp
        headers/controllers/ui/CreateNewVaccineTypeController.h
        headers/domain/model/VaccineType.h
        sources/controllers/ui/App.cpp
        sources/controllers/ui/CreateNewVaccineTypeController.cpp
        sources/domain/model/VaccineType.cpp
        ../ConsoleApp/headers/views/CreateNewVaccineTypeView.h
        ../ConsoleApp/sources/views/CreateNewVaccineTypeView.cpp
        sources/domain/model/VaccineTypeContainer.cpp
        ../ConsoleApp/headers/views/MainView.h
        ../ConsoleApp/sources/views/MainView.cpp
        # US11 - Register Vaccine
        headers/domain/model/VaccineTechnology.h
        sources/domain/model/VaccineTechnology.cpp
        headers/domain/model/Vaccine.h
        sources/domain/model/Vaccine.cpp
        headers/domain/model/VaccineContainer.h
        sources/domain/model/VaccineContainer.cpp
        headers/controllers/ui/RegisterVaccineController.h
        sources/controllers/ui/RegisterVaccineController.cpp
        headers/controllers/ui/ListEmployeesByRoleController.h
        sources/controllers/ui/ListEmployeesByRoleController.cpp
        sources/domain/model/EmployeeContainer.cpp
        sources/domain/model/Employee.cpp
        sources/controllers/ui/RegisterEmployeeControllerRegisterEmployeeController.cpp
        ../ConsoleApp/sources/views/RegisterEmployeeView.cpp
        ../ConsoleApp/sources/views/ListEmployeesByRoleView.cpp
        # US20 - Register SNS user
        headers/domain/model/SNSUser.h
        sources/domain/model/SNSUser.cpp
        headers/domain/model/SNSUserContainer.h
        sources/domain/model/SNSUserContainer.cpp
        headers/controllers/ui/RegisterSNSUserController.h
        sources/controllers/ui/RegisterSNSUserControllerRegisterSNSUserController.cpp
        ../ConsoleApp/headers/views/RegisterSNSUserView.h
        ../ConsoleApp/sources/views/RegisterSNSUserView.cpp

        # Service/repository pattern files for SNS user registration
        headers/domain/repositories/SNSUserRepository.h
        headers/domain/repositories/RepositoryFactory.h
        headers/infrastructure/memory/MemoryRepositoryFactory.h
        sources/infrastructure/memory/MemoryRepositoryFactory.cpp
        headers/infrastructure/memory/SNSUserMemoryRepository.h
        sources/infrastructure/memory/SNSUserMemoryRepository.cpp
        headers/domain/services/SNSUserService.h
        sources/domain/services/SNSUserService.cpp
)