#include "Room.hpp"

#include "Player.hpp"

#include "Treasure.hpp"

#include <fstream>
#include <string>

void Room::Load(std::string _path)
{
    std::vector<Enemy*> enemies;

    
    enemies.push_back((new Enemy()));
    enemies.push_back((new Enemy()));
    enemies.push_back((new Enemy()));
    enemies.push_back((new Enemy()));
    enemies.push_back((new Enemy()));
    enemies.push_back((new Harpy()));
    enemies.push_back((new Harpy()));
    enemies.push_back((new Cyclops()));
    for(int i = 0; i<enemies.size();i++)
    {
        (enemies[i])->Init(0, 0);
        (enemies[i])->Start();
    }
    bool enemyexist = false;
    m_map.clear();
    m_doors.clear();

    std::ifstream file;
    file.open(_path);

    if (!file.is_open())
    {
        printf("file not found at: %s \n", _path.c_str());
        exit(1);
    }

    std::string word;
    int number;

    while (file >> word)
    {
        if (word == "level")
        {
            if (file >> number)
            {
                printf("open level: %i\n", number);
            }
        }

        if (word == "next_level")
        {
            if (file >> word)
            {
                m_doors.push_back(Door());
                m_doors[m_doors.size() - 1].path = word;
            }
        }

        if (word == "map")
        {
            m_map.push_back(std::vector<char>());
            while(file >> word)
            {
                if (word == "-2")
                {
                    break;
                }

                if (word == "-1")
                {
                    m_map.push_back(std::vector<char>());
                    continue;
                }

                if (word == "0")
                    m_map[m_map.size() - 1].push_back(' ');
                else
                    m_map[m_map.size() - 1].push_back(word[0]);
                
            }
        }
    }

    int doorCount = 0;

    for (int y = 0; y < m_map.size(); y++)
    {
        for (int x = 0; x < m_map[y].size(); x++)
        {
            if (m_map[y][x] == 'S')
            {
                if (m_player == nullptr)
                    m_player = new Player();
                
                m_player->Init(x, y);
                m_player->Start();
                m_map[y][x] = ' ';
            }

            if (m_map[y][x] == 'D' || m_map[y][x] == 'L')
            {
                if (m_doors.size() - 1 >= doorCount)
                {
                    m_doors[doorCount].pos.x = x;
                    m_doors[doorCount].pos.y = y;
                    doorCount++;
                }
            }
            printf("Enemy Next\n");
            if(m_map[y][x] == 'E')
            {
                printf("E found\n");
                if (true)//m_enemy == nullptr)
                    {
                        //printf("Was NullPtr");
                        m_enemy = enemies[RollIndex(enemies.size())];
                        m_enemy->Init(x, y);
                    }
                printf("Enemy init complete\n");;
                
                enemyexist = true;
                printf("\n\n\nEnemy Exist\n\n\n");
            }
            printf("x = %i, y = %i",x,y);
        }
    }
    bool treasurePlaced = true;
    Treasure::PlaceTreasure(&m_map, treasurePlaced);

    if(enemyexist)
    {
        if(m_player->stats.level > m_enemy->stats.level)
                {
                    printf("Lower Level");
                    m_enemy->Level_Up(m_player->stats.level-m_enemy->stats.level);
                }
                printf("Setlevel next");
                m_enemy->SetEquipmentLevel();
                m_enemy->RollEquipment();
                printf("Enemy statted\n");
    }
    printf("Load Done\n");
}

void Room::Update()
{
    Draw();
    if (m_player != nullptr)
    {
        m_player->room = this;
        m_player->Update();
    }
}

void Room::Draw()
{
    for (int y = 0; y < m_map.size(); y++)
    {
        for (int x = 0; x < m_map[y].size(); x++)
        {
            printf("%c ", GetLocation(Vector2D(x, y)));
        }
        printf("\n");
    }
}

void Room::KillPlayer()
{
    MaybePlaying = false;
}

char Room::GetLocation(Vector2D _pos)
{
    if (_pos.y >= m_map.size())
        return ' ';
    
    if (_pos.x >= m_map[_pos.y].size())
        return ' ';

    if (m_player != nullptr)
        if (m_player->GetPosition() == _pos)
            return m_player->Draw();
    
    return m_map[_pos.y][_pos.x];
}

void Room::ClearLocation(Vector2D _pos)
{
    if (_pos.y >= m_map.size())
        return;
    
    if (_pos.x >= m_map[_pos.y].size())
        return;
    
    m_map[_pos.y][_pos.x] = ' ';
}

void Room::OpenDoor(Vector2D _pos)
{
    for(int i = 0; i < m_doors.size(); i++)
    {
        if (m_doors[i].pos == _pos)
        {
            Load(m_doors[i].path);
        }
    }

    m_player->health += RollSum(RollIndex(m_player->stats.level), 4);
    if(m_player->health > m_player->stats.maxHealth)
    {
        m_player->health = m_player->stats.maxHealth;
    }
}
