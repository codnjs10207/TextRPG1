#include "Rogue.h"
#include "Monster.h"

Rogue::Rogue(string name, int hp, int mp, int power, int defence)
	: Player(name, "Rogue", hp, mp, power, defence)
{
	job = "Rogue";
	this->power += 30;
	cout << "* You became a Rogue! (POWER +30)" << endl;
}

void Rogue::attack(Monster* monster) {
	int damage = (power / 5) - monster->getDefence();
	if (damage <= 0) {
		damage = 1;
	}

	int totalDamage = damage * 5;
	int oldHp = monster->getHp();
	monster->setHp(oldHp - totalDamage);
	cout << "[Rogue] Stabs dagger! -> " << damage << " damage to " << monster->getName() << "! (x5)" << endl;
	cout << monster->getName() << " HP : " << oldHp << " -> " << monster->getHp() << endl;
}