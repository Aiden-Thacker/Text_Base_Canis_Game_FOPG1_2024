#include "Dice.hpp"

std::vector<int> Roll(int _num, int _sides)
{
    std::vector<int> rolls;
    for(int i = 0; i<_num; i++)
    {
        rolls.push_back((rand()%_sides)+1);
    }

    return rolls;

}

int RollSum(int _num, int _sides)
{
    std::vector rolls = Roll(_num,_sides);
    int total = 0;

    for(int num: rolls)
    {
        total += num;
    }
    
    Print(rolls);

    return total;
}

void Print(std::vector<int> rolls)
{
    printf("[");
    for(int i = 0; i<rolls.size(); i++)
    {
        printf("%i", rolls[i]);
        if(i==rolls.size()-1)
        {
            printf("]");
        }
        else
        {
            printf(", ");
        }
    }
    printf("\n");
}