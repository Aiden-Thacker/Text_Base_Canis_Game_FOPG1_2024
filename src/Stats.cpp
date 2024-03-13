#include "Stats.hpp"


#include <fstream>
#include <stdio.h>


using namespace std;


void Printstats(const Stats&  _stats)
{
    printf("Current Player Heath: {%f}  \n", _stats.maxHealth);
    printf("Player Strength: {%f}  \n", _stats.strength);
    printf("Player Dexterity: {%f}  \n", _stats.dexterity);
    printf("Player Constitution:  {%f}  \n", _stats.constitution);    
} 

