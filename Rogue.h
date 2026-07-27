#pragma once
#include "Player.h"

class Rogue : public Player {
public:
    Rogue(string name, int hp, int mp, int power, int defence);
    void attack(Monster* monster) override;
};
