#include "Equipment.hpp"
#include "Player.hpp"

class Potion: public Equipment
{
    public:
    std::vector<std::string> potionType {"Minor", "", "Major", "Supreme"};

    void SetName();

    void UsePotion(Player *player);
};