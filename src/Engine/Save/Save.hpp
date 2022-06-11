/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Save
*/

#ifndef SAVE_HPP_
    #define SAVE_HPP_
    #include "json/json.h"
    #include "../Engine.hpp"

class Save {
    public:
        Save(std::string file_to_save);
        ~Save();
        void save(ECSManager *ecs);

    protected:
    private:
};

#endif /* !SAVE_HPP_ */
