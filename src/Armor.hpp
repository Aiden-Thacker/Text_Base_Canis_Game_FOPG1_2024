#pragma once

#include "Equipment.hpp"

class Armor: public Equipment
{
private:

public:
    int defense;
    Armor(/* args */);
    ~Armor();
};

Armor::Armor(/* args */)
{
}

Armor::~Armor()
{
}
