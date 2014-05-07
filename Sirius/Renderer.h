/* 
 * File:   Renderer.h
 * Author: Suyash Mohan
 *
 * Created on 3 May, 2014, 3:27 PM
 */

#ifndef RENDERER_H
#define	RENDERER_H

#include "SDL.h"
#include "Window.h"
#include <memory>

namespace Sirius
{
    class Renderer {
    public:
        Renderer();
        Renderer(WindowPtr window);
        virtual ~Renderer();
        SDL_Renderer* getSDLRenderer();
        void setLogicalSize(int width, int height);
        void setScale(float scale);
        void setBackgroundColor(int r,int g,int b);
        int getWidth();
        int getHeight();
        void clear();
        void present();
    private:
        SDL_Renderer* m_renderer;
        void createRenderer(WindowPtr window);
    };
    
    typedef std::shared_ptr<Renderer> RendererPtr;
}

#endif	/* RENDERER_H */

