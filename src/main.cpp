#ifdef _WIN32
#include <windows.h>
#endif

#include "fogpi/fogpi.hpp"
#include "fogpi/Math.hpp"

#include "Room.hpp"
#include "Entity.hpp"
#include "Dice.hpp"
#include "Combat.hpp"

#include <string>

int main(int argc, char* argv[])
{
    srand(time(NULL));
    Room room;
    room.Load("assets/maps/level_1_" + std::to_string(1 + rand() % 3) + ".map");

    while(room.StillPlaying() == true)
    {
        room.Update();
    }

    return 0;
}