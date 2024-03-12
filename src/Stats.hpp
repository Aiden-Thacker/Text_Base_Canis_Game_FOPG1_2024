#pragma once

struct Stats
{
    float maxHealth = 10.0f;
    float strength = 10.0f;
    float dexterity = 10.0f;
    float constitution = 10.0f;
};

extern void playerStats(const Stats&  _stats);
