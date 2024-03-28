#include "Armor.hpp"

void Armor::RollStats()
{
    std::vector<std::string> names {"Leather Tunic", "Plate Armor", "Chainmail Shirt", "Wooden Chestplate"};
    if(name == "");
    {
        name = names[RollIndex(4)];
    }
    this->weight = RollSum(1,3);
    this->defense = ((RollSum(1,this->rarity+1))*(RollIndex(1+((int)(level/2)))))+5;
    if(defense<0)
    {
        defense = 0;
    }
    this->defense*=weight;

}



void Armor::SetLevel(int new_level)
{
    this->level=new_level;
    RollStats();
}

void Armor::PrintArmor()
{
    std::vector<std::string> rarities {"Common", "Uncommon", "Rare", "Legendary"};
    std::vector<std::string> weights {"Light", "Medium", "Heavy"};
    printf("Name: %s        Level: %i\nType: %s Armor\nRarity: %s\nDefense: %i\n", name.c_str(), level, weights[weight-1].c_str(), rarities[rarity].c_str(), defense);
}