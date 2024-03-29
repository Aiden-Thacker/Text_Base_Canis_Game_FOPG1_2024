#include "Harpy.hpp"

void HarpyRollEquipmentStats(Character *_instance)
    {
        printf("Harpy Override\n");
        _instance->armor.RollStats();
        _instance->shield.RollStats();
        _instance->weapon.RollStats();
        _instance->shield.block += 2;
        _instance->shield.defense += 10;
        _instance->armor.defense *=2;

        _instance->armor.name = "Tunic";
        _instance->weapon.name = "Talons";
        _instance->shield.name = "None";
        //no shield
        _instance->shield.block = 0;
        _instance->shield.defense = 0;

    //Weapon
    //only D4s allowed, but gets 1 more
    for(int i=0; i<_instance->weapon.damage_dice_sides.size();i++)
    {
        _instance->weapon.damage_dice_sides[i] = 4;
    }

    _instance->weapon.hit_dice_sides[0] = 6;

    _instance->weapon.damage_dice[0] += 1;
    }


void HarpyRollEquipment(Character *_instance)
    {
        printf("Harpy Override\n");
        _instance->armor.RollRarity();
        _instance->shield.RollRarity();
        _instance->weapon.RollRarity();
        _instance->armor.RollStats();
        _instance->shield.RollStats();
        _instance->weapon.RollStats();
        _instance->shield.block += 2;
        _instance->shield.defense += 10;
        _instance->armor.defense *=2;

        _instance->armor.name = "Tunic";
        _instance->weapon.name = "Talons";
        _instance->shield.name = "None";
        //no shield
        _instance->shield.block = 0;
        _instance->shield.defense = 0;

        //Weapon
        //only D4s allowed, but gets 1 more
        for(int i=0; i<_instance->weapon.damage_dice_sides.size();i++)
        {
            _instance->weapon.damage_dice_sides[i] = 4;
        }

        _instance->weapon.hit_dice_sides[0] = 6;

        _instance->weapon.damage_dice[0] += 1;
    }

Harpy::Harpy(/*int level*/)
{
    name = "Harpy";
    RollEquipmentStatsOverride = &HarpyRollEquipmentStats;
    RollEquipmentOverride = &HarpyRollEquipment;

    loot_chance = {2/*Weapon*/,3/*Armor*/,11/*Shield*/};
    loot_chance_dice = {10/*Weapon*/,10/*Armor*/,10/*Shield*/};

    //Stats
    stats.dexterity = 20;
    stats.strength = 14;
    stats.defense = 5;
    stats.constitution = 12;
    stats.expertise = 3;
    stats.maxHealth = 15;
    health = stats.maxHealth;

    //Level
    //Level_Up(level-stats.level);

    //Can't Block
    actions = {'l','h','a'};

    //equipment
    RollEquipment();
    //names
    armor.name = "Tunic";
    weapon.name = "Talons";
    shield.name = "None";
    //no shield
    shield.block = 0;
    shield.defense = 0;

    //Weapon
    //only D4s allowed, but gets 1 more
    for(int i=0; i<weapon.damage_dice_sides.size();i++)
    {
        weapon.damage_dice_sides[i] = 4;
    }

    weapon.hit_dice_sides[0] = 6;

    weapon.damage_dice[0] += 1;
}


