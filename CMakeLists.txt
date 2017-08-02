cmake_minimum_required(VERSION 3.6)
project(Humanity)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -lSDL2 -lSDL2_image -lSDL2_mixer")

set(SOURCE_FILES main.cpp src/Game.cpp src/Game.h src/Scene/Scene.h src/Scene/SceneType.h src/Scene/TitleScene/TitleScene.cpp src/Scene/TitleScene/TitleScene.h src/GameDefs.h src/Scene/BattleScene/BattleScene.cpp src/Scene/BattleScene/BattleScene.h src/Scene/SceneExitStatus.h src/Scene/TitleScene/TitleMessage.cpp src/Scene/TitleScene/TitleMessage.h src/tools/Timer.cpp src/Scene/TitleScene/TitleMessage.h src/tools/Timer.h src/tools/SDL_helper.cpp src/tools/SDL_helper.h src/Scene/Part.cpp src/Scene/Part.h src/Scene/PartExitStatus.h src/Scene/BattleScene/BeginningPart.cpp src/Scene/BattleScene/BeginningPart.h src/Scene/BattleScene/Components.cpp src/Scene/BattleScene/Components.h src/Scene/BattleScene/EnemyEmergingPart.cpp src/Scene/BattleScene/EnemyEmergingPart.h src/GameDefs.cpp src/Scene/BattleScene/Character/Character.cpp src/Scene/BattleScene/Character/Character.h src/Scene/BattleScene/Character/AttackType.h)
add_executable(Humanity ${SOURCE_FILES})