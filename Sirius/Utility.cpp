/* 
 * File:   Utility.cpp
 * Author: Suyash Mohan
 * 
 * Created on 3 May, 2014, 3:33 PM
 */

#include "Utility.h"
#include <iostream>

namespace Sirius
{
    namespace Utility
    {
        namespace Log
        {
            void Error(std::string msg)
            {
                std::cout << "Error : " << msg << std::endl;
            }
            
            void Info(std::string msg)
            {
                std::cout << "Info  : " << msg << std::endl;
            }
            
            void Print(std::string msg)
            {
                std::cout << "Log   : " << msg << std::endl;
            }
        }
    }
}

