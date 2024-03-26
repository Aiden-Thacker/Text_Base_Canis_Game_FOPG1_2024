#include "Potion.hpp"

void Potion::SetName()
{
    this->name = potionType[rarity] + " Health Potion";
}

void Potion::UsePotion(Player *player)
{
    player->health += RollSum(rarity + 1, 4) + rarity + 1;
    if(player->health > player->stats.maxHealth)
    {
        player->health = player->stats.maxHealth;
    }
}