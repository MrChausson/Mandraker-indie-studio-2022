/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** DrawableModel
*/

#include "DrawableModel.hpp"

DrawableModel::DrawableModel(std::vector<Texture2D> textures, std::string modelPath, std::vector<int> meshOrder)
{
    this->_model = LoadModel(modelPath.c_str());
    this->_type = DRAWABLE_TYPE_MODEL;
    this->_animsCount = 0;
    this->_anims = LoadModelAnimations(modelPath.c_str(), &this->_animsCount);

    for (int i = 0; i < textures.size(); i++) {
        SetMaterialTexture(&this->_model.materials[i], MATERIAL_MAP_DIFFUSE, textures[i]);
        SetModelMeshMaterial(&this->_model, meshOrder[i], i);
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

//     SetModelMeshMaterial(&model, 1, 0); // Robe
//     SetModelMeshMaterial(&model, 2, 1); // Yeux
//     SetModelMeshMaterial(&model, 3, 2);  // Main
//     SetModelMeshMaterial(&model, 5, 3); // Chapeau
//     SetModelMeshMaterial(&model, 0, 4); // tete
//     SetModelMeshMaterial(&model, 4, 5); // Cheveux
