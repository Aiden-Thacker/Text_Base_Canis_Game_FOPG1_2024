#include "Equipment.hpp"

    void Equipment::SetName(std::string new_name)
    {
        this->name = new_name;
    }

    void Equipment::RollRarity()
    {
        this->rarity=RollIndex(4);
    }