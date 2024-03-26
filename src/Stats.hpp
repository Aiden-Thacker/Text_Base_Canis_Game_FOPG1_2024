#pragma once

struct Stats
{
    int level = 1;
    int expertise = 0;
    int maxHealth = 10;
    int strength = 10;
    int dexterity = 10;
    int constitution = 10;
    int defense = 10;
    int block = 0;

};

extern void Printstats(const Stats&  _stats);
