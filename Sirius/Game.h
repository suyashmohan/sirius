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
#include "Typedefs.h"

namespace Sirius
{
    class Game {
    private:
        struct construct_key {};
        void init(int width, int height);
        static GamePtr instance;
        WindowPtr m_window;
        RendererPtr m_renderer;   
        ResourceManagerPtr m_resources;
        std::map<std::string, ScenePtr> m_scenes;
        ScenePtr m_currentScene;
    public:
        Game(construct_key);
        virtual ~Game();
        static GamePtr initialize(int width=640, int height=480);        
        static GamePtr getInstance();
        static void terminate();
        void run(std::string scene);
        void switchScene(std::string scene);
        WindowPtr getWindow();
        RendererPtr getRenderer();    
        ResourceManagerPtr getResourceManager();
        float ticks;
        float getTicks();
        ScenePtr addScene(std::string name, ScenePtr scene);
        ScenePtr removeScene(std::string name);
        ScenePtr findScene(std::string name);        
        unsigned int removeAllScenes();
        unsigned int countScenes();
    };
}

#endif	/* GAME_H */

