cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set the project name
project(FastBombing)

include(cmake/Findraylib.cmake)
# add the executable
add_executable(${PROJECT_NAME}
# main #
src/main.cpp
# src/Example/Example.cpp
# SYSTEMS #
src/ecs/Systems/Gravity/Gravity.cpp
src/ecs/Systems/Draw/Draw.cpp
# Components #
src/ecs/Components/Breakable/Breakable.cpp
src/ecs/IComponent/IComponent.cpp
src/ecs/Components/Placable/Placable.cpp
src/ecs/Components/Drawable/Drawable.cpp
src/ecs/Components/Drawable/DrawableText.cpp
# Entity #
src/ecs/Entity/Entity.cpp
# ECS MANAGER #
src/ecs/ECSManager/ECSManager.cpp
# Engine #
src/Engine/Engine.cpp
# Chrono #
src/Engine/Chrono/Chrono.cpp
)
include_directories(./_deps/raylib-src/src)

# foreach(i IN ITEMS raylib)
#if(NOT TARGET raylib)
#    message(FATAL_ERROR "raylib is not a target")
#endif()
target_link_libraries(${PROJECT_NAME} raylib)
