#pragma once

#include "Equipment.hpp"

class Armor: public Equipment
{
private:

public:
    void RollStats();
    
    void SetLevel(int);

    void PrintArmor();
    int weight = 1;
    int defense = 5;
};


