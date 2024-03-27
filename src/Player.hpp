#pragma once

#include "Entity.hpp"
#include "Stats.hpp"
#include "Character.hpp"
#include "Enemy.hpp"

class Player : public Character
{
public:
    void Start();
    void Update();
    void Level_Up();
    void Gold(int _goldCount);
private:
    int m_keyCount = 0;
    int m_goldCount = 0;
    Enemy *m_enemy = nullptr;
};