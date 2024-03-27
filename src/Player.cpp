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

void Player::Gold(int _goldCount)
{
    m_goldCount += _goldCount;
}

void Player::Level_Up()
{
    printf("LEVEL UP!!!\n");
    this->stats.level++;
    this->stats.constitution += RollIndex(4);
    int healthBonus = RollIndex(4) + (int)(this->stats.constitution/5);
    this->stats.maxHealth += healthBonus;
    this->health += healthBonus;
    this->stats.defense += RollIndex(4);
    this->stats.dexterity += RollIndex(4);
    this->stats.strength += RollIndex(4);
    if(RollIndex(5)==4)
    {
        this->stats.expertise+=1;
    }
    Printstats(stats);
}

void Player::Update()
{
    if (m_enemy == nullptr)
                    m_enemy = new Enemy();
                
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
            StartCombat(this, m_enemy);
        }  
        if (directionInput == 'L')
        {
            Level_Up();
        }  
        if (directionInput == 'P')
        {
            weapon.PrintWeapon();
        }
        if (directionInput == 'U')
        {
            printf("Upgrade Weapon!!!\n");
            weapon.SetLevel(stats.level);
            weapon.PrintWeapon();
        } 
        if (directionInput == 'R')
        {
            printf("Reroll Weapon!!\n");
            weapon.RollRarity();
            weapon.RollStats();
            weapon.PrintWeapon();
        } 
        if (directionInput == 'r')
        {
            printf("Reroll Weapon Stats!!\n");
            weapon.RollStats();
            weapon.PrintWeapon();
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

    // check for gold
    if (room->GetLocation(m_position + direction) == 'G')
    {
        m_goldCount++;
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