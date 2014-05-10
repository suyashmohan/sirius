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
    void update(float delta)
    {
        x += delta*dx;
        y += delta*dy;
        position.x = (int)x;
        position.y = (int)y;
        
        if(x >= renderer->getWidth() / 2)
        {
            x = 0;
            y = 0;
            game->switchScene("level1");
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
    void update(float delta)
    {
        x += delta*dx;
        y += delta*dy;
        position.x = (int)x;
        position.y = (int)y;
        
        if(x >= renderer->getHeight())
        {
            x = 0;
            y = 0;
            game->switchScene("level2");
        }
    }

};

class GameScene2: public Sirius::Scene
{  
    int fps;
    float time;
public:
    GameScene2(){ fps = 0; time = 0.0f;}
    void begin()
    {
        renderer->setScaleFilter(Sirius::ScaleFilter::Linear);
        renderer->setLogicalSize(1024,600);
        resources->addTexture("smiley2","smiley2.bmp");
        
        addEntity("object", Sirius::Entity::Create(std::make_shared<GameObject2>(0.0f,0.0f,50.0f,50.0f)));
        
        renderer->setBackgroundColor(0,0,0);
    }
    
    void update(float delta)
    {
        fps += 1;
        time += delta;
        if(time > 1.0f)
        {
            //std::cout << "Scene2 FPS : " << fps << std::endl;
            fps = 0;
            time = 0.0f;
        }
    }
    
    void end()
    {
        removeAllEntities();
        resources->clear();
    }
};

class GameScene: public Sirius::Scene
{  
    int fps;
    float time;
public:
    GameScene(){ fps = 0; time = 0.0f;}
    void begin()
    {
        renderer->setScaleFilter(Sirius::ScaleFilter::Linear);
        renderer->setLogicalSize(512,300);
        resources->addTexture("smiley1","smiley.bmp");
        
        addEntity("object", Sirius::Entity::Create(std::make_shared<GameObject>(0.0f,0.0f,100.0f,80.0f)));
        
        renderer->setBackgroundColor(255,255,255);
    }
    
    void update(float delta)
    {
        fps += 1;
        time += delta;
        if(time > 1.0f)
        {
            //std::cout << "Scene1 FPS : " << fps << std::endl;
            fps = 0;
            time = 0.0f;
        }
    }
    
    void end()
    {
        removeAllEntities();
        resources->clear();
    }
};

int main(int argc, char **argv)
{
    try
    {
        Sirius::GamePtr game = Sirius::Game::initialize(1024,600);
        Sirius::ScenePtr scene = Sirius::Scene::Create<GameScene>();
        Sirius::ScenePtr scene2 = Sirius::Scene::Create<GameScene2>();
        game->addScene("level1",scene);
        game->addScene("level2",scene2);
        game->run("level1");   
        game->removeAllScenes();
        Sirius::Game::terminate();
    }
    catch(std::runtime_error e)
    {
        Sirius::Utility::Log::Error(e.what());
    }
    
    return 0;
}

