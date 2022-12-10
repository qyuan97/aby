cmake_minimum_required (VERSION 3.15)
project (Secure-PoSt)
set(NAME "Secure-PoSt")
set (CMAKE_CXX_STANDARD 11)

find_package(ABY QUIET)
if (ABY_FOUND)
    message(STATUS "Found ABY")
elseif (NOT ABY_FOUND AND NOT TARGET ABY::aby)
    message("ABY was not found: add ABY subdirectory")
    if (NOT EXISTS "${PROJECT_SOURCE_DIR}/extern/ABY/CMakeLists.txt")
        find_package(Git REQUIRED)
        message("initialize Git submodule: extern/ABY")
        execute_process(COMMAND git submodule update --init extern/ABY
                WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}")
    endif ()
    add_subdirectory(extern/ABY)
endif ()

add_executable(my_application myapplication.cpp)
target_link_libraries(my_application ABY::aby)

