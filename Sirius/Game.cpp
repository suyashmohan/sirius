/* 
 * File:   Game.cpp
 * Author: Suyash Mohan
 * 
 * Created on 3 May, 2014, 3:13 PM
 */

#include "Game.h"
#include "Utility.h"

namespace Sirius
{
    GamePtr Game::instance = nullptr;
    
    Game::Game(construct_key) {
        m_window = nullptr;
        m_renderer = nullptr;
        m_resources = nullptr;
        Utility::Log::Info("[Game] Sirius Initialized");
    }

    Game::~Game() {
        if(m_renderer != nullptr)
            m_renderer.reset();
        if(m_window != nullptr)
            m_window.reset();
        
        Utility::Log::Info("[Game] Sirius Terminated");
    }
    
    GamePtr Game::initialize(int width, int height)
    {
        if(Game::instance == nullptr)
        {
            Game::instance = std::make_shared<Game>(construct_key());
            Game::instance->init(width, height);
        }
        return Game::instance;
    }
    
    void Game::terminate()
    {
        if(Game::instance != nullptr)
        {
            Game::instance->m_resources->clear();
            Game::instance.reset();            
        }
    }
    
    GamePtr Game::getInstance()
    {
        return Game::instance;
    }
    
    void Game::init(int width, int height)
    {
        m_window = std::make_shared<Window>(width, height);
        m_renderer = std::make_shared<Renderer>(m_window);
        m_resources = std::make_shared<ResourceManager>();
    }
    
    void Game::run(ScenePtr scene)
    {
        if(scene != nullptr && m_renderer != nullptr && m_window != nullptr)
        {
            bool quit = false;
            scene->begin();
            scene->postBegin();
            while(!quit)
            {
                m_renderer->clear();
                scene->updateEntities();
                scene->update();
                scene->render();
                m_renderer->present();
                quit = m_window->step();
            }
            scene->preEnd();
            scene->end();
        }
    }
    
    WindowPtr Game::getWindow()
    {
        return m_window;
    }
    
    RendererPtr Game::getRenderer()
    {
        return m_renderer;
    }
    
    ResourceManagerPtr Game::getResourceManager()
    {
        return m_resources;
    }
}

