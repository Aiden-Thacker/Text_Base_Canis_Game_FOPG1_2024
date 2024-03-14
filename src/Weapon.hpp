#pragma once

#include <vector>

#include "Equipment.hpp"
#include "Dice.hpp"

class Weapon: public Equipment
{
private:
    
public:
    std::vector<int> damage_dice;
    std::vector<int> damage_dice_sides;
    
    std::vector<int> hit_dice;
    std::vector<int> hit_dice_sides;
    int hit_chance;
    int damage_bonus;
    Weapon(/* args */);
    ~Weapon();
};