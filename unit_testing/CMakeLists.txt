cmake_minimum_required(VERSION 3.15)
# 'unit_testing' is the subproject name
project(unit_testing)
set(SOURCE_FILES
        mainTest.cpp
        Tests.cpp
        ../Core/Game.cpp
        ../Core/Game.h
        ../Core/State.cpp
        ../Core/State.h
        ../Core/MainMenuState.cpp
        ../Core/MainMenuState.h
        ../Core/GameState.cpp
        ../Core/GameState.h
        ../Core/RunTimeClock.cpp
        ../Core/RunTimeClock.h
        ../Gui/Gui.cpp
        ../Gui/Gui.h
        ../Gui/PauseMenu.cpp
        ../Gui/PauseMenu.h
        ../Gui/CharacterTab.cpp
        ../Gui/CharacterTab.h
        ../Game/Entity.cpp
        ../Game/Entity.h
        ../Game/Player.cpp
        ../Game/Player.h
        ../Game/Enemy.cpp
        ../Game/Enemy.h
        ../Game/Buff.h
        ../Game/Buff.cpp
        ../Game/Inventory.cpp
        ../Game/Inventory.h
        ../Game/Item.cpp
        ../Game/Item.h
        ../Game/Spell.cpp
        ../Game/Spell.h
        ../Game/Stats.h
        ../Game/Stats.cpp
        ../Components/MovementComponent.cpp
        ../Components/MovementComponent.h
        ../Components/AnimationComponent.cpp
        ../Components/AnimationComponent.h
        ../Components/HitBoxComponent.cpp
        ../Components/HitBoxComponent.h
        ../Components/BuffComponent.cpp
        ../Components/BuffComponent.h
        ../Components/PopUpTextComponent.cpp
        ../Components/PopUpTextComponent.h
        ../Resources/ResourcesHandler.cpp
        ../Resources/ResourcesHandler.h
        ../Resources/Resource.cpp
        ../Resources/Resource.h
        )
# 'lib' is the folder with Google Test sources
add_subdirectory(lib/googletest-master)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(unit_testing_run ${SOURCE_FILES})

set(SFML_ROOT "../SFML_2.5.1")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED COMPONENTS audio graphics window system)

target_link_libraries(unit_testing_run gtest gtest_main sfml-system sfml-window sfml-graphics sfml-audio sfml-network)