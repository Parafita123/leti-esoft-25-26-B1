project(CoreTests)
add_subdirectory(lib)
include_directories(${gtestSOURCE_DIR}/include ${gtest_SOURCE_DIR} ${gmock_SOURCE_DIR}/include ${gmock_SOURCE_DIR})

add_executable(CoreTests domain/model/CategoryTests.cpp infrastructure/memory/CategoryMemoryRepositoryTests.cpp domain/shared/StringUtilsTests.cpp domain/model/PersonTests.cpp controllers/ui/CreateCategoryControllerTests.cpp domain/repositories/RepositoryFactoryMock.h domain/repositories/CategoryRepositoryMock.h domain/services/CategoryServiceMock.h domain/services/CategoryServiceTests.cpp)

target_link_libraries(CoreTests TCore)
target_link_libraries(CoreTests gmock gtest gtest_main)