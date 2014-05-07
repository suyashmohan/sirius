/* 
 * File:   ResourceManager.cpp
 * Author: Suyash Mohan
 *  
 * Created on 7 May, 2014, 7:27 PM
 */

#include "ResourceManager.h"
#include "Game.h"

namespace Sirius
{
    ResourceManager::ResourceManager() {}
    ResourceManager::~ResourceManager() {}
    
    TexturePtr ResourceManager::addTexture(std::string name, std::string path)
    {
        Sirius::GamePtr game = Sirius::Game::getInstance();
        if(game == nullptr)
            throw std::runtime_error("Error add texture to resource manager");
        TexturePtr tex = std::make_shared<Texture>(game->getRenderer(),path);
        if(tex == nullptr)
            throw std::runtime_error("Error creating Texture");
        
        std::pair<std::map<std::string,TexturePtr>::iterator,bool> ret;
        ret = m_textures.insert(std::pair<std::string,TexturePtr>(name, tex));
        if(ret.second == false)
            return NULL;
        else
            return ret.first->second;
    }
    
    TexturePtr ResourceManager::removeTexture(std::string name)
    {
        TexturePtr tex = nullptr;
        std::map<std::string, TexturePtr>::iterator it = m_textures.find(name);
        if(it != m_textures.end())
        {
            tex = it->second;
            m_textures.erase(it);
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
    
    void ResourceManager::clear()
    {
        m_textures.clear();
    }
}
