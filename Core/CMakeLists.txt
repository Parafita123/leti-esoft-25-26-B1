project(Core)

add_library(Core headers/domain/shared/Result.h headers/domain/shared/StringUtils.h sources/domain/shared/Result.cpp sources/domain/shared/StringUtils.cpp
        headers/controllers/ui/CreateNewVaccineTypeController.h
        headers/domain/model/VaccineType.h
        sources/controllers/ui/App.cpp
        sources/controllers/ui/CreateNewVaccineTypeController.cpp
        sources/domain/model/VaccineType.cpp
        ../ConsoleApp/headers/views/CreateNewVaccineTypeView.h
        ../ConsoleApp/sources/views/CreateNewVaccineTypeView.cpp
        sources/domain/model/VaccineTypeContainer.cpp
        ../ConsoleApp/headers/views/MainView.h
        ../ConsoleApp/sources/views/MainView.cpp)