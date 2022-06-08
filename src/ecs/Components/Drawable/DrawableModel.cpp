/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** DrawableModel
*/

#include "DrawableModel.hpp"
#include "raylib.hpp"

DrawableModel::DrawableModel(std::vector<Texture2D> textures, std::string modelPath, std::vector<int> meshOrder)
{
    Raylib::Raylib_encap Raylib_encp;
    this->_model = Raylib_encp.LModel(modelPath);
    this->_type = DRAWABLE_TYPE_MODEL;
    this->_animsCount = 0;
    this->_anims = Raylib_encp.LoadMAnimations(modelPath, &this->_animsCount);

    for (int i = 0; i < textures.size(); i++) {
        Raylib_encp.SetMTexture(&this->_model.materials[i], MATERIAL_MAP_DIFFUSE, textures[i]);
        Raylib_encp.SetMMeshMaterial(&this->_model, meshOrder[i], i);
    }
    this->_animFrameCounter = 0;
}

DrawableModel::~DrawableModel()
{
}


Model DrawableModel::getModel()
{
    return this->_model;
}

//     Raylib_encp.SetMMeshMaterial(&model, 1, 0); // Robe
//     Raylib_encp.SetMMeshMaterial(&model, 2, 1); // Yeux
//     Raylib_encp.SetMMeshMaterial(&model, 3, 2);  // Main
//     Raylib_encp.SetMMeshMaterial(&model, 5, 3); // Chapeau
//     Raylib_encp.SetMMeshMaterial(&model, 0, 4); // tete
//     Raylib_encp.SetMMeshMaterial(&model, 4, 5); // Cheveux
