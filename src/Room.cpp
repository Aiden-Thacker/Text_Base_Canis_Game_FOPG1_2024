#include "Room.hpp"

#include "Player.hpp"

#include <fstream>
#include <string>

void Room::Load(std::string _path)
{
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
        }
    }
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
