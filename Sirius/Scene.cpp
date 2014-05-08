/* 
 * File:   Scene.cpp
 * Author: Suyash Mohan
 * 
 * Created on 3 May, 2014, 3:14 PM
 */

#include <stdexcept>
#include "Scene.h"
#include "Game.h"
#include "Utility.h"

namespace Sirius
{    
    Scene::Scene() 
    {
        game = Sirius::Game::getInstance();
        if(game == nullptr)
            throw std::runtime_error("[Scene] Unable to create a scene. Game is not initialized");
        window = game->getWindow();
        renderer = game->getRenderer();
        resources = game->getResourceManager();
    }
    Scene::~Scene(){}
    
    void Scene::begin(){}
    void Scene::end(){}
    void Scene::update(){}
    
    void Scene::updateEntities() {
        for(std::map<std::string, EntityPtr>::iterator it=m_entities.begin(); it!=m_entities.end(); ++it)
        {
            it->second->update();
        }
    }
    
    void Scene::postBegin() {
        for(std::map<std::string, EntityPtr>::iterator it=m_entities.begin(); it!=m_entities.end(); ++it)
        {
            it->second->begin();
        }
    }
    
    void Scene::preEnd() {
        for(std::map<std::string, EntityPtr>::iterator it=m_entities.begin(); it!=m_entities.end(); ++it)
        {
            it->second->end();
        }
    }
    
    void Scene::render() {
        for(std::map<std::string, EntityPtr>::iterator it=m_entities.begin(); it!=m_entities.end(); ++it)
        {
            it->second->render();
        }
    }
    
    EntityPtr Scene::addEntity(std::string name, EntityPtr entity)
    {
        std::pair<std::map<std::string,EntityPtr>::iterator,bool> ret;
        ret = m_entities.insert(std::pair<std::string,EntityPtr>(name, entity));
        if(ret.second == false)
        {
            Utility::Log::Warning("[Scene] Unable to add Entity to scene - "+name);
            return NULL;
        }
        else
        {
            Utility::Log::Info("[Scene] Entity added to scene - "+name);
            return ret.first->second;
        }
    }
    
    EntityPtr Scene::findEntity(std::string name)
    {
        EntityPtr entity = nullptr;
        std::map<std::string, EntityPtr>::iterator it = m_entities.find(name);
        if(it != m_entities.end())
            entity = it->second;
        return entity;
    }
    
    EntityPtr Scene::removeEntity(std::string name)
    {
        EntityPtr entity = nullptr;
        std::map<std::string, EntityPtr>::iterator it = m_entities.find(name);
        if(it != m_entities.end())
        {
            entity = it->second;
            m_entities.erase(it);
            Utility::Log::Info("[Scene] Entity removed from scene - "+name);
        }
        else
        {
            Utility::Log::Warning("[Scene] Unable to remove Entity from scene - "+name);
        }
        return entity;
    }
    
    unsigned int Scene::removeAllEntities()
    {
        unsigned int size = countEntities();
        //m_entities.clear();
        std::map<std::string, EntityPtr>::iterator it=m_entities.begin();
        while(it != m_entities.end())
        {
            removeEntity(it->first);
            it = m_entities.begin();
        }
        return size;
    }
    
    unsigned int Scene::countEntities()
    {
        return m_entities.size();
    }

}

