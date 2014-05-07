/* 
 * File:   Texture.h
 * Author: Suyash Mohan
 *
 * Created on 3 May, 2014, 3:15 PM
 */

#ifndef TEXTURE_H
#define	TEXTURE_H

#include "SDL.h"
#include "Renderer.h"
#include <string>
#include <memory>

namespace Sirius
{
    class Texture {
    public:
        Texture();
        Texture(RendererPtr renderer,std::string file);
        virtual ~Texture();
        void loadTexture(RendererPtr renderer,std::string file);
        void drawTexture(RendererPtr renderer, int x,int y);
    private:
        SDL_Texture *m_texture;
        int m_width;
        int m_height;
        std::string path;
    };
    
    typedef std::shared_ptr<Texture> TexturePtr;
}

#endif	/* TEXTURE_H */

