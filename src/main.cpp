#include "Engine/Engine.hpp"

int getFps(int ac, char **av)
{
    int fps = 60;
    std::string fps_input;
    if (ac == 2) {
        fps_input = av[1];
         for (int i = 0; i < fps_input.length(); i++)
            if (isdigit(fps_input[i]) == false)
                return 60;
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