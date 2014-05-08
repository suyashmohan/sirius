/* 
 * File:   ResourceManager.cpp
 * Author: Suyash Mohan
 *  
 * Created on 7 May, 2014, 7:27 PM
 */

#include "ResourceManager.h"
#include "Game.h"
#include "Utility.h"

namespace Sirius
{
    ResourceManager::ResourceManager() {}
    ResourceManager::~ResourceManager() {}
    
    TexturePtr ResourceManager::addTexture(std::string name, std::string path)
    {
        Sirius::GamePtr game = Sirius::Game::getInstance();
        if(game == nullptr)
            throw std::runtime_error("[ResourceManager] Unable to add texture to resource manager. Game is not initialized");
        TexturePtr tex = std::make_shared<Texture>(game->getRenderer(),path);
        if(tex == nullptr)
            throw std::runtime_error("[ResourceManager] Unable to add texture to resource manager");
        
        std::pair<std::map<std::string,TexturePtr>::iterator,bool> ret;
        ret = m_textures.insert(std::pair<std::string,TexturePtr>(name, tex));
        if(ret.second == false)
        {
            Utility::Log::Warning("[ResourceManager] Unable to add texture to resource manager");
            return NULL;
        }
        else
        {
            Utility::Log::Info("[ResourceManager] Texture added to resource manager");
            return ret.first->second;
        }
    }
    
    TexturePtr ResourceManager::removeTexture(std::string name)
    {
        TexturePtr tex = nullptr;
        std::map<std::string, TexturePtr>::iterator it = m_textures.find(name);
        if(it != m_textures.end())
        {
            tex = it->second;
            m_textures.erase(it);
            Utility::Log::Info("[ResourceManager] Texture removed from resource manager");
        }
        else
        {
            Utility::Log::Warning("[ResourceManager] Unable to remove texture from resource manager");
        }
        
        return tex;
    }
    
    TexturePtr ResourceManager::getTexture(std::string name)
    {
        TexturePtr tex = nullptr;
        std::map<std::string, TexturePtr>::iterator it = m_textures.find(name);
        if(it != m_textures.end())
            tex = it->second;
        return tex;
    }
    
    unsigned int ResourceManager::clear()
    {
        unsigned int size = m_textures.size();
        //m_textures.clear();
        std::map<std::string, TexturePtr>::iterator it=m_textures.begin();
        while(it != m_textures.end())
        {
            removeTexture(it->first);
            it = m_textures.begin();
        }
        
        return size;
    }
}
