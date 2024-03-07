#include "Dice.hpp"

std::vector<int> Roll(int _num, int _sides)
{
    srand(time(NULL));
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

    return total;
}