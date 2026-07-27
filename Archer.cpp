#include "Archer.h"
#include "Monster.h"

Archer::Archer(string name, int hp, int mp, int power, int defence)
	: Player(name, "Archer", hp, mp, power, defence)
{
	job = "Archer";
	this->defence += 30;
	cout << "* You became a Archer! (DEFENCE +30)" << endl;
}

void Archer::attack(Monster* monster) {
	int damage = (power / 3) - monster->getDefence();
	if (damage <= 0) {
		damage = 1;
	}

	int totalDamage = damage * 3;
	int oldHp = monster->getHp();
	monster->setHp(oldHp - totalDamage);
	cout << "[Archer] Shoots arrow! -> " << damage << " damage to " << monster->getName() << "! (x3)" << endl;
	cout << monster->getName() << " HP : " << oldHp << " -> " << monster->getHp() << endl;
}
