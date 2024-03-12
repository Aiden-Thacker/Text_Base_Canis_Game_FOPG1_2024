#include "Dice.hpp"

//Roll _num dice with _sides sides and get back a vector of the dice results
std::vector<int> Roll(int _num, int _sides)
{
    std::vector<int> rolls;
    for(int i = 0; i<_num; i++)
    {
        rolls.push_back((rand()%_sides)+1);
    }

    return rolls;

}

//Roll _num dice with _sides sides and get back the total of all the rolls
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

//Roll an index in a list
int RollIndex(int _len)
{
    int rolls = (rand()%_len);
    //printf("%i\n", rolls);
    return rolls;
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