/* 
 * File:   typedefs.h
 * Author: Suyash Mohan
 *
 * Created on 4 May, 2014, 11:27 AM
 */

#ifndef TYPEDEFS_H
#define	TYPEDEFS_H

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
}

#endif	/* TYPEDEFS_H */

