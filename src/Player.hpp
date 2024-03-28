#pragma once

#include "Entity.hpp"
#include "Stats.hpp"
#include "Character.hpp"
#include "Enemy.hpp"
#include "Harpy.hpp"
#include "Cyclops.hpp"

class Player : public Character
{
public:
    void Start();
    void Update();
    
    void Pick_Up(Shield);
    void Pick_Up(Armor);
    void Pick_Up(Weapon);
    int experience;
    void Gold(int _goldCount);
    int m_goldCount = 0;
private:
    int m_keyCount = 0;
    Enemy *m_enemy = nullptr;
};