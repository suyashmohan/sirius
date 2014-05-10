/* 
 * File:   Scene.h
 * Author: Suyash Mohan
 *
 * Created on 3 May, 2014, 3:14 PM
 */

#ifndef SCENE_H
#define	SCENE_H

#include "Typedefs.h"
#include "Game.h"
#include "Window.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include "Entity.h"
#include <map>
#include <string>
#include <memory>

namespace Sirius
{   
    class Scene {
    public:
        template <typename T>
        static ScenePtr Create()
        {
            return std::dynamic_pointer_cast<Sirius::Scene>(std::make_shared<T>());
        }
        
        template <typename T>
        static ScenePtr Create(std::shared_ptr<T> ptr)
        {
            return std::dynamic_pointer_cast<Sirius::Scene>(ptr);
        }
        
        Scene();
        virtual ~Scene();
        virtual void begin();
        virtual void end();
        virtual void update(float delta);
        void updateEntities(float delta);
        void postBegin();
        void preEnd();
        void render();
        EntityPtr addEntity(std::string name, EntityPtr entity);
        EntityPtr removeEntity(std::string name);
        EntityPtr findEntity(std::string name);        
        unsigned int removeAllEntities();
        unsigned int countEntities();
    protected:
        GamePtr game;
        WindowPtr window;
        RendererPtr renderer;
        ResourceManagerPtr resources;
    private:
        std::map<std::string, EntityPtr> m_entities;
    };
}

#endif	/* SCENE_H */

