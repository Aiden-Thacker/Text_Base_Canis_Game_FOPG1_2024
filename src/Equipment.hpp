#pragma once

#include <string>
#include "fogpi/Math.hpp"

class Equipment
{
private:
public:
    void SetName(std::string);
    int level = 3;
    int rarity;
    std::string name;
};

