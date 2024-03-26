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
        std::string name = "Monster";

};