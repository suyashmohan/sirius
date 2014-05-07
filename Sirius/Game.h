/* 
 * File:   Game.h
 * Author: Suyash Mohan
 *
 * Created on 3 May, 2014, 3:13 PM
 */

#ifndef GAME_H
#define	GAME_H

#include "Scene.h"
#include "Window.h"
#include "Renderer.h"
#include "ResourceManager.h"
#include <memory>

namespace Sirius
{
    class Game;
    typedef std::shared_ptr<Game> GamePtr;
    
    class Game {
    private:
        struct construct_key {};
        void init(int width, int height);
        static GamePtr instance;
        WindowPtr m_window;
        RendererPtr m_renderer;   
        ResourceManagerPtr m_resources;
    public:
        Game(construct_key);
        virtual ~Game();
        static GamePtr initialize(int width=640, int height=480);        
        static GamePtr getInstance();
        static void terminate();
        void run(ScenePtr scene);
        WindowPtr getWindow();
        RendererPtr getRenderer();    
        ResourceManagerPtr getResourceManager();
    };
}

#endif	/* GAME_H */

