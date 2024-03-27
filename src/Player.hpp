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
    int experience;
private:
    int m_keyCount = 0;
    Enemy *m_enemy = nullptr;
};