/*
** EPITECH PROJECT, 2022
** B-YEP-400-LIL-4-1-indiestudio-clement.chausson
** File description:
** Loading
*/

#ifndef LOADING_HPP_
#define LOADING_HPP_

#include "../../ISystem/ISystem.hpp"
#include "../../Components/Drawable/DrawableSprite.hpp"
#include "../../Components/Placable/Placable.hpp"
#include "../../Components/Loadable/Loadable.hpp"

class Loading : public ISystem {
    public:
        Loading();
        ~Loading();
        void apply(std::vector<IComponent *> component) override;
        virtual SYSTEM_TYPES getType() override;

    protected:
    private:
        std::chrono::time_point<std::chrono::system_clock> _clock;
};

#endif /* !LOADING_HPP_ */
