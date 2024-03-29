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

void Treasure::PlaceTreasure(std::vector<std::vector<char>> *map, bool treasurePlaced) 
{
    // Determine if the room has a treasure chest
    bool treasure = hasTreasureChest();
    // If the room has a treasure chest, place it in the room
    if (treasure) {
        // Roll for the location of the treasure chest
        int numRows = (*map).size();
        printf("numRows = %i\n", numRows);
        int numCols = (numRows > 0) ? (*map)[0].size() : 0;
        printf("numCols = %i\n", numCols);
        // Continue searching for an empty space until we find one
        while (treasurePlaced==true) {
            int row = RollIndex(numRows); // Generate a random row index
            printf("row = %i\n", row);
            int col = RollIndex(numCols); // Generate a random column index
            printf("col = %i\n", col);
            if ((*map)[row][col] == ' ') { // Check if the room is empty
                (*map)[row][col] = 'T'; // Place the treasure in the room
                printf("Treasue made at [%i, %i]\n", row, col);
                treasurePlaced=false; // Exit the loop
            }
            else
            {
                printf("Not Empty");
            }
        }
    }
}

void Treasure::OpenTreasure(Player* player) {
    if (player == nullptr)
        player = new Player();

    int result = RollIndex(4);

    if (result == 0) 
    {
        // Generate a random amount of gold within a range, for example, between 1 and 10
        int randomGold = RollSum(1, 10);
        player->Gold(randomGold);
        printf("You received [%i] gold.\n", randomGold);
    } 
    else if (result == 1) 
    {
        Shield newShield = (*(new Shield()));
        newShield.SetLevel(player->stats.level);
        newShield.RollRarity();
        newShield.RollStats();
        player->Pick_Up(newShield);
    } 
    else if (result == 2) 
    {
        Armor newArmor = (*(new Armor()));
        newArmor.SetLevel(player->stats.level);
        newArmor.RollRarity();
        newArmor.RollStats(); 
        player->Pick_Up(newArmor);
    } 
    else if (result == 3) 
    {
        Weapon newWeapon = (*(new Weapon()));
        newWeapon.SetLevel(player->stats.level);
        newWeapon.RollRarity();
        newWeapon.RollStats();
        player->Pick_Up(newWeapon);
    }
}