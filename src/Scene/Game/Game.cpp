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
#include "../../ecs/Components/Playable/Playable.hpp"
#include "../../ecs/Components/Timable/Timable.hpp"
#include "../../ecs/Components/Collisionable/Collisionable.hpp"
#include "../../ecs/Components/Breakable/Breakable.hpp"
#include "../../ecs/Systems/Animation/Animation.hpp"
#include "../../ecs/Systems/Player/Player.hpp"
#include "../../ecs/Systems/Timer/Timer.hpp"
#include "../../ecs/Systems/Finish/Finish.hpp"
#include "../../ecs/Systems/Save/SaveSystem.hpp"
#include "../../ecs/Components/Drawable/DrawableCube.hpp"
#include "../../ecs/Components/Drawable/DrawableCubeTexture.hpp"
#include "../../Scene/Menu/Menu.hpp"

float mapHeight = 14;
float mapWidth = 10;

Game::Game(std::vector<Model> models, std::vector<CHARACTER_CHOOSEN> *characterChoosen, std::vector<std::unique_ptr<Entity>> entities)
{
    Raylib::Raylib_encap Raylib_encp;

    // Set character chosen
    this->_characterChoosen = characterChoosen;
    this->_ecsManager = std::make_unique<ECSManager>();
    // Create vector for map
    this->_mapEntities = std::make_unique<std::vector<Entity *>>();
    // Load HUD textures
    this->_gryf_infos_texture = Raylib_encp.LTexture("assets/materials/game/gryffindor.png");
    this->_rav_infos_texture = Raylib_encp.LTexture("assets/materials/game/ravenclaw.png");
    this->_slyth_infos_texture = Raylib_encp.LTexture("assets/materials/game/slytherin.png");
    this->_huff_infos_texture = Raylib_encp.LTexture("assets/materials/game/hufflepuff.png");

    // Load Music
    this->music = Raylib_encp.LoadMStream("assets/sounds/game_bg.mp3");

    // Creating Mandrake model
    this->mandrakeModel = Raylib_encp.LModel("assets/models/mandrake/mandrake.iqm");

    // Configuring Player vector
    Vector3 position_player = { 1.0f, 0.0f, 0.0f };

    // Create camera vectors
    Vector3 position = { 7.0f, 50.0f, 25.0f };
    Vector3 target = { 7.0f, -20.0f, 0.0f };
    Vector3 up = { 0.0f, 1.0f, 0.0f };

    // Createing plane vectors
    Vector2 size = { 128.0f, 128.0f };

    // Create variables for entities
    int camera;
    int text;
    int player;
    int ai;
    int model;
    int test_pot;
    int trelawney;
    int snape;
    int plane;
    int sprout;
    int gryf_infos;
    int rav_infos;
    int slyth_infos;
    int huff_infos;
    int music_id;
    int mandrake;
    int game_clock;


    // Creating HUD entities
    gryf_infos = this->_ecsManager->createEntity();
    rav_infos = this->_ecsManager->createEntity();
    slyth_infos = this->_ecsManager->createEntity();
    huff_infos = this->_ecsManager->createEntity();

    // Adding HUD Components
    this->_ecsManager->addComponent(gryf_infos, std::make_unique<Placable>(0, 0));
    this->_ecsManager->addComponent(gryf_infos, std::make_unique<DrawableSprite>(this->_gryf_infos_texture, 1));
    this->_ecsManager->addComponent(huff_infos, std::make_unique<Placable>(1792, 0));
    this->_ecsManager->addComponent(huff_infos, std::make_unique<DrawableSprite>(this->_huff_infos_texture, 1));
    this->_ecsManager->addComponent(rav_infos, std::make_unique<Placable>(0, 937));
    this->_ecsManager->addComponent(rav_infos, std::make_unique<DrawableSprite>(this->_rav_infos_texture, 1));
    this->_ecsManager->addComponent(slyth_infos, std::make_unique<Placable>(1792, 937));
    this->_ecsManager->addComponent(slyth_infos, std::make_unique<DrawableSprite>(this->_slyth_infos_texture, 1));

    IComponent *tmp_component = nullptr;
    ModelType model_type;
    if (entities.size() != 0) {
        std::cout << "Constructing Game from saved entities" << std::endl;
        for (auto &entity : entities) {
            tmp_component = entity.get()->getComponentsByType(COMPONENT_TYPES::DRAWABLE);
            if (tmp_component != nullptr && static_cast<Drawable *>(tmp_component)->getComponentType() == DRAWABLE_TYPE::DRAWABLE_TYPE_MODEL) {
                model_type = (ModelType) static_cast<DrawableModel *> (tmp_component)->getModelType();
                if (model_type == ModelType::MCG)
                    player = entity.get()->getId();
                else if (model_type == ModelType::TRELAWNEY)
                    trelawney = entity.get()->getId();
                else if (model_type == ModelType::SNAPE)
                    snape = entity.get()->getId();
                else if (model_type == ModelType::SPROUT)
                    sprout = entity.get()->getId();
            }
            this->_ecsManager->addEntity(std::move(entity));
        }
    } else {
        // Creating entities
        camera = this->_ecsManager->createEntity();
        text = this->_ecsManager->createEntity();
        player = this->_ecsManager->createEntity();
        ai = this->_ecsManager->createEntity();
        model = this->_ecsManager->createEntity();
        test_pot = this->_ecsManager->createEntity();
        trelawney = this->_ecsManager->createEntity();
        snape = this->_ecsManager->createEntity();
        plane = this->_ecsManager->createEntity();
        sprout = this->_ecsManager->createEntity();
        music_id = this->_ecsManager->createEntity();
        mandrake = this->_ecsManager->createEntity();
        game_clock = this->_ecsManager->createEntity();

        // Creating Model , vector texture and the mesh order for mcg
        this->mgmModel = models[0];
        this->trelawneyModel = models[1];
        this->snapeModel = models[2];
        this->sproutModel = models[3];

        // Adding Camera Component
        this->_ecsManager->addComponent(camera, std::make_unique<CameraComponent>(position, target, up, 18.0f, CAMERA_PERSPECTIVE));


        // Adding Timer
        this->_font = Raylib_encp.LFontEx("assets/fonts/wizarding.ttf", 100, 0, 0);
        this->_ecsManager->addComponent(game_clock, std::make_unique<Placable>(1792/2 - 3, 20));
        this->_ecsManager->addComponent(game_clock, std::make_unique<DrawableText>(1, "", Color{255, 255, 255, 255}, this->_font, 80));
        this->_ecsManager->addComponent(game_clock, std::make_unique<Timable>(120, GAME_CLOCK, game_clock));

        // Configuring player MCG
        this->_ecsManager->addComponent(player, std::make_unique<Placable>(1.0f, 0.0f, 1.0f, position_player, -90.0f));
        int done = 0;
        for (int i = 0; i != (*characterChoosen).size(); i++) {
            if ((*characterChoosen)[i] == CHARACTER_CHOOSEN::MCG && i == 0) {
                done = 1;
                this->_ecsManager->addComponent(player, std::make_unique<Movable>(4.0f, MOVABLE_PLAYER));
            }
            else if ((*characterChoosen)[i] == CHARACTER_CHOOSEN::MCG && i == 1) {
                done = 1;
                this->_ecsManager->addComponent(player, std::make_unique<Movable>(4.0f, MOVABLE_PLAYER_2));
            }
        }
        if (done != 1)
            this->_ecsManager->addComponent(player, std::make_unique<Movable>(4.0f, MOVABLE_AI));
        this->_ecsManager->addComponent(player, std::make_unique<Playable>(1));
        this->_ecsManager->addComponent(player, std::make_unique<DrawableModel>(texturesMgm, mgmModel, meshOrderMgm, 0, ModelType::MCG));
        this->_ecsManager->addComponent(player, std::make_unique<Animable>("assets/models/mcg/mcg.iqm", ANIMATION_TYPE::IDLE));
        this->_ecsManager->addComponent(player, std::make_unique<Breakable>());


        // Configuring player TRELAWNEY
        this->_ecsManager->addComponent(trelawney, std::make_unique<Placable>(1.0f, 0.0f, 11.0f, position_player, -90.0f));
        done = 0;
        for (int i = 0; i != (*characterChoosen).size(); i++) {
            if ((*characterChoosen)[i] == CHARACTER_CHOOSEN::TRELAWNEY && i == 0) {
                done = 1;
                this->_ecsManager->addComponent(trelawney, std::make_unique<Movable>(4.0f, MOVABLE_PLAYER));
            }
            else if ((*characterChoosen)[i] == CHARACTER_CHOOSEN::TRELAWNEY && i == 1) {
                done = 1;
                this->_ecsManager->addComponent(trelawney, std::make_unique<Movable>(4.0f, MOVABLE_PLAYER_2));
            }
        }
        if (done != 1)
            this->_ecsManager->addComponent(trelawney, std::make_unique<Movable>(4.0f, MOVABLE_AI));
        this->_ecsManager->addComponent(trelawney, std::make_unique<Playable>(1));
        this->_ecsManager->addComponent(trelawney, std::make_unique<DrawableModel>(texturesTre, trelawneyModel, meshOrderTrelawney, 0, ModelType::TRELAWNEY));
        this->_ecsManager->addComponent(trelawney, std::make_unique<Animable>("assets/models/trelawney/trelawney.iqm", ANIMATION_TYPE::IDLE));
        this->_ecsManager->addComponent(trelawney, std::make_unique<Breakable>());

        // Configuring player SNAPE
        this->_ecsManager->addComponent(snape, std::make_unique<Placable>(13.0f, 0.0f, 11.0f, position_player, -90.0f));
        done = 0;
        for (int i = 0; i != (*characterChoosen).size(); i++) {
            if ((*characterChoosen)[i] == CHARACTER_CHOOSEN::SNAPE && i == 0) {
                done = 1;
                this->_ecsManager->addComponent(snape, std::make_unique<Movable>(4.0f, MOVABLE_PLAYER));
            }
            else if ((*characterChoosen)[i] == CHARACTER_CHOOSEN::SNAPE && i == 1) {
                done = 1;
                this->_ecsManager->addComponent(snape, std::make_unique<Movable>(4.0f, MOVABLE_PLAYER_2));
            }
        }
        if (done != 1)
            this->_ecsManager->addComponent(snape, std::make_unique<Movable>(4.0f, MOVABLE_AI));

        this->_ecsManager->addComponent(snape, std::make_unique<Playable>(1));
        this->_ecsManager->addComponent(snape, std::make_unique<DrawableModel>(texturesSnape, snapeModel, meshOrderSnape, 0, ModelType::SNAPE));
        this->_ecsManager->addComponent(snape, std::make_unique<Animable>("assets/models/snape/snape.iqm", ANIMATION_TYPE::IDLE));
        this->_ecsManager->addComponent(snape, std::make_unique<Breakable>());

        // Configuring player SPROUT
        this->_ecsManager->addComponent(sprout, std::make_unique<Placable>(13.0f, 0.0f, 1.0f, position_player, -90.0f));
        done = 0;
        for (int i = 0; i != (*characterChoosen).size(); i++) {
            if ((*characterChoosen)[i] == CHARACTER_CHOOSEN::SPROUT && i == 0) {
                done = 1;
                this->_ecsManager->addComponent(sprout, std::make_unique<Movable>(4.0f, MOVABLE_PLAYER));
            }
            else if ((*characterChoosen)[i] == CHARACTER_CHOOSEN::SPROUT && i == 1) {
                done = 1;
                this->_ecsManager->addComponent(sprout, std::make_unique<Movable>(4.0f, MOVABLE_PLAYER_2));
            }
        }
        if (done != 1)
            this->_ecsManager->addComponent(sprout, std::make_unique<Movable>(4.0f, MOVABLE_AI));

        this->_ecsManager->addComponent(sprout, std::make_unique<Playable>(1));
        this->_ecsManager->addComponent(sprout, std::make_unique<DrawableModel>(texturesSprout, sproutModel, meshOrderSprout, 0, ModelType::SPROUT));
        this->_ecsManager->addComponent(sprout, std::make_unique<Animable>("assets/models/sprout/sprout.iqm", ANIMATION_TYPE::IDLE));
        this->_ecsManager->addComponent(sprout, std::make_unique<Breakable>());

        // Loading the map
        this->loadMap("assets/map/map.txt");

        // Collision configuration
        this->_ecsManager->addComponent(player, std::make_unique<Collisionable>(this->_mapEntities.get()));
        this->_ecsManager->addComponent(sprout, std::make_unique<Collisionable>(this->_mapEntities.get()));
        this->_ecsManager->addComponent(trelawney, std::make_unique<Collisionable>(this->_mapEntities.get()));
        this->_ecsManager->addComponent(snape, std::make_unique<Collisionable>(this->_mapEntities.get()));
    }

    //Configure Music
    Raylib_encp.PlayMStream(music);
    this->_ecsManager->addComponent(music_id, std::make_unique<Musicable>(music));

    // make the player vector
    this->_playerEntities.push_back(this->_ecsManager->getEntity(player));
    this->_playerEntities.push_back(this->_ecsManager->getEntity(trelawney));
    this->_playerEntities.push_back(this->_ecsManager->getEntity(snape));
    this->_playerEntities.push_back(this->_ecsManager->getEntity(sprout));
    // this->_playerEntities->push_back(this->_ecsManager->getEntity(trelawney));
    // this->_playerEntities->push_back(this->_ecsManager->getEntity(snape));
    // this->_playerEntities->push_back(this->_ecsManager->getEntity(sprout));

    // Adding systems
    this->_ecsManager->addSystem(std::make_unique<Draw>(Draw()));
    this->_ecsManager->addSystem(std::make_unique<Music_sys>(Music_sys()));
    this->_ecsManager->addSystem(std::make_unique<Move>(Move()));
    this->_ecsManager->addSystem(std::make_unique<Animation>(Animation()));
    this->_ecsManager->addSystem(std::make_unique<Player>(this->_ecsManager.get(), this->_mapEntities.get()));
    this->_ecsManager->addSystem(std::make_unique<SaveSystem>(this->_ecsManager->getEntities()));
    this->_ecsManager->addSystem(std::make_unique<Timer>(this->_ecsManager.get(), this->_mapEntities.get(), &this->_playerEntities));
    this->_ecsManager->addSystem(std::make_unique<Finish>(&this->_playerEntities));

    //Drawing the plane
    this->_ecsManager->addComponent(plane, std::make_unique<Placable>(0, -1, 0));
    this->_ecsManager->addComponent(plane, std::make_unique<DrawablePlane>(size, DARKBROWN));

    // this->_ecsManager->addSystem(std::make_unique<Move>());
    std::cout << "Game created" << std::endl;
}

Game::~Game()
{
}

void Game::loadMap(std::string map_src)
{
    Raylib::Raylib_encap Raylib_encp;
    std::ifstream myfile (map_src);
    std::string line;
    int i = 0;

    // Gass
    this->grass_texture = Raylib_encp.LTexture("assets/materials/grass.png");
    // Stone
    this->stone_texture = Raylib_encp.LTexture("assets/materials/game/stone.png");
    this->textures_bag = {
        Raylib_encp.LTexture("assets/models/bag/p_FertiliserBag_Diffuse_v1@4x.png")
    };

    //bag
    std::vector<int> texture_po_mesh_order = {
        0
    };
    this->bagModel = Raylib_encp.LModel("assets/models/bag/bag.obj");

    //Table
    this->textures_tables = {
        Raylib_encp.LTexture("assets/models/table/leaves2_v73@4x.png"),
        Raylib_encp.LTexture("assets/models/table/Metal_potteryHolders_v11@4x.png"),
        Raylib_encp.LTexture("assets/models/table/pottery02_v18@4x.png"),
    };
    std::vector<int> texture_table_mesh_order = {
        2, 0, 1
    };
    this->tableModel = Raylib_encp.LModel("assets/models/table/table.obj");

    // Gnome
    this->gnome = Raylib_encp.LModel("assets/models/gnome/gnome.iqm");
    gnome.transform = MatrixRotateX(1.55);
    this->textures_gnome = {
        Raylib_encp.LTexture("assets/models/gnome/gnome_DIF_v1@4x.png"),
        Raylib_encp.LTexture("assets/models/gnome/GnomeHoles_DIF_v1@4x.png")
    };
    std::vector<int> texture_gnome_mesh_order = {
        0, 2
    };
    Vector3 gnome_scale = {0.01, 0.01, 0.01};
    // 
    Vector3 zeroVector3 = {0.0f, 0.0f, 0.0f};
    Vector3 rotation_gnome = {0.0f, 90.0f, 0.0f};
    Vector3 bag_scale = {0.03, 0.03, 0.03};
    Vector2 size = { 1, 1 };
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    if (!myfile.is_open())
        throw Error_file("Error while opening map file");
    while (std::getline(myfile, line)) {
        for (int j = 0; j < line.size(); j++) {
            Entity *entity = nullptr;
            Entity *grass_block = this->_ecsManager->getEntity(this->_ecsManager->createEntity());
            if (line[j] == 'r') {
                entity = this->_ecsManager->getEntity(this->_ecsManager->createEntity());
                entity->addComponent(std::make_unique<Placable>(round(j), 0, round(i), zeroVector3 , -45, bag_scale));
                entity->addComponent(std::make_unique<DrawableModel>(textures_bag, bagModel, texture_po_mesh_order, 0, ModelType::BAG));
                // we have to put grass also
                grass_block->addComponent(std::make_unique<Placable>(round(j), -1.0f, round(i), zeroVector3));
                grass_block->addComponent(std::make_unique<DrawableCubeTexture>(grass_texture, CubeTextureType::GRASS));
            } else if (line[j] == 'B') {
                entity = this->_ecsManager->getEntity(this->_ecsManager->createEntity());
                entity->addComponent(std::make_unique<Placable>(round(j), -1.0f, round(i), zeroVector3));
                entity->addComponent(std::make_unique<DrawableModel>(textures_tables, tableModel, texture_table_mesh_order, 0, ModelType::BAG));
                // we have to put grass also
                grass_block->addComponent(std::make_unique<Placable>(round(j), -1.0f, round(i), zeroVector3));
                grass_block->addComponent(std::make_unique<DrawableCubeTexture>(grass_texture, CubeTextureType::GRASS));
            } else if (line[j] == '*') {
                grass_block->addComponent(std::make_unique<Placable>(round(j), -1.0f, round(i), zeroVector3));
                grass_block->addComponent(std::make_unique<DrawableCubeTexture>(stone_texture, CubeTextureType::STONE));
            } else {
                if (std::rand() % 2 == 1) { // 50% chance to spawn a gnome
                    entity = this->_ecsManager->getEntity(this->_ecsManager->createEntity());
                    entity->addComponent(std::make_unique<Placable>(round(j), 0, round(i), zeroVector3, 0, gnome_scale));
                    entity->addComponent(std::make_unique<DrawableModel>(textures_gnome, gnome, texture_gnome_mesh_order, 0, ModelType::BAG));
                    entity->addComponent(std::make_unique<Breakable>());
                }
                // we have to put grass also
                grass_block->addComponent(std::make_unique<Placable>(round(j), -1.0f, round(i), zeroVector3));
                grass_block->addComponent(std::make_unique<DrawableCubeTexture>(grass_texture, CubeTextureType::GRASS));
            }
            if (entity != nullptr)
                this->_mapEntities->push_back(entity);
        }
        i++;
    }
    myfile.close();
}


void Game::Unload()
{
    std::cout << "Game destructor" << std::endl;
    Raylib::Raylib_encap RaylibEncap;
    RaylibEncap.UnlTexture(this->_gryf_infos_texture);
    RaylibEncap.UnlTexture(this->_rav_infos_texture);
    RaylibEncap.UnlTexture(this->_slyth_infos_texture);
    RaylibEncap.UnlTexture(this->_huff_infos_texture);
    RaylibEncap.UnloadMStream(this->music);
    RaylibEncap.UnloadMdl(mgmModel);
    RaylibEncap.UnloadMdl(trelawneyModel);
    RaylibEncap.UnloadMdl(snapeModel);
    RaylibEncap.UnloadMdl(sproutModel);
    for (auto &i : texturesMgm)
        RaylibEncap.UnlTexture(i);
    for (auto &i : texturesTre)
        RaylibEncap.UnlTexture(i);
    for (auto &i : texturesSnape)
        RaylibEncap.UnlTexture(i);
    for (auto &i : texturesSprout)
        RaylibEncap.UnlTexture(i);
    RaylibEncap.UnlTexture(grass_texture);
    RaylibEncap.UnlTexture(stone_texture);
    for (auto &i : textures_bag)
        RaylibEncap.UnlTexture(i);
    for (auto &i : textures_tables)
        RaylibEncap.UnlTexture(i);
    for (auto &i : textures_gnome)
        RaylibEncap.UnlTexture(i);
    RaylibEncap.UnloadMdl(bagModel);
    RaylibEncap.UnloadMdl(tableModel);
    RaylibEncap.UnloadMdl(tableModelRotate);
    RaylibEncap.UnloadMdl(gnome);
    RaylibEncap.UnlFont(this->_font);
}