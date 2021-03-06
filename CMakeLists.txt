cmake_minimum_required(VERSION 3.5)
project(Humanity)

#-lSDL2 -lSDL2_image -lSDL2_mixer
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z")

set(SOURCE_FILES main.cpp src/Game.cpp src/Game.h src/Scene/Scene.h src/Scene/SceneType.h src/Scene/TitleScene/TitleScene.cpp src/Scene/TitleScene/TitleScene.h src/GameDefs.h src/Scene/BattleScene/BattleScene.cpp src/Scene/BattleScene/BattleScene.h src/Scene/SceneExitStatus.h src/Scene/TitleScene/TitleMessage.cpp src/Scene/TitleScene/TitleMessage.h src/tools/Timer.cpp src/Scene/TitleScene/TitleMessage.h src/tools/Timer.h src/tools/SDL_helper.cpp src/tools/SDL_helper.h src/Scene/Part.h src/Scene/PartExitStatus.h src/Scene/BattleScene/BeginningPart.cpp src/Scene/BattleScene/BeginningPart.h src/Scene/BattleScene/Components.cpp src/Scene/BattleScene/Components.h src/Scene/BattleScene/EnemyAppearancePart.cpp src/Scene/BattleScene/EnemyAppearancePart.h src/GameDefs.cpp src/Scene/BattleScene/Character/Enemy/EnemyStatus.h src/Scene/BattleScene/Character/Enemy/TestEnemy/TestEnemy.cpp src/Scene/BattleScene/Character/Enemy/TestEnemy/TestEnemy.h src/Scene/BattleScene/Character/Enemy/TestEnemy/TestEnemyNeutral.cpp src/Scene/BattleScene/Character/Enemy/TestEnemy/TestEnemyNeutral.h src/Scene/BattleScene/Character/Enemy/Enemy.h src/Scene/BattleScene/Character/Enemy/TestEnemy/TestEnemyAppearing.cpp src/Scene/BattleScene/Character/Enemy/TestEnemy/TestEnemyAppearing.h src/Scene/BattleScene/BattleSceneDefs.cpp src/Scene/BattleScene/BattleSceneDefs.h src/Scene/BattleScene/Character/Enemy/EnemyStatus.cpp)
add_executable(Humanity.out ${SOURCE_FILES})

find_package(PkgConfig REQUIRED)
pkg_check_modules(SDL2 sdl2 REQUIRED)
pkg_check_modules(SDL2image SDL2_image REQUIRED)
pkg_check_modules(SDL2mixer SDL2_mixer REQUIRED)
pkg_check_modules(SDL2ttf SDL2_ttf REQUIRED)

target_include_directories(Humanity.out PRIVATE
        ${SDL2_INCLUDE_DIR}
        ${SDL2image_INCLUDE_DIR}
        ${SDL2mixer_INCLUDE_DIR}
        ${SDL2ttf_INCLUDE_DIR})
target_link_libraries(Humanity.out
        ${SDL2_LIBRARIES}
        ${SDL2image_LIBRARIES}
        ${SDL2mixer_LIBRARIES}
        ${SDL2ttf_LIBRARIES})