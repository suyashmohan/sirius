/* 
 * File:   Game.cpp
 * Author: Suyash Mohan
 * 
 * Created on 3 May, 2014, 3:13 PM
 */

#include "Game.h"
#include "Utility.h"
#include <SDL.h>

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
        ticks = getTicks();
    }
    
    void Game::run(std::string sceneName)
    {
        if(m_renderer != nullptr && m_window != nullptr)
        {
            ScenePtr scene = findScene(sceneName);
            if(scene == nullptr)
            {
                Utility::Log::Error("[Game] Unable to run the scene. Scene not found - "+sceneName);
                return;
            }
            m_currentScene = scene;
            Utility::Log::Info("[Game] Running scene - "+sceneName);
            
            bool quit = false;
            float newTicks = 0.0f;
            scene->begin();
            scene->postBegin();
            while(!quit)
            {
                newTicks = getTicks();
                m_renderer->clear();
                scene->updateEntities(newTicks-ticks);
                scene->update(newTicks-ticks);
                scene->render();
                m_renderer->present();
                quit = m_window->step();
                ticks = newTicks;
                
                if(m_currentScene != scene)
                {
                    scene->preEnd();
                    scene->end();
                    scene = m_currentScene;
                    scene->begin();
                    scene->postBegin();
                }
            }
            scene->preEnd();
            scene->end();
        }
        else
        {
            throw std::runtime_error("[Game] Game components have not be initialized");
        }
    }
    
    void Game::switchScene(std::string sceneName)
    {
        ScenePtr scene = findScene(sceneName);
        if(scene != nullptr)
        {
            m_currentScene = scene;
            Utility::Log::Info("[Game] Switching scene - "+sceneName);
        }
        else
        {
            Utility::Log::Info("[Game] Unable to switch scene. Scene not found - "+sceneName);
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
    
    float Game::getTicks()
    {
        float sdlTicks = (float)SDL_GetTicks();
        return sdlTicks/1000.0f;
    }
    
    ScenePtr Game::addScene(std::string name, ScenePtr scene)
    {
        std::pair<std::map<std::string,ScenePtr>::iterator,bool> ret;
        ret = m_scenes.insert(std::pair<std::string,ScenePtr>(name, scene));
        if(ret.second == false)
        {
            Utility::Log::Warning("[Game] Unable to add Scene to game - "+name);
            return NULL;
        }
        else
        {
            Utility::Log::Info("[Game] Scene added to game - "+name);
            return ret.first->second;
        }
    }
    
    ScenePtr Game::removeScene(std::string name)
    {
        ScenePtr scene = nullptr;
        std::map<std::string, ScenePtr>::iterator it = m_scenes.find(name);
        if(it != m_scenes.end())
        {
            scene = it->second;
            m_scenes.erase(it);
            Utility::Log::Info("[Game] Scene removed from game - "+name);
        }
        else
        {
            Utility::Log::Warning("[Game] Unable to remove Scene from game - "+name);
        }
        return scene;
    }
    
    ScenePtr Game::findScene(std::string name)
    {
        ScenePtr scene = nullptr;
        std::map<std::string, ScenePtr>::iterator it = m_scenes.find(name);
        if(it != m_scenes.end())
            scene = it->second;
        return scene;
    }
    
    unsigned int Game::removeAllScenes()
    {
        unsigned int size = countScenes();
        //m_entities.clear();
        std::map<std::string, ScenePtr>::iterator it=m_scenes.begin();
        while(it != m_scenes.end())
        {
            removeScene(it->first);
            it = m_scenes.begin();
        }
        return size;
    }
    
    unsigned int Game::countScenes()
    {
        return m_scenes.size();
    }
}

