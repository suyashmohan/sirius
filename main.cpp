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
        graphic = Sirius::Image::Create(resources->getTexture("smiley2"));
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
        
        if(x >= renderer->getWidth() / 2)
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
        graphic = Sirius::Image::Create(resources->getTexture("smiley1"));
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
        renderer->setScaleFilter(Sirius::ScaleFilter::Linear);
        renderer->setLogicalSize(512,300);
        resources->addTexture("smiley1","smiley.bmp");
        resources->addTexture("smiley2","smiley2.bmp");
        
        addEntity("object", Sirius::Entity::Create(std::make_shared<GameObject>(0.0f,0.0f,0.01f,0.001f)));
        addEntity("object2", Sirius::Entity::Create(std::make_shared<GameObject>(0.0f,0.0f,0.001f,0.01f)));
        addEntity("object3", Sirius::Entity::Create(std::make_shared<GameObject2>(0.0f,0.0f,0.005f,0.005f)));
        
        renderer->setBackgroundColor(255,255,255);
    }
    
    void update()
    {
        
    }
    
    void end()
    {
        removeAllEntities();
        resources->clear();
    }
};

int main(int argc, char **argv){

    try
    {
        Sirius::GamePtr game = Sirius::Game::initialize(1024,600);
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

