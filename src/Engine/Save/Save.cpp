/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Save
*/

#include "../../ecs/Components/Timable/Timable.hpp"
#include "../../ecs/Components/Animable/Animable.hpp"
#include "../../ecs/Components/CameraComponent/CameraComponent.hpp"
#include "../../ecs/Components/Timable/Timable.hpp"
#include "../../ecs/Components/Collisionable/Collisionable.hpp"
#include "../../ecs/Components/Drawable/DrawableCube.hpp"
#include "../../ecs/Components/Drawable/DrawableCubeTexture.hpp"
#include "../../ecs/Components/Drawable/DrawablePlane.hpp"
#include "../../ecs/Components/Drawable/DrawableSprite.hpp"
#include "../../ecs/Components/Drawable/DrawableText.hpp"
#include "../../ecs/Components/Movable/Movable.hpp"
#include "Save.hpp"

Save::Save(std::string file_to_save)
{
    this->_fileToSaveTo = file_to_save;
}

Save::~Save()
{
}

void Save::save(std::vector<Entity *> entities)
{
    std::stringstream buffer;
    std::ofstream savefile(this->_fileToSaveTo, std::fstream::trunc);
    Drawable *drawable;
    Timable *timable;
    Placable *placable;
    Movable *movable;
    Animable *animable;
    CameraComponent *camera;
    DrawableCube *drawableCube;
    DrawableCubeTexture *drawableCubeTexture;
    DrawableModel *drawableModel;
    DrawablePlane *drawablePlane;
    DrawableSprite *drawableSprite;
    DrawableText *drawableText;
    Rectangle tmp_rect;
    Vector3 tmp_vector3;
    DRAWABLE_TYPE tmp_drawable_type;

    if (!savefile.is_open())
        throw Error_file("Error while opening save file");
    for (Entity *entity : entities) {
        buffer << std::to_string(entity->getId()) << std::endl;
        for (IComponent *component : entity->getComponents()) {
            if (component->getType() == TIMABLE) {
                timable = static_cast<Timable *>(component);
                buffer << "Timable" << std::endl;
                buffer << std::to_string(timable->getTimeLeft()) << std::endl;
            } else if (component->getType() == PLACABLE) {
                placable = static_cast<Placable *>(component);
                buffer << "Placable" << std::endl;
                buffer << std::to_string(placable->getX()) << std::endl;
                buffer << std::to_string(placable->getY()) << std::endl;
                buffer << std::to_string(placable->getZ()) << std::endl;
                buffer << std::to_string(placable->getRotationAxis().x) << std::endl;
                buffer << std::to_string(placable->getRotationAxis().y) << std::endl;
                buffer << std::to_string(placable->getRotationAxis().z) << std::endl;
                buffer << std::to_string(placable->getRotationAngle()) << std::endl;
                buffer << std::to_string(placable->getScale().x) << std::endl;
                buffer << std::to_string(placable->getScale().y) << std::endl;
                buffer << std::to_string(placable->getScale().z) << std::endl;
            } else if (component->getType() == MOVABLE) {
                movable = static_cast<Movable *>(component);
                buffer << "Movable" << std::endl;
                buffer << std::to_string(movable->getSpeed()) << std::endl;
                buffer << std::to_string(movable->getMovableType()) << std::endl;
            } else if (component->getType() == ANIMABLE) {
                animable = static_cast<Animable *>(component);
                buffer << "Animable" << std::endl;
                buffer << std::to_string(animable->getAnimationType()) << std::endl;
                buffer << animable->getPathToFile() << std::endl;
            } else if (component->getType() == CAMERA) {
                camera = static_cast<CameraComponent *>(component);
                buffer << "Camera" << std::endl;
                tmp_vector3 = camera->getPosition();
                buffer << std::to_string(tmp_vector3.x) << std::endl;
                buffer << std::to_string(tmp_vector3.y) << std::endl;
                buffer << std::to_string(tmp_vector3.z) << std::endl;
                tmp_vector3 = camera->getTarget();
                buffer << std::to_string(tmp_vector3.x) << std::endl;
                buffer << std::to_string(tmp_vector3.y) << std::endl;
                buffer << std::to_string(tmp_vector3.z) << std::endl;
                tmp_vector3 = camera->getUp();
                buffer << std::to_string(tmp_vector3.x) <<  std::endl;
                buffer << std::to_string(tmp_vector3.y) << std::endl;
                buffer << std::to_string(tmp_vector3.z) << std::endl;
                buffer << std::to_string(camera->getFov()) << std::endl;
                buffer << std::to_string(camera->getProjection()) << std::endl;
            } else if (component->getType() == DRAWABLE) {
                drawable = static_cast<Drawable *>(component);
                buffer << "Drawable" << std::endl;
                drawable->getPlan();
                tmp_drawable_type = drawable->getComponentType();
                buffer << std::to_string(tmp_drawable_type) << std::endl;
                if (tmp_drawable_type == DRAWABLE_TYPE_CUBE) {
                    drawableCube = static_cast<DrawableCube *>(drawable);
                    buffer << std::to_string(drawableCube->getColor().r) << std::endl;
                    buffer << std::to_string(drawableCube->getColor().g) << std::endl;
                    buffer << std::to_string(drawableCube->getColor().b) << std::endl;
                    buffer << std::to_string(drawableCube->getColor().a) << std::endl;
                } else if (tmp_drawable_type == DRAWABLE_TYPE_TEXTURE_CUBE) {
                    drawableCubeTexture = static_cast<DrawableCubeTexture *>(drawable);
                    buffer << std::to_string(drawableCubeTexture->getCubeTextureType()) << std::endl;
                    buffer << std::to_string(drawableCubeTexture->getHeight()) << std::endl;
                    buffer << std::to_string(drawableCubeTexture->getWidth()) << std::endl;
                    buffer << std::to_string(drawableCubeTexture->getLength()) << std::endl;
                    buffer << std::to_string(drawableCubeTexture->getColor().r) << std::endl;
                    buffer << std::to_string(drawableCubeTexture->getColor().g) << std::endl;
                    buffer << std::to_string(drawableCubeTexture->getColor().b) << std::endl;
                    buffer << std::to_string(drawableCubeTexture->getColor().a) << std::endl;
                } else if (tmp_drawable_type == DRAWABLE_TYPE_TEXT) {
                    drawableText = static_cast<DrawableText *>(drawable);
                    buffer << drawableText->getText() << std::endl;
                } else if (tmp_drawable_type == DRAWABLE_TYPE_PLANE) {
                    drawablePlane = static_cast<DrawablePlane *>(drawable);
                    buffer << std::to_string(drawablePlane->getColor().r) << std::endl;
                    buffer << std::to_string(drawablePlane->getColor().g) << std::endl;
                    buffer << std::to_string(drawablePlane->getColor().b) << std::endl;
                    buffer << std::to_string(drawablePlane->getColor().a) << std::endl;
                } else if (tmp_drawable_type == DRAWABLE_TYPE_MODEL) {
                    drawableModel = static_cast<DrawableModel *>(drawable);
                    buffer << drawableModel->getModelType() << std::endl;
                }
                }
            }
    }
    savefile << buffer.str();
    savefile.close();
}

std::unique_ptr<IComponent> Save::saveTimable(std::vector<std::string> lines)
{
    std::unique_ptr<IComponent> component = std::make_unique<Timable>(std::stoi(lines[0]));
    return component;
}

std::unique_ptr<IComponent> Save::savePlacable(std::vector<std::string> lines)
{
    Vector3 rot = {std::stof(lines[3]), std::stof(lines[4]), std::stof(lines[5])};
    float angle = std::stof(lines[6]);
    Vector3 scale = {std::stof(lines[7]), std::stof(lines[8]), std::stof(lines[9])};
    std::unique_ptr<IComponent> component = std::make_unique<Placable>
    (std::stof(lines[0]), std::stof(lines[1]), std::stof(lines[2]), rot, angle, scale);
    return component;
}

std::unique_ptr<IComponent> Save::saveMovable(std::vector<std::string> lines)
{
    float speed = std::stof(lines[0]);
    int movable_type = std::stoi(lines[1]);
    std::unique_ptr<IComponent> component = std::make_unique<Movable>(speed, (MOVABLE_TYPE) movable_type);
    return component;
}

std::vector<std::unique_ptr<Entity>> Save::load()
{
    std::vector<std::unique_ptr<Entity>> entities;
    std::ifstream savefile;
    Drawable *drawable;
    Timable *timable;
    Placable *placable;
    Movable *movable;
    Animable *animable;
    CameraComponent *camera;
    DrawableCube *drawableCube;
    DrawableCubeTexture *drawableCubeTexture;
    DrawableModel *drawableModel;
    DrawablePlane *drawablePlane;
    DrawableSprite *drawableSprite;
    DrawableText *drawableText;
    std::string line;
    std::vector <std::string> lines;
    std::unique_ptr<Entity> entity;

    savefile.open(this->_fileToSaveTo);
    if (!savefile.is_open())
        throw Error_file("Could not open file to load");
    while (getline(savefile, line)) {
        lines.clear();
        entity = std::make_unique<Entity>(std::stoi(line));
        getline(savefile, line);
        if (line == "Timable") {
            for (int i = 0; i < 1; i++) {
                getline(savefile, line);
                lines.push_back(line);
            }
            entity.get()->addComponent(saveTimable(lines));
        } else if (line == "Placable") {
            for (int i = 0; i < 10; i++) {
                getline(savefile, line);
                lines.push_back(line);
            }
            entity.get()->addComponent(savePlacable(lines));
        } else if (line == "Movable") {
            for (int i = 0; i < 2; i++) {
                getline(savefile, line);
                lines.push_back(line);
            }
            entity.get()->addComponent(saveMovable(lines));
        }
        entities.push_back(std::move(entity));
    }
    return entities;
}