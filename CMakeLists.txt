cmake_minimum_required(VERSION 3.15)
set(PROJECT_NAME DragonSlayer)
project(${PROJECT_NAME})
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

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
        Core/BattleState.cpp
        Core/BattleState.h
        Core/Observer.h
        Core/Subject.h
        Core/Common.h
        Core/DebugTool.cpp
        Core/DebugTool.h
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
        Gui/SpellTab.cpp
        Gui/SpellTab.h
        Gui/WizardTab.cpp
        Gui/WizardTab.h
        Gui/libraries/RichText.hpp
        Gui/libraries/RichText.cpp
        Gui/SelectLevelTab.cpp
        Gui/SelectLevelTab.h
        Gui/AchievementTab.cpp
        Gui/AchievementTab.h
        Gui/LoadSaveTab.cpp
        Gui/LoadSaveTab.h
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
        Game/Utils.h
        Game/Utils.cpp
        Game/BattleResult.h
        Game/BattleResult.cpp
        Game/LootGenerator.cpp
        Game/LootGenerator.h
        Game/LootBag.h
        Game/LootBag.cpp
        Game/Achievement.cpp
        Game/Achievement.h
        Game/Save.cpp
        Game/Save.h
        Components/MovementComponent.cpp
        Components/MovementComponent.h
        Components/AnimationComponent.cpp
        Components/AnimationComponent.h
        Components/HitBoxComponent.cpp
        Components/HitBoxComponent.h
        Components/BuffComponent.cpp
        Components/BuffComponent.h
        Components/SpellComponent.cpp
        Components/SpellComponent.h
        Components/PopUpTextComponent.cpp
        Components/PopUpTextComponent.h
        Components/CollisionBoxComponent.cpp
        Components/CollisionBoxComponent.h
        Components/AchievementComponent.cpp
        Components/AchievementComponent.h
        Components/AchievementsEnum.h
        Resources/ResourcesHandler.cpp
        Resources/ResourcesHandler.h
        Resources/Resource.cpp
        Resources/Resource.h
        Resources/SavesHandler.cpp
        Resources/SavesHandler.h
        Resources/EnemySaveData.cpp
        Resources/EnemySaveData.h
        Resources/LootBagSaveData.cpp
        Resources/LootBagSaveData.h
        Map/Map.cpp
        Map/Map.h
        Map/MapGenerator.h
        Map/MapGenerator.cpp
        Map/Tile.h
        Map/Tile.cpp
        Map/Dungeon.cpp
        Map/Dungeon.h
        Map/Node.cpp
        Map/Node.h
        Map/PathFinder.cpp
        Map/PathFinder.h
        Map/MiniMap.cpp
        Map/MiniMap.h
        Shader/fragment_shader.frag
        Shader/vertex_shader.vert
        AI/AIBehaviour.cpp
        AI/AIBehaviour.h
        AI/BattleAI.cpp
        AI/BattleAI.h)

include_directories(Resources)
link_directories(SFML_2.5.1/bin)
include_directories ("lib")

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    add_executable(${PROJECT_NAME} WIN32 ${SOURCE_FILES})
else ()
    add_executable(${PROJECT_NAME} ${SOURCE_FILES})
endif ()

#SFML CONFIG
set(SFML_DIR SFML_2.5.1/lib/cmake/SFML)
set(SFML_ROOT "SFML_2.5.1")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED COMPONENTS audio graphics window system)
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

#GOOGLE TEST CONFIG
add_subdirectory(unit_testing)