/* 
 * File:   Entity.cpp
 * Author: Suyash Mohan
 * 
 * Created on 3 May, 2014, 3:15 PM
 */

#include "Entity.h"

namespace Sirius
{
    Entity::Entity() {
        game = Sirius::Game::getInstance();
        if(game == nullptr)
            throw std::runtime_error("[Entity] Unable to create an Entity. Game is not initialized");
        window = game->getWindow();
        renderer = game->getRenderer();
        resources = game->getResourceManager();
        
        position.x = 0;
        position.y = 0;
        scale.x = 1.0f;
        scale.y = 1.0f;
        angle = 0.0f;
    }

    Entity::~Entity() {}
    
    void Entity::begin(){}
    void Entity::end(){}
    void Entity::update(float delta){}
    
    void Entity::render()
    {
        if(graphic != nullptr)
            graphic->render(position.x, position.y,scale.x,scale.y,angle);
    }
}
