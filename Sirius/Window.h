/* 
 * File:   Window.h
 * Author: Suyash Mohan
 *
 * Created on 3 May, 2014, 3:14 PM
 */

#ifndef WINDOW_H
#define	WINDOW_H

#include <SDL.h>
#include "Window.h"
#include "Typedefs.h"
#include <string>

namespace Sirius
{   
    class Window {
    public:
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
}

#endif	/* WINDOW_H */

