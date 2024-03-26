#include "Character.hpp"

void Character::RollEquipment()
    {
        this->armor.RollRarity();
        this->shield.RollRarity();
        this->weapon.RollRarity();
        this->armor.RollStats();
        this->shield.RollStats();
        this->weapon.RollStats();
    }

void Character::RollEquipmentStats()
    {
        this->armor.RollStats();
        this->shield.RollStats();
        this->weapon.RollStats();
    }

void Character::SetEquipmentLevel()
    {
        this->armor.SetLevel(stats.level);
        this->shield.SetLevel(stats.level);
        this->weapon.SetLevel(stats.level);
    }

void Character::PrintEquipment()
    {
        this->armor.PrintArmor();
        printf("\n");
        this->weapon.PrintWeapon();
        printf("\n");
        this->shield.PrintShield();
        printf("\n");
    }