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
    void RollEquipment();
    void RollEquipmentStats();
    void SetEquipmentLevel();
    void PrintEquipment();
    Stats stats;
    int health = stats.maxHealth;
    Shield shield;
    Weapon weapon;
    Armor armor;
};