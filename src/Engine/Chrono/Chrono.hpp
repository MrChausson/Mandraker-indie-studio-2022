/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Chrono
*/

#ifndef CHRONO_HPP_
    #define CHRONO_HPP_
    #include <chrono>
    #include <thread>
    #ifdef _WIN32
        #include <windows.h>
    #endif
    #ifdef linux
        #include <unistd.h>
    #endif

class Chrono {
    public:
        Chrono(int fps = 60);
        ~Chrono();
        void init();
        void startLoop();
        void sleepEndLoop();
        void setFps(int fps);

    protected:
    private:
        std::chrono::time_point<std::chrono::system_clock> _start;
        std::chrono::time_point<std::chrono::system_clock>  _end;
        std::chrono::duration<double> _elapsedSeconds;
        std::chrono::duration<double> _toSleep;
        std::chrono::duration<double> _saveStart;
};

#endif /* !CHRONO_HPP_ */
