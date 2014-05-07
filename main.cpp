#include <iostream>
#include <stdexcept>
#include <SDL.h>
#include "Sirius/Sirius.h"

class GameObject2: public Sirius::Entity
{
    float x,y;
    float dx, dy;
public:
    GameObject2(float px, float py, float _dx, float _dy)
    {        
        x = px;
        y = py;
        dx = _dx;
        dy = _dy;
    }
    void begin()
    {        
        graphic = Sirius::Image::Create(Sirius::Game::getInstance()->getResourceManager()->getTexture("smiley2"));
        position.x = (int)x;
        position.y = (int)y;
    }
    void end()
    {     
        
    }
    void update()
    {
        x += dx;
        y += dy;
        position.x = (int)x;
        position.y = (int)y;
        
        if(x >= Sirius::Game::getInstance()->getRenderer()->getWidth() / 2)
        {
            x = 0;
            y = 0;
        }
    }
};

class GameObject: public Sirius::Entity
{
    float x,y;
    float dx, dy;
public:
    GameObject(float px, float py, float _dx, float _dy)
    {        
        x = px;
        y = py;
        dx = _dx;
        dy = _dy;
    }
    void begin()
    {        
        graphic = Sirius::Image::Create(Sirius::Game::getInstance()->getResourceManager()->getTexture("smiley1"));
        position.x = (int)x;
        position.y = (int)y;
    }
    void end()
    {     
        
    }
    void update()
    {
        x += dx;
        y += dy;
        position.x = (int)x;
        position.y = (int)y;
    }

};

class GameScene: public Sirius::Scene
{  
public:
    void begin()
    {
        Sirius::Game::getInstance()->getResourceManager()->addTexture("smiley1","smiley.bmp");
        Sirius::Game::getInstance()->getResourceManager()->addTexture("smiley2","smiley2.bmp");
        addEntity("object", Sirius::Entity::Create(std::make_shared<GameObject>(0.0f,0.0f,0.1f,0.01f)));
        addEntity("object2", Sirius::Entity::Create(std::make_shared<GameObject>(0.0f,0.0f,0.01f,0.1f)));
        addEntity("object3", Sirius::Entity::Create(std::make_shared<GameObject2>(0.0f,0.0f,0.05f,0.05f)));
        
        Sirius::Game::getInstance()->getRenderer()->setBackgroundColor(255,255,255);
    }
    
    void update()
    {
        
    }
    
    void end()
    {
        
    }
};

int main(int argc, char **argv){

    try
    {
        Sirius::GamePtr game = Sirius::Game::initialize(480,640);
        Sirius::ScenePtr scene = Sirius::Scene::Create<GameScene>();
        game->run(scene);   
        Sirius::Game::terminate();
    }
    catch(std::runtime_error e)
    {
        Sirius::Utility::Log::Error(e.what());
    }
    return 0;
}

