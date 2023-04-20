cmake_minimum_required(VERSION 3.0.0)
project(Elevator VERSION 0.1.0)

set(SRC_LIST src/main.cpp src/elevator.cpp src/elevsystem.cpp src/person.cpp)
set(CMAKE_BUILD_TYPE Debug)
include_directories(${CMAKE_SOURCE_DIR}/include)
add_executable(main ${SRC_LIST})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
