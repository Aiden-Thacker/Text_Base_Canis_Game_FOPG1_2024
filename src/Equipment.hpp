#pragma once

#include <string>
#include <vector>
#include "fogpi/Math.hpp"
#include "Dice.hpp"

class Equipment
{
private:
public:
    void RollRarity();
    void SetName(std::string);
    int level = 3;
    int rarity;
    std::string name;
};

