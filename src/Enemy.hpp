#pragma once

#include <string>

#include "Entity.hpp"
#include "Stats.hpp"
#include "Character.hpp"

class Enemy : public Character
{
    public:
        void Start();
        std::vector<char> actions {'l','h','a','b'};
        std::vector<int> loot_chance{1/*Weapon*/,1/*Armor*/,1/*Shield*/};
        std::vector<int> loot_chance_dice{10/*Weapon*/,10/*Armor*/,10/*Shield*/};
        std::string name = "Monster";

};