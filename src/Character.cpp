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

    void Character::Level_Up()
    {
        printf("LEVEL UP!!!\n");
        this->stats.level++;
        this->stats.constitution += RollIndex(4);
        int healthBonus = RollIndex(4) + (int)(this->stats.constitution/5);
        this->stats.maxHealth += healthBonus;
        this->health += healthBonus;
        this->stats.defense += RollIndex(4);
        this->stats.dexterity += RollIndex(4);
        this->stats.strength += RollIndex(4);
        if(RollIndex(5)==4)
        {
            this->stats.expertise+=1;
        }
        Printstats(stats);
    }

    void Character::Level_Up(int times)
    {
        for(int i = 0; i<times; i++)
        {
            Level_Up();
        }
    }