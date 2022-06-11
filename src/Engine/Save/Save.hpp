/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Save
*/

#ifndef SAVE_HPP_
    #define SAVE_HPP_
    #include "../../ecs/Entity/Entity.hpp"

class Save {
    public:
        Save(std::string file_to_save);
        ~Save();
        void save(std::vector<Entity *> entities);

    protected:
    private:
        std::string _fileToSaveTo;
};

#endif /* !SAVE_HPP_ */
