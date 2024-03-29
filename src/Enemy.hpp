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
        std::vector<int> loot_chance{3/*Weapon*/,3/*Armor*/,3/*Shield*/};
        std::vector<int> loot_chance_dice{10/*Weapon*/,10/*Armor*/,10/*Shield*/};
        std::string name = "Monster";

};