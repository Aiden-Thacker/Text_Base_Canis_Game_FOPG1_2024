#include "Stats.hpp"


#include <fstream>
#include <stdio.h>


using namespace std;


void Printstats(const Stats&  _stats)
{
    printf("Player Level: {%i}  \n", _stats.level);
    printf("Current Player Heath: {%i}  \n", _stats.maxHealth);
    printf("Player Expertise: {%i}  \n", _stats.expertise);
    printf("Player Strength: {%i}  \n", _stats.strength);
    printf("Player Dexterity: {%i}  \n", _stats.dexterity);
    printf("Player Constitution:  {%i}  \n", _stats.constitution);    
} 

