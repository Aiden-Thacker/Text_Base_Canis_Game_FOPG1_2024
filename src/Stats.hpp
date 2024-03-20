#pragma once

struct Stats
{
    int   level = 1;
    int   expertise = 0;
    float maxHealth = 10.0f;
    float strength = 10.0f;
    float dexterity = 10.0f;
    float constitution = 10.0f;
    float defense = 10.0f;

};

extern void Printstats(const Stats&  _stats);
