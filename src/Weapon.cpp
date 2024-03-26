#include "Weapon.hpp"

void Weapon::RollStats()
{
    damage_dice.clear();
    damage_dice_sides.clear();
    std::vector<int> possible_dice {4,6,8,10,12};
    int diceTypeCount = RollSum(1,rarity+1)-1;
    if(diceTypeCount<1)
    {
        diceTypeCount = 1;
    }
    int diceCount = RollSum(1,rarity+1);
    for(int i = 0; i<diceTypeCount;i++)
    {
        int roll = RollSum(1,diceCount);
        this->damage_dice.push_back(roll);
        this->damage_dice_sides.push_back(possible_dice[RollIndex(rarity+2)]);
        diceCount-=roll;
        if (diceCount<1)
        {
            i=diceTypeCount;
        }
    }

    this->damage_bonus = (int)((RollSum(1,this->rarity+1)-1)*(level/3));

}



void Weapon::SetLevel(int new_level)
{
    this->level=new_level;
    RollStats();
}

void Weapon::PrintWeapon()
{
    std::vector<std::string> rarities {"Common", "Uncommon", "Rare", "Legendary"};
    printf("Name: %s        Level: %i\nType: Weapon\nRarity: %s\nDamage: ", name.c_str(), level, rarities[rarity].c_str());
    for(int i = 0; i<damage_dice.size();i++)
    {
        printf("%iD%i + ", damage_dice[i],damage_dice_sides[i]);
    }
    printf("%i\nRoll To Hit: ",damage_bonus);
    for(int i = 0; i<hit_dice.size();i++)
    {
        if(i<hit_dice.size()-1)
        {
            printf("%iD%i + ", hit_dice[i],hit_dice_sides[i]);
        }
        else
        {
            printf("%iD%i\n", hit_dice[i],hit_dice_sides[i]);
        }
    }
    printf("Miss Chance: %i\n", miss_chance);
}