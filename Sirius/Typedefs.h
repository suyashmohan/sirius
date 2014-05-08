/* 
 * File:   typedefs.h
 * Author: Suyash Mohan
 *
 * Created on 4 May, 2014, 11:27 AM
 */

#ifndef TYPEDEFS_H
#define	TYPEDEFS_H

#include <memory>

namespace Sirius
{
    typedef struct 
    {
        int x;
        int y;
    }Point;
    
    typedef struct 
    {
        float x;
        float y;
    }PointF;
    
    typedef struct 
    {
        int x;
        int y;
        int w;
        int h;
    }Rect;
    
    class Game;
    class Window;
    class Renderer;
    class Scene;
    class Entity;
    class Graphic;
    class Texture;
    class Image;
    class Input;
    class ResourceManager;
    
    typedef std::shared_ptr<Game> GamePtr;
    typedef std::shared_ptr<Window> WindowPtr;
    typedef std::shared_ptr<Renderer> RendererPtr;
    typedef std::shared_ptr<Scene> ScenePtr;
    typedef std::shared_ptr<Entity> EntityPtr;
    typedef std::shared_ptr<Texture> TexturePtr;
    typedef std::shared_ptr<Graphic> GraphicPtr;
    typedef std::shared_ptr<Image> ImagePtr;
    typedef std::shared_ptr<Input> InputPtr;
    typedef std::shared_ptr<ResourceManager> ResourceManagerPtr;
    
    typedef enum
    {
        Nearest = 0,
        Linear = 1,
        Best = 2
    }ScaleFilter;
}

#endif	/* TYPEDEFS_H */

