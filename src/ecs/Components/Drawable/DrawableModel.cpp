/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** DrawableModel
*/

#include "DrawableModel.hpp"
#include "raylib.hpp"

DrawableModel::DrawableModel(std::vector<Texture2D> textures, Model model, std::vector<int> meshOrder, int plan, ModelType modelType)
{
    this->_model = model;
    this->_type = DRAWABLE_TYPE_MODEL;
    this->_plan = plan;
    this->_modelType = modelType;
    Raylib::Raylib_encap Raylib_encp;

    for (int i = 0; i < textures.size(); i++) {
        Raylib_encp.SetMTexture(&this->_model.materials[i], MATERIAL_MAP_DIFFUSE, textures[i]);
        Raylib_encp.SetMMeshMaterial(&this->_model, meshOrder[i], i);
    }
}

DrawableModel::~DrawableModel()
{
}


Model DrawableModel::getModel()
{
    return this->_model;
}

Model *DrawableModel::getPtrModel()
{
    return &this->_model;
}

int DrawableModel::getModelType()
{
    return ((int) this->_modelType);
}