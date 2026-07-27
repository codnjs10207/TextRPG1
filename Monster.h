#pragma once
#include <iostream>
#include <string>
#include "Player.h" 
using namespace std;

class Monster {
private:
    string name;
    int hp;
    int power;
    int defence;
    string dropItemName;
    int dropItemPrice;
    int expReward;

public:
    Monster(string name, int hp, int power, int defence, string dropItemName, int dropItemPrice, int expReward);

    string getName() { return name; }
    int getHp() { return hp; }
    void setHp(int hp) { this->hp = hp; }
    int getPower() { return power; }
    int getDefence() { return defence; }
    string getDropItemName() { return dropItemName; }
    int getDropItemPrice() { return dropItemPrice; }
    int getExpReward() const { return expReward; }

    void attack(Player* player);
};