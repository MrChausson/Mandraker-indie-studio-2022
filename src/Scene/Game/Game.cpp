/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Game
*/

#include <iostream>
#include <fstream>
#include "Game.hpp"
#include "../../ecs/Components/CameraComponent/CameraComponent.hpp"
#include "../../ecs/Components/Animable/Animable.hpp"
#include "../../ecs/Systems/Animation/Animation.hpp"
#include "../../ecs/Components/Drawable/DrawableCube.hpp"
#include "../../ecs/Components/Drawable/DrawableCubeTexture.hpp"


Game::Game()
{
    this->_ecsManager = std::make_unique<ECSManager>();
    this->_mapEntities = std::make_unique<std::vector<Entity *>>();
    this->_gryf_infos_texture = LoadTexture("assets/materials/game/gryffindor.png");

    // Create camera vectors
    Vector3 position = { 10.0f, 60.0f, 25.0f };
    Vector3 target = { 10.0f, -25.0f, 0.0f };
    Vector3 up = { 0.0f, 1.0f, 0.0f };

    // Createing plane vectors
    Vector2 size = { 12.0f, 8.0f };

    // Creating entities
    int camera = this->_ecsManager->createEntity();
    int text = this->_ecsManager->createEntity();
    int player = this->_ecsManager->createEntity();
    int ai = this->_ecsManager->createEntity();
    int model = this->_ecsManager->createEntity();
    int test_pot = this->_ecsManager->createEntity();
    int flitwick = this->_ecsManager->createEntity();
    int snape = this->_ecsManager->createEntity();
    int sprout = this->_ecsManager->createEntity();
    int gryf_infos = this->_ecsManager->createEntity();
    // int plane = this->_ecsManager->createEntity();

    // Creating Model , vector texture and the mesh order for mcg 
    Model mgmModel = LoadModel("assets/models/mcg/mcg.iqm");
    std::vector<Texture2D> texturesMgm = {
        LoadTexture("assets/models/mcg/c_McGonagall_Body_Diffuse_v1@4x.png"),
        LoadTexture("assets/models/mcg/c_McGonagall_eyes_Diffuse_v1@4x.png"),
        LoadTexture("assets/models/mcg/c_McGonagall_hands_Diffuse_v1@4x.png"),
        LoadTexture("assets/models/mcg/c_McGonagall_Hat_Diffuse_v1@4x.png"),
        LoadTexture("assets/models/mcg/c_McGonagall_Head_Diffuse_v1@4x.png"),
        LoadTexture("assets/models/mcg/glass.png")
    };
    std::vector<int> meshOrderMgm = {
        1, 2, 3, 5, 0, 4
    };


    // Creating Model , vector texture and the mesh order for FLitwick
    Model flitwickModel = LoadModel("assets/models/flitwick/flitwick.iqm");
    std::vector<Texture2D> texturesFlit = {
        LoadTexture("assets/models/flitwick/HP_Flitwick_bodyB_diffuse_v4@4x.png"),
        LoadTexture("assets/models/flitwick/EyesBW_v169@4x.png"),
        LoadTexture("assets/models/flitwick/HP_Flitwick_hairB_diffuse_v4@4x.png"),
        LoadTexture("assets/models/flitwick/HP_Flitwick_hand_diffuse_v4@4x.png"),
        LoadTexture("assets/models/flitwick/Flitwick_head_diffuse_v4@4x.png")
    };
    std::vector<int> meshOrderFlitwick = {
        2, 4, 5, 1, 3
    };

    // Creating Model , vector texture and the mesh order for Snape
    Model snapeModel = LoadModel("assets/models/snape/snape.iqm");
    std::vector<Texture2D> texturesSnape = {
        LoadTexture("assets/models/snape/c_Snape_Hair_diffuse_v3@4x.png"),
        LoadTexture("assets/models/snape/c_Snape_Hands_diffuse_v8@4x.png"),
        LoadTexture("assets/models/snape/c_Snape_Head_diffuse_v3@4x.png"),
        LoadTexture("assets/models/snape/c_Snape_Outfit_diffuse_v3@4x.png"),
        LoadTexture("assets/models/snape/EyesBW_v169@4x.png")
    };
    std::vector<int> meshOrderSnape = {
       4, 3, 0, 2, 1
    };


    // Creating Model , vector texture and the mesh order for Sprout
    Model sproutModel = LoadModel("assets/models/sprout/sprout.iqm");
    std::vector<Texture2D> texturesSprout = {
        LoadTexture("assets/models/sprout/Sprout_body_diffuse_v1@4x.png"),
        LoadTexture("assets/models/sprout/Sprout_cloak_diffuse_v1@4x.png"),
        LoadTexture("assets/models/sprout/Sprout_eyes_diffuse_v1@4x.png"),
        LoadTexture("assets/models/sprout/Sprout_face_diffuse_v1@4x.png"),
        LoadTexture("assets/models/sprout/Sprout_hair_diffuse_v1@4x.png"),
        LoadTexture("assets/models/sprout/Sprout_hand_diffuse_v1@4x.png"),
        LoadTexture("assets/models/sprout/Sprout_hat_diffuse_v1@4x.png")

    };
    std::vector<int> meshOrderSprout = {
        1, 5, 4, 0, 6, 3, 2
    };

    // Configuring Player vector
    Vector3 position_player = { 1.0f, 0.0f, 0.0f };

    // Adding components
    this->_ecsManager->addComponent(camera, std::make_unique<CameraComponent>(position, target, up, 18.0f, CAMERA_PERSPECTIVE));
    this->_ecsManager->addComponent(gryf_infos, std::make_unique<Placable>(0, 100));
    this->_ecsManager->addComponent(gryf_infos, std::make_unique<DrawableSprite>(this->_gryf_infos_texture, 1));
    this->_ecsManager->addComponent(text, std::make_unique<Placable>(1000, 150));
    this->_ecsManager->addComponent(text, std::make_unique<DrawableText>(0,"Mandraker", Color{255, 255, 255, 255}));
    
    // Configuring player MCG
    this->_ecsManager->addComponent(player, std::make_unique<Placable>(1.0f, 0.0f, 1.0f, position_player, -90.0f));
    this->_ecsManager->addComponent(player, std::make_unique<Movable>(4.0f, MOVABLE_PLAYER));
    this->_ecsManager->addComponent(player, std::make_unique<DrawableModel>(texturesMgm, mgmModel, meshOrderMgm));
    this->_ecsManager->addComponent(player, std::make_unique<Animable>("assets/models/mcg/mcg.iqm", ANIMATION_TYPE::IDLE));


    // Configuring player FLITWICK
    this->_ecsManager->addComponent(flitwick, std::make_unique<Placable>(13.0f, 0.0f, 1.0f, position_player, -90.0f));
    this->_ecsManager->addComponent(flitwick, std::make_unique<Movable>(4.0f, MOVABLE_AI));
    this->_ecsManager->addComponent(flitwick, std::make_unique<DrawableModel>(texturesFlit, flitwickModel, meshOrderFlitwick));
    this->_ecsManager->addComponent(flitwick, std::make_unique<Animable>("assets/models/flitwick/flitwick.iqm", ANIMATION_TYPE::IDLE));

    // Configuring player SNAPE
    this->_ecsManager->addComponent(snape, std::make_unique<Placable>(13.0f, 0.0f, 11.0f, position_player, -90.0f));
    this->_ecsManager->addComponent(snape, std::make_unique<Movable>(4.0f, MOVABLE_AI));
    this->_ecsManager->addComponent(snape, std::make_unique<DrawableModel>(texturesSnape, snapeModel, meshOrderSnape));
    this->_ecsManager->addComponent(snape, std::make_unique<Animable>("assets/models/snape/snape.iqm", ANIMATION_TYPE::IDLE));

    // Configuring player SPROUT
    this->_ecsManager->addComponent(sprout, std::make_unique<Placable>(1.0f, 0.0f, 11.0f, position_player, -90.0f));
    this->_ecsManager->addComponent(sprout, std::make_unique<Movable>(4.0f, MOVABLE_AI));
    this->_ecsManager->addComponent(sprout, std::make_unique<DrawableModel>(texturesSprout, sproutModel, meshOrderSprout));
    this->_ecsManager->addComponent(sprout, std::make_unique<Animable>("assets/models/sprout/sprout.iqm", ANIMATION_TYPE::IDLE));




    // // Configuring ai
    // this->_ecsManager->addComponent(ai, std::make_unique<Placable>(0, 0));
    // this->_ecsManager->addComponent(ai, std::make_unique<Movable>(1, MOVABLE_AI));

    // Adding systems
    this->_ecsManager->addSystem(std::make_unique<Draw>());
    this->_ecsManager->addSystem(std::make_unique<Move>());
    this->_ecsManager->addSystem(std::make_unique<Animation>());
    this->loadMap("assets/map/map.txt");
    // this->_ecsManager->addSystem(std::make_unique<Move>());
    std::cout << "Game created" << std::endl;
}

Game::~Game()
{
    std::cout << "Game destructor" << std::endl;
}

void Game::loadMap(std::string map_src)
{
    //load map from file
    std::ifstream myfile (map_src);
    std::string line;
    int i = 0;
    std::vector<Texture2D> textures_pot = {
        LoadTexture("assets/models/bag/p_FertiliserBag_Diffuse_v1@4x.png")
    };
    std::vector<int> texture_po_mesh_order = {
        0
    };
    //Table model
    std::vector<Texture2D> textures_tables = {
        LoadTexture("assets/models/table/leaves2_v73@4x.png"),
        LoadTexture("assets/models/table/Metal_potteryHolders_v11@4x.png"),
        LoadTexture("assets/models/table/pottery02_v18@4x.png"),
    };
    std::vector<int> texture_table_mesh_order = {
        2, 0, 1
    };
    Model tableModel = LoadModel("assets/models/table/table.obj");
    Model bagModel = LoadModel("assets/models/bag/bag.obj");
    Vector3 zeroVector3 = {0.0f, 0.0f, 0.0f};
    Vector3 bag_scale = {0.03, 0.03, 0.03};
    Vector2 size = { 1, 1 };

    if (!myfile.is_open())
        throw Error_file("Error while opening map file");
    while (std::getline(myfile, line)) {
        for (int j = 0; j < line.size(); j++) {
            Entity *entity = this->_ecsManager->getEntity(this->_ecsManager->createEntity());
            if (line[j] == 'r') {
                entity->addComponent(std::make_unique<Placable>(j, 0.0f, i, zeroVector3 , -45, bag_scale));
                entity->addComponent(std::make_unique<DrawableModel>(textures_pot, bagModel, texture_po_mesh_order));
            } else if (line[j] == 'B') {
                entity->addComponent(std::make_unique<Placable>(j, 0.5f, i, zeroVector3));
                entity->addComponent(std::make_unique<DrawableModel>(textures_tables, tableModel, texture_table_mesh_order));
            } else if (line[j] == '*') {
                entity->addComponent(std::make_unique<Placable>(j, 0.0f, i, zeroVector3));
                entity->addComponent(std::make_unique<DrawablePlane>(size));
            }
            this->_mapEntities->push_back(entity);
        }
        i++;
    }
    myfile.close();
}
