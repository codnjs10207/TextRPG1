#include "Player.h" 

Player::Player(string name, string job, int hp, int mp, int power, int defence) : name(name), job(job), hp(hp), mp(mp), maxHp(hp), maxMp(mp), power(power), defence(defence), level(1), exp(0), maxExp(100) {}

void Player::gainExp(int rewardExp) {
    exp += rewardExp;
    cout << " -> +" << rewardExp << " EXP! (EXP: " << exp << "/" << maxExp << ")" << endl;

    while (exp >= maxExp) {
        cout << endl;
        cout << " -> Level up! Lv." << level << " -> Lv." << (level + 1) << endl;
        level++;

        hp += 10;
        maxHp += 10;
        mp += 5;
        power += 5;
        cout << " -> HP +10, MP +5, Attack +5" << endl;

        exp -= maxExp;
        maxExp += 50;
        cout << " -> (Current EXP: " << exp << "/" << maxExp << ")" << endl;
    }
}

void Player::printPlayerStatus() const {
    cout << "===========================================" << endl;
    cout << "    [ " << name << " (" << job << ") - Lv." << level << " ]" << endl;
    cout << "===========================================" << endl;
    cout << " EXP : " << exp << " / " << maxExp << endl;
    cout << " HP  : " << hp << "        MP      : " << mp << endl;
    cout << " Attack : " << power << "        Defense : " << defence << endl;
    cout << "===========================================" << endl << endl;
}
