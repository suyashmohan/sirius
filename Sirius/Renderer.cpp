/* 
 * File:   Renderer.cpp
 * Author: Suyash Mohan
 * 
 * Created on 3 May, 2014, 3:27 PM
 */

#include "Renderer.h"
#include "Utility.h"
#include <stdexcept>
#include <memory>

namespace Sirius
{
    Renderer::Renderer()
    {
        m_renderer = NULL;
    }
    
    Renderer::Renderer(WindowPtr window)
    {
        m_renderer = NULL;
        createRenderer(window);
    }

    Renderer::~Renderer() {
        if(m_renderer != NULL)
        {
            SDL_DestroyRenderer(m_renderer);
            Utility::Log::Info("Renderer Destroyed");
        }
    }
    
    void Renderer::createRenderer(WindowPtr window)
    {
        m_renderer = SDL_CreateRenderer(window->getSDLWindow(),-1,SDL_RENDERER_ACCELERATED /*| SDL_RENDERER_PRESENTVSYNC*/);
        if(m_renderer == NULL)
        {
            std::string sdlError("Unable to create a renderer : ");
            sdlError += SDL_GetError();
            throw std::runtime_error(sdlError);
        }
        Utility::Log::Info("Renderer Created");
    }
    
    SDL_Renderer *Renderer::getSDLRenderer()
    {
        return m_renderer;
    }
    
    void Renderer::clear()
    {
        if(m_renderer)
            SDL_RenderClear(m_renderer);
    }
    
    void Renderer::present()
    {
        if(m_renderer)
            SDL_RenderPresent(m_renderer);
    }
    
    void Renderer::setLogicalSize(int width, int height)
    {
        if(m_renderer)
            SDL_RenderSetLogicalSize(m_renderer,width,height);
    }
    
    void Renderer::setScale(float scale)
    {
        if(m_renderer)
            SDL_RenderSetScale(m_renderer,scale,scale);
    }
    
    void Renderer::setBackgroundColor(int r, int g, int b)
    {
        if(m_renderer)
            SDL_SetRenderDrawColor(m_renderer, r,g,b,255);
    }
    
    int Renderer::getWidth()
    {
        SDL_Rect box;
        if(m_renderer)
            SDL_RenderGetViewport(m_renderer,&box);
        return box.w;
    }
    
    int Renderer::getHeight()
    {
        SDL_Rect box;
        if(m_renderer)
            SDL_RenderGetViewport(m_renderer,&box);
        return box.h;
    }
}

