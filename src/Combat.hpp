#pragma once

#include "Player.hpp"
#include "Enemy.hpp"
#include "Character.hpp"
#include "Dice.hpp"
#include "Room.hpp"

extern void StartCombat(Player*, Enemy*);
extern void Attack(Character*, Character*);
extern void Heavy_Attack(Character* , Character*);
extern void Light_Attack(Character*, Character*);
extern void Run(Character, Character);
extern void Block(Character);
extern void Act(Character*, Character*, char, bool*);



