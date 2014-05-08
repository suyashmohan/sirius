/* 
 * File:   ResourceManager.h
 * Author: Suyash Mohan
 *
 * Created on 7 May, 2014, 7:27 PM
 */

#ifndef RESOURCEMANAGER_H
#define	RESOURCEMANAGER_H

#include "Texture.h"
#include "Typedefs.h"
#include <string>
#include <map>

namespace Sirius
{   
    class ResourceManager {
    public:
        ResourceManager();
        virtual ~ResourceManager();
        TexturePtr addTexture(std::string name, std::string path);
        TexturePtr getTexture(std::string name);
        TexturePtr removeTexture(std::string name);
        unsigned int clear();
    private:
        std::map<std::string,TexturePtr> m_textures;
    };
}

#endif	/* RESOURCEMANAGER_H */

