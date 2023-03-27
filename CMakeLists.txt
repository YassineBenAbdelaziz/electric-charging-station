cmake_minimum_required(VERSION 3.0.0)
project(charging_station VERSION 0.1.0)

include(CTest)
enable_testing()


file(GLOB_RECURSE SRC_FILES src/*.cpp )
add_executable(charging_station main.cpp ${SRC_FILES})
target_include_directories(charging_station PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)