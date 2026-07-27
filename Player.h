#pragma once
#include <iostream>
#include <string>

using namespace std;
class Monster;

class Player {
protected:
	string name;
	string job;
	int hp;
	int mp;
	int power;
	int defence;

	int level;
	int exp;
	int maxExp;
	int maxHp;
	int maxMp;

public:
	Player(string name, string job, int hp, int mp, int power, int defence);
	virtual ~Player() {}

	virtual void attack(Monster* monster) = 0;

	void gainExp(int rewardExp);

	void printPlayerStatus() const;

	string getName() { return name; }
	string getJob() { return job; }
	int getLevel() { return level; }
	int getHp() { return hp; }
	int getMp() { return mp; }
	int getPower() { return power; }
	int getDefence() { return defence; }
	int getMaxHp() { return maxHp; }
	int getMaxMp() { return maxMp; }

	void setName(string name) { this->name = name; }
	void setJob(string job) { this->job = job; }
	void setLevel(int level) { this->level = level; }
	void setHp(int hp) { this->hp = hp; }
	void setMp(int mp) { this->mp = mp; }
	void setPower(int power) { this->power = power; }
	void setDefence(int defence) { this->defence = defence; }
};