/* 
 * File:   Renderer.h
 * Author: Suyash Mohan
 *
 * Created on 3 May, 2014, 3:27 PM
 */

#ifndef RENDERER_H
#define	RENDERER_H

#include <SDL.h>
#include "Window.h"
#include "Typedefs.h"

namespace Sirius
{   
    class Renderer {
    public:
        Renderer(WindowPtr window);
        virtual ~Renderer();
        SDL_Renderer* getSDLRenderer();
        void setLogicalSize(int width, int height);
        void setScale(float scale);
        void setBackgroundColor(int r,int g,int b);
        bool setScaleFilter(ScaleFilter filter);
        int getWidth();
        int getHeight();
        void clear();
        void present();         
    private:
        SDL_Renderer* m_renderer;
        void createRenderer(WindowPtr window);
    };
}

#endif	/* RENDERER_H */

