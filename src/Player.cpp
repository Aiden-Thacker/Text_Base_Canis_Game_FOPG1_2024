#include "Player.hpp"
#include "fogpi/fogpi.hpp"
#include "fogpi/Math.hpp"
#include "Room.hpp"
#include "Combat.hpp"
#include <string>

void Player::Start()
{
    m_character = 'P';
}



void Player::Update()
{
    if (m_enemy == nullptr)
                    m_enemy = new Harpy(/*stats.level*/);
                
                m_enemy->Init(4, 4);
                m_enemy->Start();
    // direction
    std::string instruction = "wasd and Enter to move";
    char directionInput = 'r';
    Vector2D direction(0.0f, 0.0f);

    while(directionInput != 'w' &&
          directionInput != 'a' &&
          directionInput != 's' &&
          directionInput != 'd')
    {
        directionInput = request_char(instruction.c_str());
         // Kill player
        if (directionInput == 'K')
        {
            room->KillPlayer();
            return;
        }    
        if (directionInput == 'C')
        {
            if(stats.level>m_enemy->stats.level)
            {
                m_enemy->Level_Up(stats.level-m_enemy->stats.level);
            }
            m_enemy->SetEquipmentLevel();
            m_enemy->RollEquipment();
            StartCombat(this, m_enemy);
        }  
        if (directionInput == 'L')
        {
            Level_Up();
        }  
        if (directionInput == 'P')
        {
            PrintEquipment();
        }
        if (directionInput == 'U')
        {
            printf("Upgrade Equipment!!!\n");
            SetEquipmentLevel();
            PrintEquipment();
        } 
        if (directionInput == 'R')
        {
            printf("Reroll Equipment!!\n");
            RollEquipment();
            PrintEquipment();
        } 
        if (directionInput == 'r')
        {
            printf("Reroll Equipment Stats!!\n");
            RollEquipmentStats();
            PrintEquipment();
        } 
    }

    if (directionInput == 'w')
        direction = Vector2D(0.0f, -1.0f);
    if (directionInput == 'a')
        direction = Vector2D(-1.0f, 0.0f);
    if (directionInput == 's')
        direction = Vector2D(0.0f, 1.0f);
    if (directionInput == 'd')
        direction = Vector2D(1.0f, 0.0f);
    
    // check for key
    if (room->GetLocation(m_position + direction) == 'K')
    {
        m_keyCount++;
        room->ClearLocation(m_position + direction);
    }

    // check for lock
    if (room->GetLocation(m_position + direction) == 'L')
    {
        if (m_keyCount <= 0)
            return;
        
        m_keyCount--;
        room->OpenDoor(m_position + direction);
    }

    // check for door
    if (room->GetLocation(m_position + direction) == 'D')
    {
        room->OpenDoor(m_position + direction);
    }

    // try to move
    if (room->GetLocation(m_position + direction) == ' ')
      {
        m_position += direction;
        //Printstats(stats);
      }  
}

void Player::Pick_Up(Shield new_shield)
{
    char choice = ' ';
    std::string prompt = "Keep your Current Shield (k)\nSwap to New Shield (s)\n";
    printf("You Found A Shield!!!\nCurrent Shield:\n");
    shield.PrintShield();
    printf("\nNew Shield:\n");
    new_shield.PrintShield();

    while(choice != 'k' && choice != 's')
    {
        choice = request_char(prompt.c_str());
    }

    if(choice == 'k')
    {
        printf("Gotta Stick With Ol Reliable.\n");
    }
    else if(choice == 's')
    {
        printf("New Shield Aquired!!!\n");
        shield = new_shield;
    }
}
void Player::Pick_Up(Armor new_armor)
{
    char choice = ' ';
    std::string prompt = "Keep your Current Armor (k)\nSwap to New Armor (s)\n";
    printf("You Found Some Armor!!!\nCurrent Armor:\n");
    armor.PrintArmor();
    printf("\nNew Armor:\n");
    new_armor.PrintArmor();

    while(choice != 'k' && choice != 's')
    {
        choice = request_char(prompt.c_str());
    }

    if(choice == 'k')
    {
        printf("Gotta Stick With Ol Reliable.\n");
    }
    else if(choice == 's')
    {
        printf("New Armor Aquired!!!\n");
        armor = new_armor;
    }
}
void Player::Pick_Up(Weapon new_weapon)
{
    char choice = ' ';
    std::string prompt = "Keep your Current Weapon (k)\nSwap to New Weapon (s)\n";
    printf("You Found A Weapon!!!\nCurrent Weapon:\n");
    weapon.PrintWeapon();
    printf("\nNew Weapon:\n");
    new_weapon.PrintWeapon();

    while(choice != 'k' && choice != 's')
    {
        choice = request_char(prompt.c_str());
    }

    if(choice == 'k')
    {
        printf("Gotta Stick With Ol Reliable.\n");
    }
    else if(choice == 's')
    {
        printf("New Weapon Aquired!!!\n");
        weapon = new_weapon;
    }
}