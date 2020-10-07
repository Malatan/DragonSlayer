cmake_minimum_required(VERSION 3.15)
set(PROJECT_NAME DragonSlayer)
project(${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 14)
set(SOURCE_FILES
        main.cpp
        Core/Game.cpp
        Core/Game.h
        Core/State.cpp
        Core/State.h
        Core/MainMenuState.cpp
        Core/MainMenuState.h
        Gui/Gui.cpp
        Gui/Gui.h
        )

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

#SFML CONFIG
set(SFML_ROOT "../SFML_2.5.1")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED COMPONENTS audio graphics window system)
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

#GOOGLE TEST CONFIG
add_subdirectory(unit_testing)