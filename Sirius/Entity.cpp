/* 
 * File:   Entity.cpp
 * Author: Suyash Mohan
 * 
 * Created on 3 May, 2014, 3:15 PM
 */

#include "Entity.h"
#include <SDL.h>

namespace Sirius
{
    Entity::Entity() {
        position.x = 0;
        position.y = 0;
        scale.x = 1.0f;
        scale.y = 1.0f;
        angle = 0.0f;
    }

    Entity::~Entity() {}
    
    void Entity::begin(){}
    void Entity::end(){}
    void Entity::update(){}
    
    void Entity::render()
    {
        if(graphic != nullptr)
            graphic->render(position.x, position.y,scale.x,scale.y,angle);
    }
}
