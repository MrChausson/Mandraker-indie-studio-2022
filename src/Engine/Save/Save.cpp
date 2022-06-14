/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Save
*/

#include "raylib.hpp"
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
#include "../../ecs/Components/Breakable/Breakable.hpp"
#include "Save.hpp"

Save::Save(std::string file_to_save)
{
    Raylib::Raylib_encap r;
    this->_fileToSaveTo = file_to_save;
    this->_grassTexture = r.LTexture("assets/meterials/grass.png");
    this->_stoneTexture = r.LTexture("assets/materials/game/stone.png");
    // Creating vector texture and the mesh order for mcg
    this->_textures_mcg = {
        r.LTexture("assets/models/mcg/c_McGonagall_Body_Diffuse_v1@4x.png"),
        r.LTexture("assets/models/mcg/c_McGonagall_eyes_Diffuse_v1@4x.png"),
        r.LTexture("assets/models/mcg/c_McGonagall_hands_Diffuse_v1@4x.png"),
        r.LTexture("assets/models/mcg/c_McGonagall_Hat_Diffuse_v1@4x.png"),
        r.LTexture("assets/models/mcg/c_McGonagall_Head_Diffuse_v1@4x.png"),
        r.LTexture("assets/models/mcg/glass.png")
    };
    this->_meshOrder_mcg = {
        1, 2, 3, 5, 0, 4
    };

    //sprout
        this->_textures_sprout = {
        r.LTexture("assets/models/sprout/Sprout_body_diffuse_v1@4x.png"),
        r.LTexture("assets/models/sprout/Sprout_cloak_diffuse_v1@4x.png"),
        r.LTexture("assets/models/sprout/Sprout_eyes_diffuse_v1@4x.png"),
        r.LTexture("assets/models/sprout/Sprout_face_diffuse_v1@4x.png"),
        r.LTexture("assets/models/sprout/Sprout_hair_diffuse_v1@4x.png"),
        r.LTexture("assets/models/sprout/Sprout_hand_diffuse_v1@4x.png"),
        r.LTexture("assets/models/sprout/Sprout_hat_diffuse_v1@4x.png")
    };
    this->_meshOrder_sprout = {
        1, 5, 4, 0, 6, 3, 2
    };

        // Creating Model , vector texture and the mesh order for Trelawney
    this->_texturesTre = {
        r.LTexture("assets/models/trelawney/ProfTrelawney_accessory_diffuse_v1@4x.png"),
        r.LTexture("assets/models/trelawney/ProfTrelawney_body_diffuse_v1@4x.png"),
        r.LTexture("assets/models/trelawney/Trelawney_face_diffuse_v1@4x.png"),
        r.LTexture("assets/models/trelawney/Trelawney_hair_diffuse_v1@4x.png"),
        r.LTexture("assets/models/trelawney/Trelawney_hands_diffuse_v1@4x.png"),
        r.LTexture("assets/models/trelawney/Trelawney_eyes_diffuse_v1@4x.png")
    };
    this->_meshOrderTrelawney = {
        2, 1, 0, 6, 3, 4
    };

    // Creating Model , vector texture and the mesh order for Snape
    this->_textures_snape = {
        r.LTexture("assets/models/snape/c_Snape_Hair_diffuse_v3@4x.png"),
        r.LTexture("assets/models/snape/c_Snape_Hands_diffuse_v8@4x.png"),
        r.LTexture("assets/models/snape/c_Snape_Head_diffuse_v3@4x.png"),
        r.LTexture("assets/models/snape/c_Snape_Outfit_diffuse_v3@4x.png"),
        r.LTexture("assets/models/snape/EyesBW_v169@4x.png")
    };
    this->_meshOrderSnape = {
       4, 3, 0, 2, 1
    };
    this->_texturesGnome = {
        r.LTexture("assets/models/gnome/gnome_DIF_v1@4x.png"),
        r.LTexture("assets/models/gnome/GnomeHoles_DIF_v1@4x.png")
    };
    this->_texture_gnome_mesh_order = {
        0, 2
    };
    this->_texturesBag = {
        r.LTexture("assets/models/bag/p_FertiliserBag_Diffuse_v1@4x.png")
    };
    this->_textureBagMeshOrder = {
        0
    };
    this->_mgmModel = r.LModel("assets/models/mcg/mcg.iqm");
    this->_snapeModel.transform = r.MatrixRotZ(0.6);
    this->_snapeModel = r.LModel("assets/models/snape/snape.iqm");
    this->_snapeModel.transform = r.MatrixRotZ(0.6);
    this->_sproutModel = r.LModel("assets/models/sprout/sprout.iqm");
    this->_sproutModel.transform = r.MatrixRotZ(0.6);
    this->_trelawneyModel = r.LModel("assets/models/trelawney/trelawney.iqm");
    this->_trelawneyModel.transform = r.MatrixRotZ(0.6);
    this->_gnomeModel = r.LModel("assets/models/gnome/gnome.iqm");
    this->_gnomeModel.transform = MatrixRotateX(1.55);
    this->_bagModel = r.LModel("assets/models/bag/bag.obj");
    this->_font = r.LFontEx("assets/fonts/wizarding.ttf", 100, 0, 0);
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
    Breakable *breakable;
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
            } else if (component->getType() == BREAKABLE) {
                buffer << "Breakable" << std::endl;
            } else if (component->getType() == DRAWABLE &&
            static_cast<Drawable *>(component)->getComponentType() != DRAWABLE_TYPE_SPRITE) {
                drawable = static_cast<Drawable *>(component);
                drawable->getPlan();
                tmp_drawable_type = drawable->getComponentType();
                buffer << "Drawable" << std::endl;
                buffer << std::to_string(tmp_drawable_type) << std::endl;
                if (tmp_drawable_type == DRAWABLE_TYPE_CUBE) {
                    drawableCube = static_cast<DrawableCube *>(drawable);
                    buffer << std::to_string(drawableCube->getColor().r) << std::endl;
                    buffer << std::to_string(drawableCube->getColor().g) << std::endl;
                    buffer << std::to_string(drawableCube->getColor().b) << std::endl;
                    buffer << std::to_string(drawableCube->getColor().a) << std::endl;
                    buffer << std::to_string(drawableCube->getWidth()) << std::endl;
                    buffer << std::to_string(drawableCube->getHeight()) << std::endl;
                    buffer << std::to_string(drawableCube->getLength()) << std::endl;
                } else if (tmp_drawable_type == DRAWABLE_TYPE_TEXTURE_CUBE) {
                    drawableCubeTexture = static_cast<DrawableCubeTexture *>(drawable);
                    buffer << std::to_string(drawableCubeTexture->getColor().r) << std::endl;
                    buffer << std::to_string(drawableCubeTexture->getColor().g) << std::endl;
                    buffer << std::to_string(drawableCubeTexture->getColor().b) << std::endl;
                    buffer << std::to_string(drawableCubeTexture->getColor().a) << std::endl;
                    buffer << std::to_string(drawableCubeTexture->getWidth()) << std::endl;
                    buffer << std::to_string(drawableCubeTexture->getHeight()) << std::endl;
                    buffer << std::to_string(drawableCubeTexture->getLength()) << std::endl;
                    buffer << std::to_string(drawableCubeTexture->getCubeTextureType()) << std::endl;
                } else if (tmp_drawable_type == DRAWABLE_TYPE_TEXT) {
                    drawableText = static_cast<DrawableText *>(drawable);
                    buffer << drawableText->getText() << std::endl;
                    buffer << std::to_string(drawableText->getColor().r) << std::endl;
                    buffer << std::to_string(drawableText->getColor().g) << std::endl;
                    buffer << std::to_string(drawableText->getColor().b) << std::endl;
                    buffer << std::to_string(drawableText->getColor().a) << std::endl;
                    buffer << std::to_string(drawableText->getSize()) << std::endl;
                } else if (tmp_drawable_type == DRAWABLE_TYPE_PLANE) {
                    drawablePlane = static_cast<DrawablePlane *>(drawable);
                    buffer << std::to_string(drawablePlane->getSize().x) << std::endl;
                    buffer << std::to_string(drawablePlane->getSize().y) << std::endl;
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
        buffer << "--" << std::endl;
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

std::unique_ptr<IComponent> Save::saveAnimable(std::vector<std::string> lines)
{
    std::string path = lines[0];
    std::unique_ptr<IComponent> component = std::make_unique<Animable>(path, ANIMATION_TYPE::IDLE);
    return component;
}

std::unique_ptr<IComponent> Save::saveCamera(std::vector<std::string> lines)
{
    Vector3 position = {std::stof(lines[0]), std::stof(lines[1]), std::stof(lines[2])};
    Vector3 target = {std::stof(lines[3]), std::stof(lines[4]), std::stof(lines[5])};
    Vector3 up = {std::stof(lines[6]), std::stof(lines[7]), std::stof(lines[8])};
    float fov = std::stof(lines[9]);
    int projection = std::stoi(lines[10]);
    std::unique_ptr<IComponent> component = std::make_unique<CameraComponent>(position, target, up, fov, projection);
    return component;
}

std::unique_ptr<IComponent> Save::saveDrawableCube(std::vector<std::string> lines)
{
    Color color = {(unsigned char) std::stoi(lines[0]), (unsigned char) std::stoi(lines[1]), (unsigned char) std::stoi(lines[2]), (unsigned char) std::stoi(lines[3])};
    std::unique_ptr<IComponent> component = std::make_unique<DrawableCube>(color, std::stoi(lines[4]), std::stoi(lines[5]), std::stoi(lines[6]));
    return component;
}

std::unique_ptr<IComponent> Save::saveDrawableCubeTexture(std::vector<std::string> lines)
{
    Color color = {(unsigned char) std::stoi(lines[0]), (unsigned char) std::stoi(lines[1]), (unsigned char) std::stoi(lines[2]), (unsigned char) std::stoi(lines[3])};
    CubeTextureType cube_texture_type = (CubeTextureType) std::stoi(lines[4]);
    std::unique_ptr<IComponent> component;
    if (cube_texture_type == CubeTextureType::GRASS)
        component = std::make_unique<DrawableCubeTexture>(this->_grassTexture, cube_texture_type, std::stoi(lines[4]), std::stoi(lines[5]), std::stoi(lines[6]), color);
    else
        component = std::make_unique<DrawableCubeTexture>(this->_stoneTexture, cube_texture_type, std::stoi(lines[4]), std::stoi(lines[5]), std::stoi(lines[6]), color);        
    return component;
}

std::unique_ptr<IComponent> Save::saveDrawableText(std::vector<std::string> lines)
{
    Color color = {(unsigned char) std::stoi(lines[1]), (unsigned char) std::stoi(lines[2]), (unsigned char) std::stoi(lines[3]), (unsigned char) std::stoi(lines[4])};
    std::unique_ptr<IComponent> component = std::make_unique<DrawableText>(0, lines[0], color, this->_font, std::stoi(lines[5]));
    return component;
}

std::unique_ptr<IComponent> Save::saveDrawablePlane(std::vector<std::string> lines)
{
    Vector2 size = {std::stof(lines[0]), std::stof(lines[1])};
    Color color = {(unsigned char) std::stoi(lines[2]), (unsigned char) std::stoi(lines[3]), (unsigned char) std::stoi(lines[4]), (unsigned char) std::stoi(lines[5])};
    std::unique_ptr<IComponent> component = std::make_unique<DrawablePlane>(size, color);
    return component;
}

std::unique_ptr<IComponent> Save::saveDrawableModel(std::vector<std::string> lines)
{
    ModelType model_type = (ModelType) std::stoi(lines[0]);
    std::unique_ptr<IComponent> component;
    if (model_type == ModelType::MCG)
        component = std::make_unique<DrawableModel>(this->_textures_mcg, this->_mgmModel, this->_meshOrder_mcg, 0, model_type);
    else if (model_type == ModelType::SNAPE)
        component = std::make_unique<DrawableModel>(this->_textures_snape, this->_snapeModel, this->_meshOrderSnape, 0, model_type);
    else if (model_type == ModelType::SPROUT)
        component = std::make_unique<DrawableModel>(this->_textures_sprout, this->_sproutModel, this->_meshOrder_sprout, 0, model_type);
    else if (model_type == ModelType::TRELAWNEY)
        component = std::make_unique<DrawableModel>(this->_texturesTre, this->_trelawneyModel, this->_meshOrderTrelawney, 0, model_type);
    else if (model_type == ModelType::GNOME)
        component = std::make_unique<DrawableModel>(this->_texturesGnome, this->_gnomeModel, this->_texture_gnome_mesh_order, 0, model_type);
    else if (model_type == ModelType::BAG)
        component = std::make_unique<DrawableModel>(this->_texturesBag, this->_bagModel, this->_textureBagMeshOrder, 0, model_type);
    return component;
}

std::unique_ptr<IComponent> Save::saveBreakable()
{
    std::unique_ptr<IComponent> component;
    component = std::make_unique<Breakable>();
    return component;
}

//TODO PLAN

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
    DRAWABLE_TYPE drawable_type;
    std::unique_ptr<IComponent> componentToAdd;

    savefile.open(this->_fileToSaveTo);
    if (!savefile.is_open())
        throw Error_file("Could not open file to load");
    while (getline(savefile, line)) {
        entity = std::make_unique<Entity>(std::stoi(line));
        while (getline(savefile, line) && line != "--") {
            lines.clear();
            if (line == "Timable") {
                for (int i = 0; i < 1; i++) {
                    getline(savefile, line);
                    lines.push_back(line);
                }
                componentToAdd = std::move(this->saveTimable(lines));
                if (componentToAdd != nullptr)
                    entity->addComponent(std::move(componentToAdd));
            } else if (line == "Placable") {
                for (int i = 0; i < 10; i++) {
                    getline(savefile, line);
                    lines.push_back(line);
                }
                componentToAdd = std::move(this->savePlacable(lines));
                if (componentToAdd != nullptr)
                    entity->addComponent(std::move(componentToAdd));
            } else if (line == "Movable") {
                for (int i = 0; i < 2; i++) {
                    getline(savefile, line);
                    lines.push_back(line);
                }
                componentToAdd = std::move(this->saveMovable(lines));
                if (componentToAdd != nullptr)
                    entity->addComponent(std::move(componentToAdd));
            } else if (line == "Animable") {
                for (int i = 0; i < 1; i++) {
                    getline(savefile, line);
                    lines.push_back(line);
                }
                componentToAdd = std::move(this->saveAnimable(lines));
                std::cout << "Animable Path = " << static_cast<Animable *>(componentToAdd.get())->getPathToFile() << std::endl;
                if (componentToAdd != nullptr)
                    entity->addComponent(std::move(componentToAdd));
            } else if (line == "Camera") {
                for (int i = 0; i < 11; i++) {
                    getline(savefile, line);
                    lines.push_back(line);
                }
               componentToAdd = std::move(this->saveCamera(lines));
                if (componentToAdd != nullptr)
                    entity->addComponent(std::move(componentToAdd));
            } else if (line == "Breakable") {
                componentToAdd = std::move(this->saveBreakable());
                if (componentToAdd != nullptr)
                    entity->addComponent(std::move(componentToAdd));
            } else if (line == "Drawable") {
                getline(savefile, line);
                drawable_type = (DRAWABLE_TYPE) std::stoi(line);
                if (drawable_type == DRAWABLE_TYPE_CUBE) {
                    for (int i = 0; i < 7; i++) {
                        getline(savefile, line);
                        lines.push_back(line);
                    }
                    componentToAdd = std::move(this->saveDrawableCube(lines));
                    if (componentToAdd != nullptr)
                        entity->addComponent(std::move(componentToAdd));
                } else if (drawable_type == DRAWABLE_TYPE_TEXTURE_CUBE) {
                    for (int i = 0; i < 8; i++) {
                        getline(savefile, line);
                        lines.push_back(line);
                    }
                   componentToAdd = std::move(this->saveDrawableCubeTexture(lines));
                    if (componentToAdd != nullptr)
                        entity->addComponent(std::move(componentToAdd));
                } else if (drawable_type == DRAWABLE_TYPE_TEXT) {
                    for (int i = 0; i < 6; i++) {
                        getline(savefile, line);
                        lines.push_back(line);
                    }
                    componentToAdd = std::move(this->saveDrawableText(lines));
                    if (componentToAdd != nullptr)
                        entity->addComponent(std::move(componentToAdd));
                } else if (drawable_type == DRAWABLE_TYPE_PLANE) {
                    for (int i = 0; i < 6; i++) {
                        getline(savefile, line);
                        lines.push_back(line);
                    }
                    componentToAdd = std::move(this->saveDrawablePlane(lines));
                    if (componentToAdd != nullptr)
                        entity->addComponent(std::move(componentToAdd));
                } else if (drawable_type == DRAWABLE_TYPE_MODEL) {
                    for (int i = 0; i < 1; i++) {
                        getline(savefile, line);
                        lines.push_back(line);
                    }
                    componentToAdd = std::move(this->saveDrawableModel(lines));
                    if (componentToAdd != nullptr)
                        entity->addComponent(std::move(componentToAdd));
                }
            }
        }
        for (auto &component : entity->getComponents()) {
            if (component == nullptr)
                std::cout << "Component is null" << std::endl;
        }
        entities.push_back(std::move(entity));
    }
    return entities;
}
