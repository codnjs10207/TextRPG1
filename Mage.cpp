#include "Mage.h"
#include "Monster.h"

Mage::Mage(string name, int hp, int mp, int power, int defence)
	: Player(name, "Mage", hp, mp, power, defence) 
{
	job = "Mage";
	this->mp += 30;
	cout << "* You became a Mage! (MP +30)" << endl;
}

void Mage::attack(Monster* monster) {
	int damage = power - monster->getDefence();
	if (damage <= 0) {
		damage = 1;
	}

	int oldHp = monster->getHp();
	monster->setHp(oldHp - damage);

	cout << "[Mage] Fires fireball! -> " << damage << " damage to " << monster->getName() << "!" << endl;
	cout << monster->getName() << " HP : " << oldHp << " -> " << monster->getHp() << endl;
}