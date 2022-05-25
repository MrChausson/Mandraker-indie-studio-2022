#include "Engine/Engine.hpp"

//TODO: save pointers to components in Entities
//TODO: create a ECSManager to store everything

int getFps(int ac, char **av)
{
    int fps = 60;
    std::string fps_input;
    if (ac == 2) {
        fps_input = av[1];
         for (int i = 0; i < fps_input.length(); i++)
            if (isdigit(fps_input[i]) == false)
                return 60; //when one non numeric value is found, return false
        fps = std::stoi(fps_input);
    }
    return fps;
}

int main(int ac, char **av)
{
    int fps = getFps(ac, av);
    Engine engine(fps);
    
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