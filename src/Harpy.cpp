#include "Harpy.hpp"

Harpy::Harpy(/*int level*/)
{
    name = "Harpy";

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


