/* 
 * File:   Input.h
 * Author: Suyash Mohan 
 *
 * Created on 3 May, 2014, 3:16 PM
 */

#ifndef INPUT_H
#define	INPUT_H

#include <memory>

namespace Sirius
{
    class Input {
    public:
        Input();
        virtual ~Input();
    private:

    };
    
    typedef std::shared_ptr<Input> InputPtr;
}

#endif	/* INPUT_H */

