/* 
 * File:   Texture.cpp
 * Author: Suyash Mohan
 * 
 * Created on 3 May, 2014, 3:15 PM
 */

#include "Texture.h"
#include "Utility.h"
#include <stdexcept>

namespace Sirius
{
    Texture::Texture() {
        m_texture = NULL;
        m_width = 0;
        m_height = 0;
        path = "";
    }
    
    Texture::Texture(RendererPtr renderer, std::string file)
    {
        m_texture = NULL;
        m_width = 0;
        m_height = 0;
        loadTexture(renderer, file);
    }

    Texture::~Texture() {
        if(m_texture != NULL)
        {
            SDL_DestroyTexture(m_texture);
            Utility::Log::Info("[Texture] Texture Destroyed - "+path);
        }
    }
    
    void Texture::loadTexture(RendererPtr renderer, std::string file)
    {
        path = file;
        SDL_Surface *image = SDL_LoadBMP(file.c_str());
        if(image == NULL)
        {
            std::string sdlError("[Texture] Unable to load image : ");
            sdlError += SDL_GetError();
            throw std::runtime_error(sdlError);
        }
        m_width = image->w;
        m_height = image->h;
        m_texture = SDL_CreateTextureFromSurface(renderer->getSDLRenderer(), image);
        SDL_FreeSurface(image);
        if(m_texture == NULL)
        {
            std::string sdlError("[Texture] Unable to create texture : ");
            sdlError += SDL_GetError();
            throw std::runtime_error(sdlError);
        }
        Utility::Log::Info("[Texture] Texture Loaded - "+path);
    }
    
    void Texture::drawTexture(RendererPtr renderer, int x, int y)
    {
        if(m_texture != NULL)
        {
            SDL_Rect *src = new SDL_Rect();
            SDL_Rect *dest = new SDL_Rect();

            src->x = 0;
            src->y = 0;
            src->w = m_width;
            src->h = m_height;

            dest->x = x;
            dest->y = y;
            dest->w = m_width;
            dest->h = m_height;

            SDL_RenderCopy(renderer->getSDLRenderer(),m_texture,src,dest);
            delete src;
            delete dest;
        }
    }

}

