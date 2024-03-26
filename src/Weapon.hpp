#pragma once

#include <vector>

#include "Equipment.hpp"
#include "Dice.hpp"

class Weapon: public Equipment
{
private:
    
public:
    void RollStats();
    void RollRarity();
    void SetLevel(int);

    void PrintWeapon();

    std::vector<int> damage_dice {1};
    std::vector<int> damage_dice_sides {6};
    
    std::vector<int> hit_dice {1};
    std::vector<int> hit_dice_sides {4};
    int miss_chance = 1;
    int damage_bonus = 1;
};