#include <vector>

class Treasure {
public:
    static bool hasTreasureChest(); // Function to determine if the room has a treasure chest
    static bool hasKey(); // Function to determine if the room has a key
    static void printRoomContents(bool treasure, bool key); // Function to print the contents of the room
    static void PlaceTreasure(std::vector<std::vector<char>>& map, bool& treasurePlaced); // Function to place treasure in the room
};
