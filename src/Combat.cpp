#include "Combat.hpp"

void StartCombat(Player *_player, Enemy *_enemy)
{
    bool run = false;
    char input;
    std::string instruction = "What action do you wish to take?\nLight Attack: (l)\nNormal Attack: (a)\nHeavy Attack: (h)\nBlock (Requires Shield): (b)\nRun: (r)\n"; 
    printf("You have encountered a %s\n", _enemy->name.c_str());

    while(_enemy->health > 0 && _player->health > 0 && !run)
    {
        char enemy_action = _enemy->actions[RollIndex(_enemy->actions.size())];
        printf("Your Health: %i          Enemy Health: %i\n", _player->health, _enemy->health);
        printf("the enemy plans to %c\n", enemy_action);
        input = ' ';

        while (input != 'l'&&input != 'a'&&input != 'h'&&input != 'b'&&input != 'r')
        {
          input = request_char(instruction.c_str());
        }

        if(_player->stats.dexterity>=_enemy->stats.dexterity)
        {
            if(enemy_action == 'b')
            {
                Act(_enemy,_player,enemy_action,&run);
                Act(_player,_enemy,input,&run);
            }
            else
            {
                Act(_player,_enemy,input,&run);
                if((*_enemy).health>0)
                {
                    Act(_enemy,_player,enemy_action,&run);
                }
            }
        } 
        else
        {
            if(input == 'b'|| input == 'r')
            {
                Act(_player,_enemy,input,&run);
                Act(_enemy,_player,enemy_action,&run);
            }
            else
            {
                Act(_enemy,_player,enemy_action,&run);
                if((*_player).health>0)
                {
                    Act(_player,_enemy,input,&run);
                }
            }
        }
        _enemy->stats.block=0;
        _player->stats.block=0;
    
    }
    if(_player->health<=0)
    {
        printf("You Died :,( \n");
    }
    else if(_enemy->health<=0)
    {
        printf("You Win\n");
        int exp = (((*_enemy).stats.level * 2)+(*_enemy).weapon.rarity+(*_enemy).armor.rarity+(*_enemy).shield.rarity)*2;
        printf("You got %i Experience\n",exp);
        (*_player).experience += exp;
        while((*_player).experience>=(*_player).stats.level * 10)
        {
            (*_player).experience -= (*_player).stats.level * 10;
            (*_player).Level_Up();
        }

        for(int i = 0; i<_enemy->loot_chance.size();i++)
        {
            if(RollSum(1,_enemy->loot_chance_dice[i])>=_enemy->loot_chance[i])
            {
                if(i==0)
                {
                    _player->Pick_Up(_enemy->weapon);
                }
                else if(i==1)
                {
                    _player->Pick_Up(_enemy->armor);
                }
                else if(i==2)
                {
                    _player->Pick_Up(_enemy->shield);                    
                }
            }
        }
    }
}

void Attack(Character *_attacker, Character *_target)
{
    int damage = 0;
    int to_hit = 0;
    for(int i = 0; i<(*_attacker).weapon.hit_dice.size(); i++)
    {
        to_hit += RollSum((*_attacker).weapon.hit_dice[i],(*_attacker).weapon.hit_dice_sides[i]);
    }

    if(to_hit > ((*_attacker).weapon.miss_chance+(*_attacker).stats.block)-(*_attacker).stats.expertise)
    {
        for(int i = 0; i<(*_attacker).weapon.damage_dice.size(); i++)
        {
            damage += RollSum((*_attacker).weapon.damage_dice[i],(*_attacker).weapon.damage_dice_sides[i]);
        }
        damage += ((int)(((*_attacker).stats.strength-3)/5))+((*_attacker).weapon.damage_bonus);

        damage-=((int)(((*_target).stats.defense-3)/5));
        if(damage<0)
        {
            damage = 0;
        }
        (*_target).health -= damage;
    }
    else
    {
        printf("It Missed\n");
    }
}

void Heavy_Attack(Character *_attacker, Character *_target)
{
    int damage = 0;
    int to_hit = 0;
    for(int i = 0; i<(*_attacker).weapon.hit_dice.size(); i++)
    {
        to_hit += RollSum((*_attacker).weapon.hit_dice[i],(*_attacker).weapon.hit_dice_sides[i]);
    }

    if(to_hit > ((*_attacker).weapon.miss_chance+(*_target).stats.block)-((*_attacker).stats.expertise-1))
    {
        for(int i = 0; i<(*_attacker).weapon.damage_dice.size(); i++)
        {
            damage += RollSum((*_attacker).weapon.damage_dice[i],(*_attacker).weapon.damage_dice_sides[i]);
        }
        damage += RollSum(1,(*_attacker).weapon.damage_dice_sides[0]);
        damage += ((int)(((*_attacker).stats.strength-3)/5))+((*_attacker).weapon.damage_bonus);

        damage-=((int)(((*_target).stats.defense-3)/5));
        if(damage<0)
        {
            damage = 0;
        }
        (*_target).health -= damage;
    }
    else
    {
        printf("It Missed\n");
    }
}

void Light_Attack(Character *_attacker, Character *_target)
{
    int damage = 0;
    int to_hit = 0;
    for(int i = 0; i<(*_attacker).weapon.hit_dice.size(); i++)
    {
        to_hit += RollSum((*_attacker).weapon.hit_dice[i],(*_attacker).weapon.hit_dice_sides[i]);
    }

    if(to_hit > ((*_attacker).weapon.miss_chance+(*_target).stats.block)-((*_attacker).stats.expertise+1))
    {
        for(int i = 0; i<(*_attacker).weapon.damage_dice.size(); i++)
        {
            damage += RollSum((*_attacker).weapon.damage_dice[i],(*_attacker).weapon.damage_dice_sides[i]);
        }
        damage -= RollSum(1,(*_attacker).weapon.damage_dice_sides[0]);
        damage += ((int)(((*_attacker).stats.strength-3)/5))+((*_attacker).weapon.damage_bonus);

        damage-=((int)((((*_target).stats.defense-3)+(*_target).armor.defense+(*_target).shield.defense)/5));
        if(damage<0)
        {
            damage = 0;
        }
        (*_target).health -= damage;
    }
    else
    {
        printf("It Missed\n");
    }
}

void Run(Character *_runner, Character *_target, bool* run)
{
    if(RollSum(1,20)+(*_runner).stats.dexterity>=RollSum(1,10)+(*_target).stats.dexterity)
    {
        printf("You got away!!!\n");
        *run = true;
    }
    else
    {
        printf("You can't seem to escape.\n");
    }
}

void Block(Character *_blocker)
{
    (*_blocker).stats.block += (*_blocker).shield.block;
}

void Act(Character *_acter, Character *_target, char _char, bool *run)
{
    if(_char == 'l')
    {
        Light_Attack(_acter,_target);
    }
    else if(_char == 'a')
    {
        Attack(_acter,_target);
    }
    else if(_char == 'h')
    {
        Heavy_Attack(_acter,_target);
    }
    else if(_char == 'b')
    {
        Block(_acter);
    }
    else if(_char == 'r')
    {
        Run(_acter,_target,run);
    }
}