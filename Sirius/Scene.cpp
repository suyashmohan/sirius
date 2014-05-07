/* 
 * File:   Scene.cpp
 * Author: Suyash Mohan
 * 
 * Created on 3 May, 2014, 3:14 PM
 */

#include <stdexcept>
#include "Scene.h"
#include "Game.h"

namespace Sirius
{    
    Scene::Scene() {}
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
            return NULL;
        else
            return ret.first->second;
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
        }
        return entity;
    }
    
    unsigned int Scene::removeAllEntities()
    {
        unsigned int size = countEntities();
        m_entities.clear();
        return size;
    }
    
    unsigned int Scene::countEntities()
    {
        return m_entities.size();
    }

}

