#pragma once

#include "Entity.hpp"
#include "Stats.hpp"
#include "Dice.hpp"
#include "Shield.hpp"
#include "Weapon.hpp"
#include "Armor.hpp"

class Character : public Entity
{
    public:
    Stats stats;
    int health = stats.maxHealth;
    Shield shield;
    Weapon weapon;
    Armor armor;
};