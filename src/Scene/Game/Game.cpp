/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Game
*/

#include <iostream>
#include <fstream>
#include "raylib.hpp"
#include "Game.hpp"
#include "raymath.h"
#include "../../ecs/Components/CameraComponent/CameraComponent.hpp"
#include "../../ecs/Components/Animable/Animable.hpp"
#include "../../ecs/Systems/Animation/Animation.hpp"
#include "../../ecs/Components/Drawable/DrawableCube.hpp"
#include "../../ecs/Components/Drawable/DrawableCubeTexture.hpp"


Game::Game()
{
    Raylib::Raylib_encap Raylib_encp;
    this->_ecsManager = std::make_unique<ECSManager>();
    this->_mapEntities = std::make_unique<std::vector<Entity *>>();
    this->_gryf_infos_texture = Raylib_encp.LTexture("assets/materials/game/gryffindor.png");
    this->_rav_infos_texture = Raylib_encp.LTexture("assets/materials/game/ravenclaw.png");
    this->_slyth_infos_texture = Raylib_encp.LTexture("assets/materials/game/slytherin.png");
    this->_huff_infos_texture = Raylib_encp.LTexture("assets/materials/game/hufflepuff.png");

    // Create camera vectors
    Vector3 position = { 10.0f, 60.0f, 25.0f };
    Vector3 target = { 10.0f, -25.0f, 0.0f };
    Vector3 up = { 0.0f, 1.0f, 0.0f };

    // Createing plane vectors
    Vector2 size = { 128.0f, 128.0f };

    // Creating entities
    int camera = this->_ecsManager->createEntity();
    int text = this->_ecsManager->createEntity();
    int player = this->_ecsManager->createEntity();
    int ai = this->_ecsManager->createEntity();
    int model = this->_ecsManager->createEntity();
    int test_pot = this->_ecsManager->createEntity();
    int flitwick = this->_ecsManager->createEntity();
    int snape = this->_ecsManager->createEntity();
    int plane = this->_ecsManager->createEntity();
    int sprout = this->_ecsManager->createEntity();
    int gryf_infos = this->_ecsManager->createEntity();
    int rav_infos = this->_ecsManager->createEntity();
    int slyth_infos = this->_ecsManager->createEntity();
    int huff_infos = this->_ecsManager->createEntity();
    int music_id = this->_ecsManager->createEntity();
    // int plane = this->_ecsManager->createEntity();

    // Load Music
    Music music = Raylib_encp.LoadMStream("assets/sounds/game_bg.mp3");
    // Creating Model , vector texture and the mesh order for mcg
    Model mgmModel = Raylib_encp.LModel("assets/models/mcg/mcg.iqm");
    std::vector<Texture2D> texturesMgm = {
        Raylib_encp.LTexture("assets/models/mcg/c_McGonagall_Body_Diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/mcg/c_McGonagall_eyes_Diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/mcg/c_McGonagall_hands_Diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/mcg/c_McGonagall_Hat_Diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/mcg/c_McGonagall_Head_Diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/mcg/glass.png")
    };
    std::vector<int> meshOrderMgm = {
        1, 2, 3, 5, 0, 4
    };

    // Creating Model , vector texture and the mesh order for FLitwick
    Model flitwickModel = Raylib_encp.LModel("assets/models/flitwick/flitwick.iqm");
    std::vector<Texture2D> texturesFlit = {
        Raylib_encp.LTexture("assets/models/flitwick/HP_Flitwick_bodyB_diffuse_v4@4x.png"),
        Raylib_encp.LTexture("assets/models/flitwick/EyesBW_v169@4x.png"),
        Raylib_encp.LTexture("assets/models/flitwick/HP_Flitwick_hairB_diffuse_v4@4x.png"),
        Raylib_encp.LTexture("assets/models/flitwick/HP_Flitwick_hand_diffuse_v4@4x.png"),
        Raylib_encp.LTexture("assets/models/flitwick/Flitwick_head_diffuse_v4@4x.png")
    };
    std::vector<int> meshOrderFlitwick = {
        2, 4, 5, 1, 3
    };

    // Creating Model , vector texture and the mesh order for Snape
    Model snapeModel = Raylib_encp.LModel("assets/models/snape/snape.iqm");
    std::vector<Texture2D> texturesSnape = {
        Raylib_encp.LTexture("assets/models/snape/c_Snape_Hair_diffuse_v3@4x.png"),
        Raylib_encp.LTexture("assets/models/snape/c_Snape_Hands_diffuse_v8@4x.png"),
        Raylib_encp.LTexture("assets/models/snape/c_Snape_Head_diffuse_v3@4x.png"),
        Raylib_encp.LTexture("assets/models/snape/c_Snape_Outfit_diffuse_v3@4x.png"),
        Raylib_encp.LTexture("assets/models/snape/EyesBW_v169@4x.png")
    };
    std::vector<int> meshOrderSnape = {
       4, 3, 0, 2, 1
    };

    // Creating Model , vector texture and the mesh order for Sprout
    Model sproutModel = Raylib_encp.LModel("assets/models/sprout/sprout.iqm");
    std::vector<Texture2D> texturesSprout = {
        Raylib_encp.LTexture("assets/models/sprout/Sprout_body_diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/sprout/Sprout_cloak_diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/sprout/Sprout_eyes_diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/sprout/Sprout_face_diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/sprout/Sprout_hair_diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/sprout/Sprout_hand_diffuse_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/sprout/Sprout_hat_diffuse_v1@4x.png")

    };
    std::vector<int> meshOrderSprout = {
        1, 5, 4, 0, 6, 3, 2
    };

    // Configuring Player vector
    Vector3 position_player = { 1.0f, 0.0f, 0.0f };

    //Configure Music
    Raylib_encp.PlayMStream(music);
    this->_ecsManager->addComponent(music_id, std::make_unique<Musicable>(music));

    // Adding components
    this->_ecsManager->addComponent(camera, std::make_unique<CameraComponent>(position, target, up, 18.0f, CAMERA_PERSPECTIVE));
    this->_ecsManager->addComponent(text, std::make_unique<Placable>(1000, 150));
    this->_ecsManager->addComponent(text, std::make_unique<DrawableText>(0,"Mandraker", Color{255, 255, 255, 255}));

    // Adding HUD
    this->_ecsManager->addComponent(gryf_infos, std::make_unique<Placable>(0, 0));
    this->_ecsManager->addComponent(gryf_infos, std::make_unique<DrawableSprite>(this->_gryf_infos_texture, 1));
    this->_ecsManager->addComponent(rav_infos, std::make_unique<Placable>(1792, 0));
    this->_ecsManager->addComponent(rav_infos, std::make_unique<DrawableSprite>(this->_rav_infos_texture, 1));
    this->_ecsManager->addComponent(slyth_infos, std::make_unique<Placable>(0, 937));
    this->_ecsManager->addComponent(slyth_infos, std::make_unique<DrawableSprite>(this->_slyth_infos_texture, 1));
    this->_ecsManager->addComponent(huff_infos, std::make_unique<Placable>(1792, 937));
    this->_ecsManager->addComponent(huff_infos, std::make_unique<DrawableSprite>(this->_huff_infos_texture, 1));


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

    //Drawing the plane
    this->_ecsManager->addComponent(plane, std::make_unique<Placable>(0, -1, 0));
    this->_ecsManager->addComponent(plane, std::make_unique<DrawablePlane>(size, DARKBROWN));

    // Configuring player SPROUT
    this->_ecsManager->addComponent(sprout, std::make_unique<Placable>(1.0f, 0.0f, 11.0f, position_player, -90.0f));
    this->_ecsManager->addComponent(sprout, std::make_unique<Movable>(4.0f, MOVABLE_AI));
    this->_ecsManager->addComponent(sprout, std::make_unique<DrawableModel>(texturesSprout, sproutModel, meshOrderSprout));
    this->_ecsManager->addComponent(sprout, std::make_unique<Animable>("assets/models/sprout/sprout.iqm", ANIMATION_TYPE::IDLE));

    // Configuring ai
    // this->_ecsManager->addComponent(ai, std::make_unique<Placable>(0, 0));
    // this->_ecsManager->addComponent(ai, std::make_unique<Movable>(1, MOVABLE_AI));

    // Adding systems
    this->_ecsManager->addSystem(std::make_unique<Draw>(Draw()));
    this->_ecsManager->addSystem(std::make_unique<Music_sys>(Music_sys()));
    this->_ecsManager->addSystem(std::make_unique<Move>(Move()));
    this->_ecsManager->addSystem(std::make_unique<Animation>(Animation()));
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
    Raylib::Raylib_encap Raylib_encp;
    //load map from file
    std::ifstream myfile (map_src);
    std::string line;
    int i = 0;
    Texture2D grass_texture = Raylib_encp.LTexture("assets/materials/grass.png");
    std::vector<Texture2D> textures_pot = {
        Raylib_encp.LTexture("assets/models/bag/p_FertiliserBag_Diffuse_v1@4x.png")
    };
    std::vector<int> texture_po_mesh_order = {
        0
    };
    //Table model
    std::vector<Texture2D> textures_tables = {
        Raylib_encp.LTexture("assets/models/table/leaves2_v73@4x.png"),
        Raylib_encp.LTexture("assets/models/table/Metal_potteryHolders_v11@4x.png"),
        Raylib_encp.LTexture("assets/models/table/pottery02_v18@4x.png"),
    };
    std::vector<int> texture_table_mesh_order = {
        2, 0, 1
    };
    Model tableModel = Raylib_encp.LModel("assets/models/table/table.obj");
    Model tableModelRotate = Raylib_encp.LModel("assets/models/table/table.obj");
    tableModelRotate.transform = MatrixRotateY(1.55 );
    Model bagModel = Raylib_encp.LModel("assets/models/bag/bag.obj");
    Vector3 zeroVector3 = {0.0f, 0.0f, 0.0f};
    Vector3 bag_scale = {0.03, 0.03, 0.03};
    Vector2 size = { 1, 1 };

    if (!myfile.is_open())
        throw Error_file("Error while opening map file");
    while (std::getline(myfile, line)) {
        for (int j = 0; j < line.size(); j++) {
            Entity *entity = this->_ecsManager->getEntity(this->_ecsManager->createEntity());
            Entity *grass_block = this->_ecsManager->getEntity(this->_ecsManager->createEntity());
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
            // we have to push grass also
            grass_block->addComponent(std::make_unique<Placable>(j, -1.0f, i, zeroVector3));
            grass_block->addComponent(std::make_unique<DrawableCubeTexture>(grass_texture));
            this->_mapEntities->push_back(entity);
        }
        i++;
    }
    myfile.close();
}
