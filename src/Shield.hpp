#pragma once

#include "Equipment.hpp"

class Shield: public Equipment
{
private:
    
public:
    void RollStats();
    
    void SetLevel(int);

    void PrintShield();
    int defense = 0;
    int block = 1;
};