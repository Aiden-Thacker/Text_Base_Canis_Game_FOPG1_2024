#pragma once

#include "Equipment.hpp"

class Shield: public Equipment
{
private:
    
public:
    int defense;
    int block;
    Shield(/* args */);
    ~Shield();
};