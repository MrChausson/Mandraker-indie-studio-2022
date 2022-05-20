#include "../_deps/raylib-src/src/raylib.h"
#include "Example/Example.hpp"
#include "../includes/ecs.hpp"
#include "ecs/Components/Components.hpp"
#include "ecs/System/System.hpp"

//TODO: save pointers to components in Entities
//TODO: create a ECSManager to store everything

int main()
{
    // Example testexample;
    // Entities entities =  testexample.CreatingRemovingEntities();
    // Entity entity = entities.getEntities()[6];
    // std::cout << "Entity: " << entity << std::endl;
    // Component component(entity);
    // std::cout << component.entity() << std::endl;
    // System System<component>();
}

// int main(void)
// {
//     const int screenWidth = 800;
//     const int screenHeight = 450;

//     InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

//     SetTargetFPS(60);

//     while (!WindowShouldClose())
//     {
//         BeginDrawing();

//             ClearBackground(RAYWHITE);

//             DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

//         EndDrawing();
//     }
//     CloseWindow();

//     return 0;
// }