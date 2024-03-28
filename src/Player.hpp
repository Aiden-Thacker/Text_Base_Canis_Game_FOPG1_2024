#pragma once

#include "Entity.hpp"
#include "Stats.hpp"
#include "Character.hpp"
#include "Enemy.hpp"
#include "Harpy.hpp"
#include "Cyclops.hpp"
#include "Combat.hpp"

class Player : public Character
{
public:
    void Start();
    void Update();
    
    void Pick_Up(Shield);
    void Pick_Up(Armor);
    void Pick_Up(Weapon);
    int experience;
private:
    int m_keyCount = 0;
    Enemy *m_enemy = nullptr;
};