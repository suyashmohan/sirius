/* 
 * File:   Utility.h
 * Author: Suyash Mohan
 *
 * Created on 3 May, 2014, 3:33 PM
 */

#ifndef UTILITY_H
#define	UTILITY_H

#include <string>

namespace Sirius
{
    namespace Utility
    {
        namespace Log
        {
            void Error(std::string msg);
            void Info(std::string msg);
            void Print(std::string msg);
        }
    }
}

#endif	/* UTILITY_H */

