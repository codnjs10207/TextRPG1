#include "Monster.h"

Monster::Monster(string name, int hp, int power, int defence, string dropItemName, int dropItemPrice, int expReward) : name(name), hp(hp), power(power), defence(defence), dropItemName(dropItemName), dropItemPrice(dropItemPrice), expReward(expReward) {}

void Monster::attack(Player* player) {
	cout << name << " attacks " << player->getName() << "!" << endl;
}