/* 
 * File:   Window.h
 * Author: Suyash Mohan
 *
 * Created on 3 May, 2014, 3:14 PM
 */

#ifndef WINDOW_H
#define	WINDOW_H

#include "SDL.h"
#include "Window.h"
#include <string>
#include <memory>

namespace Sirius
{
    class Window {
    public:
        Window();
        Window(int width, int height);
        virtual ~Window();
        SDL_Window *getSDLWindow();
        bool step();
        int getWidth();
        int getHeight();
    private:
        static bool isInstantiated;
        SDL_Window *m_window;
        int m_width;
        int m_height;
        std::string m_title;
        void initSDL();
        void createWindow(int width, int height);
    };
    
    typedef std::shared_ptr<Window> WindowPtr;
}

#endif	/* WINDOW_H */

