cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set the project name
project(FastBombing)

include(cmake/Findraylib.cmake)
# add the executable
add_executable(${PROJECT_NAME} src/main.cpp src/ecs/System/System.cpp  src/ecs/Components/Components.cpp  src/ecs/ConcretComponent/ConcretComponent.cpp  src/ecs/Entities/Entities.cpp src/Example/Example.cpp )
# foreach(i IN ITEMS raylib)
#if(NOT TARGET raylib)
#    message(FATAL_ERROR "raylib is not a target")
#endif()
target_link_libraries(${PROJECT_NAME} raylib)
