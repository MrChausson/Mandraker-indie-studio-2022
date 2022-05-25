#include "Engine/Engine.hpp"

//TODO: save pointers to components in Entities
//TODO: create a ECSManager to store everything

int main()
{
    Engine engine;
    engine.game_loop();
    return (0);
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