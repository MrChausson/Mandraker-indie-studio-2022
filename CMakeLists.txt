cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set the project name
project(bomberman)

include(cmake/Findraylib.cmake)
# add the executable
add_executable(${PROJECT_NAME}
# main #
src/main.cpp
# raylib_encap #
src/raylib_encap/raylib.cpp
# src/Example/Example.cpp
# SCENE #
src/Scene/Menu/Menu.cpp
src/Scene/Game/Game.cpp
src/Scene/SplashScreen/SplashScreen.cpp
src/Scene/Settings/Settings.cpp
src/Scene/CharacterSelector/CharacterSelector.cpp
# SYSTEMS #
src/ecs/Systems/Gravity/Gravity.cpp
src/ecs/Systems/Draw/Draw.cpp
src/ecs/Systems/Animation/Animation.cpp
src/ecs/Systems/MouseHover/MouseHover.cpp
src/ecs/Systems/MouseClick/MouseClick.cpp
src/ecs/Systems/Move/Move.cpp
src/ecs/Systems/Music_sys/Music_sys.cpp
src/ecs/Systems/Loading/Loading.cpp
src/ecs/Systems/Sound/SoundSystem.cpp
src/ecs/Systems/Bomber/Bomber.cpp
src/ecs/Systems/Player/Player.cpp
# Components #
src/ecs/IComponent/IComponent.cpp
src/ecs/Components/Breakable/Breakable.cpp
src/ecs/Components/Placable/Placable.cpp
src/ecs/Components/Drawable/Drawable.cpp
src/ecs/Components/Clickable/Clickable.cpp
src/ecs/Components/Animable/Animable.cpp
src/ecs/Components/Loadable/Loadable.cpp
src/ecs/Components/Collisionable/Collisionable.cpp
#src/ecs/Components/Boundable/Boundable.cpp
src/ecs/Components/Drawable/DrawableText.cpp
src/ecs/Components/Drawable/DrawableSprite.cpp
src/ecs/Components/Drawable/DrawableCube.cpp
src/ecs/Components/Drawable/DrawableCubeTexture.cpp
src/ecs/Components/Drawable/DrawableModel.cpp
src/ecs/Components/Drawable/DrawablePlane.cpp
src/ecs/Components/Hoverable/Hoverable.cpp
src/ecs/Components/Movable/Movable.cpp
src/ecs/Components/Musicable/Musicable.cpp
src/ecs/Components/CameraComponent/CameraComponent.cpp
src/ecs/Components/Soundable/Soundable.cpp
# Tools #
src/Tools/Button.cpp
# Entity #
src/ecs/Entity/Entity.cpp
# ECS MANAGER #
src/ecs/ECSManager/ECSManager.cpp
# Engine #
src/Engine/Engine.cpp
# Chrono #
src/Engine/Chrono/Chrono.cpp
)
include_directories(./_deps/raylib-src/src ./includes)

# foreach(i IN ITEMS raylib)
#if(NOT TARGET raylib)
#    message(FATAL_ERROR "raylib is not a target")
#endif()
target_link_libraries(${PROJECT_NAME} raylib)
