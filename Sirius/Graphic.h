/* 
 * File:   Graphic.h
 * Author: Suyash Mohan
 *
 * Created on 3 May, 2014, 3:15 PM
 */

#ifndef GRAPHIC_H
#define	GRAPHIC_H

#include <memory>

namespace Sirius
{
    class Graphic {
    public:
        Graphic();
        virtual ~Graphic();
        virtual void render(int x, int y, float scaleX, float scaleY, float angle);
    private:

    };
    
    typedef std::shared_ptr<Graphic> GraphicPtr;
}

#endif	/* GRAPHIC_H */

