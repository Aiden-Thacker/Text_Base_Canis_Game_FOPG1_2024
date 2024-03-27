#include "Shield.hpp"

void Shield::RollStats()
{
    this->block = ((RollSum(1,this->rarity+1))+(RollIndex(1+(int)(level/5))-1));
    if(block<1)
    {
        block=1;
    }

    this->defense = ((RollSum(1,this->rarity+1))*(RollIndex(1+((int)(level/5)))-1));
    if(defense<0)
    {
        defense = 0;
    }

}



void Shield::SetLevel(int new_level)
{
    this->level=new_level;
    RollStats();
}

void Shield::PrintShield()
{
    std::vector<std::string> rarities {"Common", "Uncommon", "Rare", "Legendary"};
    printf("Name: %s        Level: %i\nType: Shield\nRarity: %s\nDefense: %i\nBlock: %i\n", name.c_str(), level, rarities[rarity].c_str(), defense, block);
}