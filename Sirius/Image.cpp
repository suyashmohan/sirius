/* 
 * File:   Image.cpp
 * Author: Suyash Mohan
 * 
 * Created on 3 May, 2014, 3:15 PM
 */

#include "Image.h"
#include "Game.h"
#include <stdexcept>

namespace Sirius
{
    GraphicPtr Image::Create(std::string file)
    {
        ImagePtr img = std::make_shared<Image>(file);
        GraphicPtr grph = std::dynamic_pointer_cast<Graphic>(img);
        return grph;
    }
    
    GraphicPtr Image::Create(TexturePtr texture)
    {
        ImagePtr img = std::make_shared<Image>(texture);
        GraphicPtr grph = std::dynamic_pointer_cast<Graphic>(img);
        return grph;
    }
    
    Image::Image(std::string path) {
        game = Sirius::Game::getInstance();
        if(game == nullptr)
            throw std::runtime_error("Error creating Image. Game not initialized");
        m_texture = std::make_shared<Texture>(game->getRenderer(),path);
        if(m_texture == nullptr)
            throw std::runtime_error("Error creating Image. nullptr is not allowed");
    }
    
    Image::Image(TexturePtr texture)
    {
        game = Sirius::Game::getInstance();
        if(game == nullptr)
            throw std::runtime_error("Error creating Image. Game not initialized");
        if(texture == nullptr)
            throw std::runtime_error("Error creating Image. nullptr is not allowed");
        m_texture = texture;
    }
    
    Image::~Image() {
        if(m_texture != nullptr)
            m_texture.reset();
    }
    
    void Image::render(int x, int y, float scaleX, float scaleY, float angle)
    {
        if(m_texture != nullptr)
        {
            if(game == nullptr)
                throw std::runtime_error("Error creating Image. Game not initialized");
            m_texture->drawTexture(game->getRenderer(), x, y);
        }
    }
}

