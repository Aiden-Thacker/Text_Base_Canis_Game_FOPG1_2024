#pragma once

#include "Equipment.hpp"

class Armor: public Equipment
{
private:

public:
    void RollStats();
    
    void SetLevel(int);

    void PrintArmor();
    int defense = 5;
};


