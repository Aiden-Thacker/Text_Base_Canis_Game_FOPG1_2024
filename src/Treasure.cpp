#include "Treasure.hpp"
#include "Dice.hpp"

bool Treasure::hasTreasureChest() {
    // Roll a six-sided die
    int result = RollSum(1, 6);
    // If the result is 1 or 2, return true (representing the presence of a treasure chest)
    return (result == 1 || result == 2);
}

bool Treasure::hasKey() {
    // Roll a six-sided die
    int result = RollSum(1, 6);
    // If the result is 1 or 2, return true (representing the presence of a key)
    return (result == 1 || result == 2);
}

void Treasure::printRoomContents(bool treasure, bool key) {
    if (treasure && key) {
        printf("Treasure chest and key are present!\n");
    } else if (treasure) {
        printf("Treasure chest is present!\n");
    } else if (key) {
        printf("Key is present!\n");
    } else {
        printf("No treasure chest or key in the room.\n");
    }
}

void Treasure::PlaceTreasure(std::vector<std::vector<char>>& map, bool& treasurePlaced) {
    // Determine if the room has a treasure chest
    bool treasure = hasTreasureChest();
    // If the room has a treasure chest, place it in the room
    if (treasure) {
        // Roll for the location of the treasure chest
        int numRows = map.size();
        int numCols = (numRows > 0) ? map[0].size() : 0;
        // Continue searching for an empty space until we find one
        while (true) {
            int row = RollSum(1, numRows) - 1; // Generate a random row index
            int col = RollSum(1, numCols) - 1; // Generate a random column index
            if (map[row][col] == '0') { // Check if the room is empty
                map[row][col] = 'T'; // Place the treasure in the room
                break; // Exit the loop
            }
        }
    }
}
