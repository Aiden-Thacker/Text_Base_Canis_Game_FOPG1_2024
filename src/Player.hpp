#pragma once

#include "Entity.hpp"
#include "Character.hpp"

class Player : public Character
{
public:
    void Start();
    void Update();
private:
    int m_keyCount = 0;
};