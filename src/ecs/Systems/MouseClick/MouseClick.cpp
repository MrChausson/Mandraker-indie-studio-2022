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
#include "../../../Scene/CharacterSelector/CharacterSelector.hpp"

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
    ECSManager *ecs = click->getEcs();
    Scene *scene = click->getScene();
    CharacterSelector *characterSelector;
    CharacterSelector *charScene;
    Raylib::Raylib_encap r;

    switch (actionType)
    {
    case CLICKABLE_ACTION_CHANGE_ECS:
        if (click->_tmpEcs == SCENE_GAME && this->_characterChoosen != NO_CHARACTER) {
            if (scene == nullptr)
                throw std::runtime_error("Scene is null");
            std::cout << "Change scene" << std::endl;
            charScene = static_cast<CharacterSelector *>(scene);
            Game *game = new Game(charScene->getModels(), this->_characterChoosen);
            click->setEcs(game->getECS());
            std::cout << "Change scene" << std::endl;
            //delete (charScene);
        } else if (click->_tmpEcs == SCENE_MENU) {
            Menu *menu = new Menu();
            click->setEcs(menu->getECS());
            if (scene != nullptr)
                delete (static_cast<Settings *>(scene));
        } else if (click->_tmpEcs == SCENE_SETTINGS) {
            Settings *settings = new Settings();
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
    case CLICKABLE_ACTION_CHOOSE_CHARACTER:
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