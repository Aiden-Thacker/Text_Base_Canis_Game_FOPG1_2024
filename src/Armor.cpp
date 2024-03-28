#include "Armor.hpp"

void Armor::RollStats()
{
    this->defense = ((RollSum(1,this->rarity+1))*(RollIndex(1+((int)(level/2)))))+5;
    if(defense<0)
    {
        defense = 0;
    }

}



void Armor::SetLevel(int new_level)
{
    this->level=new_level;
    RollStats();
}

void Armor::PrintArmor()
{
    std::vector<std::string> rarities {"Common", "Uncommon", "Rare", "Legendary"};
    printf("Name: %s        Level: %i\nType: Armor\nRarity: %s\nDefense: %i\n", name.c_str(), level, rarities[rarity].c_str(), defense);
}