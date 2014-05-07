/* 
 * File:   Window.cpp
 * Author: Suyash Mohan
 * 
 * Created on 3 May, 2014, 3:14 PM
 */

#include "Window.h"
#include "Utility.h"
#include <sstream>
#include <stdexcept>

namespace Sirius
{
    bool Window::isInstantiated = false;
    
    Window::Window()
    {
        m_window = NULL;
        m_width = 0;
        m_height = 0;
        m_title = "Sirius";
    }
    
    Window::Window(int width, int height) 
    {
        m_window = NULL;
        m_width = width;
        m_height = height;
        m_title = "Sirius";
        if(Window::isInstantiated == true)
        {
            std::string sdlError("Only Single Instance of Window is allowed");
            sdlError += SDL_GetError();
            throw std::runtime_error(sdlError);
        }
        else
        {
            initSDL();
            createWindow(width, height);
        }
    }

    Window::~Window() {
        if(m_window != NULL)
        {
            SDL_DestroyWindow(m_window);
            Utility::Log::Info("Window Destroyed");
        }
        SDL_Quit();
        Utility::Log::Info("SDL Terminated");
    }
    
    void Window::initSDL()
    {
        if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
        {
            std::string sdlError("Unable to Initialize SDL : ");
            sdlError += SDL_GetError();
            throw std::runtime_error(sdlError);
        }
        Window::isInstantiated = true;
        Utility::Log::Info("SDL Initialized");
    }
    
    void Window::createWindow(int width, int height)
    {
        m_window = SDL_CreateWindow(m_title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
        if(m_window == NULL)
        {
            std::string sdlError("Unable to create a window : ");
            sdlError += SDL_GetError();
            throw std::runtime_error(sdlError);
        }
        SDL_GetWindowSize(m_window, &m_width, &m_height);
        std::stringstream ss;
        ss << "Window Created " << m_width << "x" << m_height;
        Utility::Log::Info(ss.str().c_str());
    }
    
    SDL_Window *Window::getSDLWindow()
    {
        return m_window;
    }
    
    bool Window::step()
    {
        SDL_Event evnt;
        bool quit = false;
        
        while(SDL_PollEvent(&evnt))
        {
            if(evnt.type == SDL_QUIT)
                quit = true;
        }
        
        return quit;
    }
    
    int Window::getWidth()
    {
        return m_width;
    }
    
    int Window::getHeight()
    {
        return m_height;
    }
}
