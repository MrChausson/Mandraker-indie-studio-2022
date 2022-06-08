/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** DrawableModel
*/

#ifndef DRAWABLEMODEL_HPP_
#define DRAWABLEMODEL_HPP_

#include <raylib.h>
#include <vector>
#include <string>
#include "Drawable.hpp"

class DrawableModel : public Drawable{
    public:
        DrawableModel(std::vector<Texture2D> textures, Model model, std::vector<int> meshOrder, int plan = 0);
        ~DrawableModel();
        Model getModel();
        Model *getPtrModel();

    protected:
    private:
        Model _model;
        ModelAnimation *_anims;
        int _animFrameCounter = 0;
        unsigned int _animsCount = 0;

    
};

#endif /* !DRAWABLEMODEL_HPP_ */