#pragma once
#include "fogpi/Math.hpp"

#include <string>
#include <vector>

#include "Entity.hpp"
#include "Player.hpp"
#include "Enemy.hpp"
#include "Door.hpp"

class Room {
public:
    void Load(std::string _path);
    void Draw();
    void Update();
    void KillPlayer();

    bool StillPlaying() { return MaybePlaying; }

    Entity& GetPlayer() { return *m_player; }
    std::vector<Enemy*>& GetMonsters() { return m_monsters; }
    const std::vector<std::vector<char>>& GetMap() { return m_map; }
    char GetLocation(Vector2D _pos);
    void ClearLocation(Vector2D _pos);
    void OpenDoor(Vector2D _pos);
private:
    Player *m_player = nullptr;
    std::vector<Enemy*> m_monsters;
    std::vector<std::vector<char>> m_map;
    std::vector<Door> m_doors;
    bool MaybePlaying = true;
};