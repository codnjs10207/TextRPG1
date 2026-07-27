#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Player.h"
#include "Monster.h"

using namespace std;

extern bool startBattle(Player* player, Monster& monster);

class Dungeon {
private:
    string dungeonName_;
    vector<Monster> normalRooms_;
    Monster boss_;

public:
    Dungeon(string name, vector<Monster> rooms, Monster boss)
        : dungeonName_(name), normalRooms_(rooms), boss_(boss) {
    }

    bool enter(Player* player) {
        system("cls");
        cout << "===========================================" << endl;
        cout << "   [ " << dungeonName_ << " ]" << endl;
        cout << "===========================================" << endl << endl;

        for (int i = 0; i < normalRooms_.size(); i++) {
            cout << "Room " << (i + 1) << ": " << normalRooms_[i].getName()
                << "    (HP " << normalRooms_[i].getHp() << ", Attack " << normalRooms_[i].getPower() << ")" << endl;

            bool isVictory = startBattle(player, normalRooms_[i]);

            if (player->getHp() <= 0) {
                cout << "=== GAME OVER! ===" << endl;
                exit(0);
            }

            if (!isVictory) {
                cout << "-> Escaping the " << dungeonName_ << " and returning to town..." << endl << endl;
                return false;
            }

            cout << " -> Room " << (i + 1) << " Clear!" << endl;
            cout << "-------------------------------------------" << endl << endl;
        }

        cout << "★ Boss Room Unlocked!" << endl;
        cout << boss_.getName() << " appears! (HP " << boss_.getHp() << ", Attack " << boss_.getPower() << ")" << endl;

        bool isBossVictory = startBattle(player, boss_);

        if (player->getHp() <= 0) {
            cout << "=== GAME OVER! ===" << endl;
            exit(0);
        }

        if (!isBossVictory) {
            cout << "-> Escaping from the boss and returning to town..." << endl << endl;
            return false;
        }

        cout << boss_.getName() << " defeated!" << endl;
        cout << "=== " << dungeonName_ << " CLEAR! ===" << endl << endl;
        return true;
    }
};