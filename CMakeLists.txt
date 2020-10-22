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
        Core/GameState.cpp
        Core/GameState.h
        Core/RunTimeClock.cpp
        Core/RunTimeClock.h
        Gui/Gui.cpp
        Gui/Gui.h
        Gui/PauseMenu.cpp
        Gui/PauseMenu.h
        Gui/CharacterTab.cpp
        Gui/CharacterTab.h
        Gui/ShopTab.cpp
        Gui/ShopTab.h
        Gui/PriestTab.cpp
        Gui/PriestTab.h
        Game/Entity.cpp
        Game/Entity.h
        Game/Player.cpp
        Game/Player.h
        Game/Enemy.cpp
        Game/Enemy.h
        Game/Buff.h
        Game/Buff.cpp
        Game/Inventory.cpp
        Game/Inventory.h
        Game/Item.cpp
        Game/Item.h
        Game/Spell.cpp
        Game/Spell.h
        Game/Stats.h
        Game/Stats.cpp
        Game/Npc.cpp
        Game/Npc.h
        Components/MovementComponent.cpp
        Components/MovementComponent.h
        Components/AnimationComponent.cpp
        Components/AnimationComponent.h
        Components/HitBoxComponent.cpp
        Components/HitBoxComponent.h
        Components/BuffComponent.cpp
        Components/BuffComponent.h
        Components/PopUpTextComponent.cpp
        Components/PopUpTextComponent.h
        Resources/ResourcesHandler.cpp
        Resources/ResourcesHandler.h
        Resources/Resource.cpp
        Resources/Resource.h
        )

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

#SFML CONFIG
set (SFML_DIR SFML_2.5.1/lib/cmake/SFML)
set(SFML_ROOT "SFML_2.5.1")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED COMPONENTS audio graphics window system)
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
include_directories(Resources)

#GOOGLE TEST CONFIG
add_subdirectory(unit_testing)