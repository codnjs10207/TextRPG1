#include "Warrior.h"
#include "Monster.h"

Warrior::Warrior(string name, int hp, int mp, int power, int defence)
    : Player(name, "Warrior", hp, mp, power, defence)
{
    job = "Warrior";
    this->hp += 30;
    cout << "* You became a Warrior! (HP +30)" << endl;
}

void Warrior::attack(Monster* monster) {
    int damage = power - monster->getDefence();
    if (damage <= 0) {
        damage = 1;
    }
    int oldHp = monster->getHp();
    monster->setHp(oldHp - damage);

    cout << "[Warrior] Swings sword! -> " << damage << " damage to " << monster->getName() << "!" << endl;
    cout << monster->getName() << " HP : " << oldHp << " -> " << monster->getHp() << endl;

}
