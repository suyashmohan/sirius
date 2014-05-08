/* 
 * File:   Image.h
 * Author: Suyash Mohan
 *
 * Created on 3 May, 2014, 3:15 PM
 */

#ifndef IMAGE_H
#define	IMAGE_H

#include "Game.h"
#include "Graphic.h"
#include "Texture.h"
#include "Typedefs.h"
#include <string>

namespace Sirius
{   
    class Image:public Graphic {
    public:
        static GraphicPtr Create(std::string file);
        static GraphicPtr Create(TexturePtr texture);
        Image(std::string file);
        Image(TexturePtr texture);
        virtual ~Image();
        virtual void render(int x,int y,float scaleX,float scaleY,float angle);
        TexturePtr getTexture();
    private:
        TexturePtr m_texture;
        GamePtr game;
    };
}

#endif	/* IMAGE_H */

