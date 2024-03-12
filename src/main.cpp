#ifdef _WIN32
#include <windows.h>
#endif

#include "fogpi/fogpi.hpp"
#include "fogpi/Math.hpp"

#include "Room.hpp"
#include "Entity.hpp"
#include "Dice.hpp"

int main(int argc, char* argv[])
{
    srand(time(NULL));
    Room room;
    room.Load("assets/maps/level_1_3.map");

    while(true)
    {
        room.Update();
    }

    return 0;
}