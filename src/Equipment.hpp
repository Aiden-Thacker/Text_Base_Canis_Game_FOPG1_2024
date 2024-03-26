#pragma once

#include <string>
#include <vector>
#include "fogpi/Math.hpp"
#include "dice.hpp"

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

