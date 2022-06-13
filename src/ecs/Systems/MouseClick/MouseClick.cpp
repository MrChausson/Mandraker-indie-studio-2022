/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** MouseClick
*/

#include <iostream>
#include "raylib.hpp"
#include "MouseClick.hpp"
#include "../../Components/Clickable/Clickable.hpp"
#include "../../../Engine/Engine.hpp"
#include "../../../Scene/Game/Game.hpp"
#include "../../../Scene/Menu/Menu.hpp"
#include "../../../Scene/Settings/Settings.hpp"
#include "../../../Scene/GameSettings/GameSettings.hpp"
#include "../../../Scene/CharacterSelector/CharacterSelector.hpp"
#include "../../../Engine/Save/Save.hpp"

MouseClick::MouseClick()
{
}

MouseClick::~MouseClick()
{
}


SYSTEM_TYPES MouseClick::getType()
{
    return (MOUSE_CLICK);
}

void MouseClick::clickAction(ClickableActionType actionType, IComponent *component, IComponent *component2)
{
    Clickable *click = static_cast<Clickable *>(component);
    DrawableSprite *sprite = static_cast<DrawableSprite *>(component2);
    ECSManager *ecs = click->getEcsToChangeTo();
    Scene *scene = click->getScene();
    CharacterSelector *characterSelector;
    Settings *settings;
    std::vector<Entity *> entities;
    Menu *menu;
    Save *save;
    
    Raylib::Raylib_encap r;

    switch (actionType)
    {
    case CLICKABLE_ACTION_CHANGE_ECS:
        if (click->_tmpEcs == SCENE_GAME && this->_characterChoosen != NO_CHARACTER) {
            if (scene == nullptr)
                throw std::runtime_error("Scene is null");
            std::cout << "Change scene" << std::endl;
            characterSelector = static_cast<CharacterSelector *>(scene);
            Game *game = new Game(characterSelector->getModels(), this->_characterChoosen);
            click->setEcs(game->getECS());
            std::cout << "Change scene" << std::endl;
        } else if (click->_tmpEcs == SCENE_MENU) {
            Menu *menu = new Menu();
            click->setEcs(menu->getECS());
            if (scene != nullptr)
                delete (static_cast<Settings *>(scene));
        } else if (click->_tmpEcs == SCENE_SETTINGS) {
            menu = static_cast<Menu *>(scene);
            int dur = menu->getMusicTimePlayed();
            Settings *settings = new Settings();
            settings->SetMusicTimePlayed(dur);
            click->setEcs(settings->getECS());
            if (scene != nullptr)
                scene->Unload();
        }
        else if (click->_tmpEcs == SCENE_CHARACTER_SELECTOR) {
            CharacterSelector *characterSelector = new CharacterSelector();
            click->setEcs(characterSelector->getECS());
            if (scene != nullptr)
                scene->Unload();
        }
    break;
    case CLICKABLE_ACTION_QUIT_GAME:
        std::cout << "Goodbye!" << std::endl;
        loop_status = false;
        if (scene != nullptr)
            scene->Unload();
    break;
    case CLICKABLE_ACTION_CHOOSE_SPANE:
        if (click->_sound != nullptr && !sprite->isSelected())
            r.PlayS(*click->_sound);
        this->_characterChoosen = SNAPE;
        characterSelector = static_cast<CharacterSelector *>(scene);
        if (!sprite->isSelected())
            characterSelector->resetBoxClicked();
        sprite->setSelected(!sprite->isSelected());
    break;
    case CLICKABLE_ACTION_CHOOSE_MCG:
        if (click->_sound != nullptr && !sprite->isSelected())
            r.PlayS(*click->_sound);
        this->_characterChoosen = MCG;
        characterSelector = static_cast<CharacterSelector *>(scene);
        if (!sprite->isSelected())
            characterSelector->resetBoxClicked();
        sprite->setSelected(!sprite->isSelected());
    break;
    case CLICKABLE_ACTION_CHOOSE_SPROUT:
        if (click->_sound != nullptr && !sprite->isSelected())
            r.PlayS(*click->_sound);
        this->_characterChoosen = SPROUT;
        characterSelector = static_cast<CharacterSelector *>(scene);
        if (!sprite->isSelected())
            characterSelector->resetBoxClicked();
        sprite->setSelected(!sprite->isSelected());
    break;
    case CLICKABLE_ACTION_CHOOSE_TRELAWNEY:
        if (click->_sound != nullptr)
            r.PlayS(*click->_sound);
        this->_characterChoosen = TRELAWNEY;
        characterSelector = static_cast<CharacterSelector *>(scene);
        if (!sprite->isSelected())
            characterSelector->resetBoxClicked();
        sprite->setSelected(!sprite->isSelected());
    break;
    case CLICKABLE_ACTION_MINUS_MUSIC:
        if (click->_sound != nullptr && musicVolume > 0) {
            int mvolume = 0;
            Settings *settings = static_cast<Settings *>(scene);
            Entity *entity = settings->getECS()->getEntity(7);
            DrawableText * text = static_cast<DrawableText *>(entity->getComponentsByType(DRAWABLE));
            r.PlayS(*click->_sound);
            musicVolume -= 0.1;
            mvolume = round(musicVolume * 100);
            text->setText(std::to_string(mvolume));
        }
    break;
    case CLICKABLE_ACTION_PLUS_MUSIC:
        if (click->_sound != nullptr && musicVolume < 1) {
            int mvolume = 0;
            Settings *settings = static_cast<Settings *>(scene);
            Entity *entity = settings->getECS()->getEntity(7);
            DrawableText * text = static_cast<DrawableText *>(entity->getComponentsByType(DRAWABLE));
            r.PlayS(*click->_sound);
            musicVolume += 0.1;
            mvolume = round(musicVolume * 100);
            text->setText(std::to_string(mvolume));
        }
    break;
    case CLICKABLE_ACTION_MINUS_SOUND:
    if (click->_sound != nullptr && soundVolume > 0) {
            int svolume = 0;
            Settings *settings = static_cast<Settings *>(scene);
            Entity *entity = settings->getECS()->getEntity(11);
            DrawableText * text = static_cast<DrawableText *>(entity->getComponentsByType(DRAWABLE));
            r.PlayS(*click->_sound);
            soundVolume -= 0.1;
            svolume = round(soundVolume * 100);
            text->setText(std::to_string(svolume));
        } 
    break;
    case CLICKABLE_ACTION_PLUS_SOUND:
        if (click->_sound != nullptr && soundVolume < 1) {
            int svolume = 0;
            Settings *settings = static_cast<Settings *>(scene);
            Entity *entity = settings->getECS()->getEntity(11);
            DrawableText * text = static_cast<DrawableText *>(entity->getComponentsByType(DRAWABLE));
            r.PlayS(*click->_sound);
            soundVolume += 0.1;
            svolume = round(soundVolume * 100);
            text->setText(std::to_string(svolume));
        }
    break;
    case CLICKABLE_ACTION_MINUS_FPS:
        if (click->_sound != nullptr && max_fps > 30) {
            Settings *settings = static_cast<Settings *>(scene);
            Entity *entity = settings->getECS()->getEntity(15);
            DrawableText * text = static_cast<DrawableText *>(entity->getComponentsByType(DRAWABLE));
            r.PlayS(*click->_sound);
            max_fps -= 30;
            r.SetTargFPS(max_fps);
            text->setText(std::to_string(max_fps));
        }
    break;
    case CLICKABLE_ACTION_PLUS_FPS:
        if (click->_sound != nullptr && max_fps < 210) {
            Settings *settings = static_cast<Settings *>(scene);
            Entity *entity = settings->getECS()->getEntity(15);
            DrawableText * text = static_cast<DrawableText *>(entity->getComponentsByType(DRAWABLE));
            r.PlayS(*click->_sound);
            max_fps += 30;
            r.SetTargFPS(max_fps);
            text->setText(std::to_string(max_fps));
        }
    break;
    case CLICKABLE_ACTION_SAVE_AND_QUIT:
        std::cout << "Goodbye!" << std::endl;
        loop_status = false;
        for (auto &entity : *scene->getECS()->getEntities())
            entities.push_back(entity.get());
        save = new Save("game.save");
        save->save(entities);
        delete(save);
        if (scene != nullptr)
            scene->Unload();

    break;
    case CLICKABLE_ACTION_SAVE_AND_MENU:
        menu = new Menu();
        for (auto &entity : *scene->getECS()->getEntities())
            entities.push_back(entity.get());
        save = new Save("game.save");
        save->save(entities);
        delete(save);
        click->setEcs(menu->getECS());
        if (scene != nullptr)
            delete (static_cast<Settings *>(scene));
    break;
    case CLICKABLE_ACTION_RETURN_GAME:
        if (scene == nullptr)
           throw std::runtime_error("Scene is null");
        std::cout << "Change scene" << std::endl;
        GameSettings *gameSet = static_cast<GameSettings *>(scene);
        click->setEcs(gameSet->_previousEcs);
        std::cout << "Change scene to game" << std::endl;
        if (scene != nullptr)
            scene->Unload();
    break;
    }
}

void MouseClick::apply(std::vector<IComponent *> component)
{
    // component : [0] = DrawableSprite, [1] = Clickable 
    Raylib::Raylib_encap Raylib_encp;
    Clickable *click = static_cast<Clickable *>(component[1]);
    Vector2 mouse = Raylib_encp.GetMousePos();
    bool pressed = Raylib_encp.IsMouseBDown(MOUSE_LEFT_BUTTON);
    bool released = Raylib_encp.IsMouseBReleased(MOUSE_LEFT_BUTTON);

    //Drawable first, clickable second
    if (click->changedState(mouse, pressed))
        if (pressed) {
            DrawableSprite *draw = static_cast<DrawableSprite *>(component[0]);
            click->_textureSaved = draw->getTexture();
            draw->setTexture(click->getTexture());
        } else if (released && click->getActionType() != CLICKABLE_ACTION_NONE) {
            this->clickAction(click->getActionType(), component[1], component[0]);
        } else {
            DrawableSprite *draw = static_cast<DrawableSprite *>(component[0]);
            draw->setTexture(click->_textureSaved);
        }
}