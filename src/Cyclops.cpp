#include "Cyclops.hpp"

void CyclopsRollEquipmentStats(Character *_instance)
    {
        printf("Cyclops Override\n");
        _instance->armor.RollStats();
        _instance->shield.RollStats();
        _instance->weapon.RollStats();
        _instance->shield.block += 2;
        _instance->shield.defense += 10;
        _instance->armor.defense *=2;

        //Weapon
        //No D4s or D6s allowed
        for(int i=0; i<_instance->weapon.damage_dice_sides.size();i++)
        {
            if(_instance->weapon.damage_dice_sides[i] == 4 || _instance->weapon.damage_dice_sides[i] == 6) 
            {
                _instance->weapon.damage_dice_sides[i] = 8;
            }
        }

        _instance->weapon.hit_dice_sides[0] = 6;
        _instance->weapon.miss_chance = 2;
    }


void CyclopsRollEquipment(Character *_instance)
    {
        printf("Cyclops Override\n");
        _instance->armor.RollRarity();
        _instance->shield.RollRarity();
        _instance->weapon.RollRarity();
        _instance->armor.RollStats();
        _instance->shield.RollStats();
        _instance->weapon.RollStats();
        _instance->shield.block += 2;
        _instance->shield.defense += 10;
        _instance->armor.defense *=2;

        //Weapon
        //No D4s or D6s allowed
        for(int i=0; i<_instance->weapon.damage_dice_sides.size();i++)
        {
            if(_instance->weapon.damage_dice_sides[i] == 4 || _instance->weapon.damage_dice_sides[i] == 6) 
            {
                _instance->weapon.damage_dice_sides[i] = 8;
            }
        }

        _instance->weapon.hit_dice_sides[0] = 6;
        _instance->weapon.miss_chance = 2;
    }

Cyclops::Cyclops(/*int level*/)
{
    name = "Cyclops";
    RollEquipmentStatsOverride = &CyclopsRollEquipmentStats;
    RollEquipmentOverride = &CyclopsRollEquipment;

    loot_chance = {4/*Weapon*/,2/*Armor*/,3/*Shield*/};
    loot_chance_dice = {10/*Weapon*/,10/*Armor*/,10/*Shield*/};

    //Stats
    stats.dexterity = 8;
    stats.strength = 25;
    stats.defense = 20;
    stats.constitution = 20;
    //bad accuracy
    stats.expertise = -1;
    stats.maxHealth = 25;
    health = stats.maxHealth;

    //Level
    //Level_Up(level-stats.level);

    //Can't Light Attack Very likely to Heavy
    actions = {'h','h','a','b'};

    //equipment
    RollEquipment();
    //names
    armor.name = "Cyclops Armor";
    weapon.name = "Heavy Club";
    shield.name = "Sturdy Wooden Shield";
    //Decent Shield & Armor
    shield.block += 2;
    shield.defense += 10;
    armor.defense *=2;

    //Weapon
    //No D4s or D6s allowed
    for(int i=0; i<weapon.damage_dice_sides.size();i++)
    {
        if(weapon.damage_dice_sides[i] == 4 || weapon.damage_dice_sides[i] == 6) 
        {
            weapon.damage_dice_sides[i] = 8;
        }
    }

    weapon.hit_dice_sides[0] = 6;
    weapon.miss_chance = 2;
}
