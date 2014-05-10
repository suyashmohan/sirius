/* 
 * File:   Entity.h
 * Author: Suyash Mohan
 *
 * Created on 3 May, 2014, 3:15 PM
 */

#ifndef ENTITY_H
#define	ENTITY_H

#include "Typedefs.h"
#include "Game.h"
#include "Window.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include "Graphic.h"
#include <memory>

namespace Sirius
{
    class Entity{
    public:
        template <typename T>
        static EntityPtr Create()
        {
            return std::dynamic_pointer_cast<Entity>(std::make_shared<T>());
        }
        
        template <typename T>
        static EntityPtr Create(std::shared_ptr<T> ptr)
        {
            return std::dynamic_pointer_cast<Entity>(ptr);
        }
        
        Point position;
        PointF scale;
        float angle;
        
        Entity();
        virtual ~Entity();
        virtual void begin();
        virtual void update(float delta);
        virtual void end();
        void render();
    protected:
        GraphicPtr graphic;
        GamePtr game;
        WindowPtr window;
        RendererPtr renderer;
        ResourceManagerPtr resources;
    private:
        
    };
}
#endif	/* ENTITY_H */

