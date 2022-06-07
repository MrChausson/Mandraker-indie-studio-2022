/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** DrawableModel
*/

#include "DrawableModel.hpp"

DrawableModel::DrawableModel(std::vector<Texture2D> textures, Model model, std::vector<int> meshOrder)
{
    this->_model = model;
    this->_type = DRAWABLE_TYPE_MODEL;

    for (int i = 0; i < textures.size(); i++) {
        SetMaterialTexture(&this->_model.materials[i], MATERIAL_MAP_DIFFUSE, textures[i]);
        SetModelMeshMaterial(&this->_model, meshOrder[i], i);
    }
}

DrawableModel::~DrawableModel()
{
}


Model DrawableModel::getModel()
{
    return this->_model;
}