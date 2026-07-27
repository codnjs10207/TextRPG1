#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include "Player.h"
#include "Warrior.h"
#include "Mage.h"
#include "Rogue.h"
#include "Archer.h"
#include "Monster.h"
#include "Inventory.h"
#include "Dungeon.h"

using namespace std;

string name;
const int SIZE = 4;
int playerstat[SIZE] = { 0 };
// {HP, MP, 공격력, 방어력}
int PotionHP = 0;
int PotionMP = 0;
int choice;
bool isGameStart = false;

struct Item {
	string name;
	int price = 0;

	void PrintItem() const {
		cout << name << " (" << price << "G)" << endl;
	}

};

bool compareByPrice(const Item& a, const Item& b) {
	return a.price < b.price;
}

Inventory<Item> inventory(10);

struct PotionRecipe {
	string potionName;
	string ingredient1;
	string ingredient2;

	void PrintRecipe() const {
		cout << "-> " << potionName << " : " << ingredient1 << " x1, " << ingredient2 << " x1" << endl;

	}
};

vector<PotionRecipe> recipes = {
	{"HPPotion", "Herb", "Clear Water"},
	{"MPPotion", "Slime Jelly", "Clear Water"},
	{"StaminaPotioin", "Herb", "Berry"}
};

const int Max_Stock = 3;
map<string, int> potionStock_;

void InitPotionStock() {
	for (const PotionRecipe& PR : recipes) {
		potionStock_[PR.potionName] = Max_Stock;
	}
}

int GetStock(string name) {
	if (potionStock_.find(name) != potionStock_.end()) {
		return potionStock_[name];
	}
	return 0;
}

bool DispensePotion(string name) {
	if (GetStock(name) > 0) {
		potionStock_[name]--;
		cout << "-> Dispense " << name << "  (stock: " << potionStock_[name] << ")" << endl;
		return true;
	}
	else {
		cout << "-> Dispense failed: out of stock!" << endl;
		return false;
	}
}

void ReturnPotion(string name) {
	if (GetStock(name) < Max_Stock) {
		potionStock_[name]++;
		cout << "-> Return empty bottle  (stock: " << potionStock_[name] << ")" << endl;
	}
	else {
		cout << "-> Return failed: stock is already full (MAX: " << Max_Stock << ")!" << endl;
	}
}

void printTitle()
{
	cout << "===========================================" << endl;
	cout << "	[ Dungeon Escape Text RPG ]" << endl;
	cout << "===========================================" << endl;

}

void statsMenu()
{
	cout << "===========================================" << endl;
	cout << "	" << name << "'s Stats" << endl;
	cout << "===========================================" << endl;
	cout << "HP: " << playerstat[0] << "		MP: " << playerstat[1] << endl;
	cout << "Attack: " << playerstat[2] << "		Defense: " << playerstat[3] << endl;
	cout << endl;
}

Player* createCharacter(string name, int playerstat[]) {
	cout << "< Job Selection >" << endl;
	cout << name << ", choose your job!" << endl;
	cout << "1. Warrior   2. Mage   3. Rogue   4. Archer" << endl;
	cout << "Choose: ";

	int jobChoice;
	cin >> jobChoice;

	Player* player = nullptr;

	switch (jobChoice) {
	case 1:
		cout << endl;
		player = new Warrior(name, playerstat[0], playerstat[1], playerstat[2], playerstat[3]);
		break;
	case 2:
		cout << endl;
		player = new Mage(name, playerstat[0], playerstat[1], playerstat[2], playerstat[3]);
		break;
	case 3:
		cout << endl;
		player = new Rogue(name, playerstat[0], playerstat[1], playerstat[2], playerstat[3]);
		break;
	case 4:
		cout << endl;
		player = new Archer(name, playerstat[0], playerstat[1], playerstat[2], playerstat[3]);
		break;
	default:
		cout << endl;
		player = new Warrior(name, playerstat[0], playerstat[1], playerstat[2], playerstat[3]);
		break;
	}
	return player;
}

Player* statsCustom()
{
	Player* player = nullptr;

	while (!isGameStart) {
		cout << "===========================================" << endl;
		cout << "	< Character Upgrade >" << endl;
		cout << "1. HP UP    2. MP UP    3. Attack x2" << endl;
		cout << "4. Defense x2  5. Show Stats  0. Jop Select & Start Game" << endl;
		cout << "===========================================" << endl;

		cout << "Choose : ";
		cin >> choice;
		cout << endl;

		switch (choice) {
		case 0:
			system("cls");
			printTitle();
			cout << endl;

			player = createCharacter(name, playerstat);
			cout << endl;

			cout << "Starting the game!" << endl;
			cout << endl;
			cout << "      /| ________________" << endl;
			cout << " O|===|* >________________>" << endl;
			cout << "      ||" << endl;
			cout << endl << endl;

			isGameStart = true;
			break;

		case 1:
			if (PotionHP == 0)
			{
				cout << "No potions left!" << endl;
				cout << endl;
				break;
			}
			cout << "* HP increased by 20. (HP Potion used: " << PotionHP - 1 << " left)" << endl;
			PotionHP -= 1;
			playerstat[0] += 20;
			cout << endl;
			break;

		case 2:
			if (PotionMP == 0)
			{
				cout << "No potions left!" << endl;
				cout << endl;
				break;
			}
			cout << "* MP increased by 20. (MP Potion used: " << PotionMP - 1 << " left)" << endl;
			PotionMP -= 1;
			playerstat[1] += 20;
			cout << endl;
			break;

		case 3:
			cout << "* Attack multiplied by 2." << endl;
			playerstat[2] *= 2;
			cout << endl;

			break;

		case 4:
			cout << "* Defense multiplied by 2." << endl;
			playerstat[3] *= 2;
			cout << endl;

			break;

		case 5:
			system("cls");
			printTitle();
			cout << endl;
			statsMenu();
			break;

		default:
			cout << "Please choose another number." << endl;
			cout << endl;

			break;
		}

	}
	return player;
}

void enterStats()
{
	while (true)
	{
		cout << "Enter HP and MP: ";
		cin >> playerstat[0];
		cin >> playerstat[1];

		if (playerstat[0] < 50 || playerstat[1] < 50)
		{
			cout << "HP or MP is too low. Try again." << endl;
		}

		else {
			break;
		}
	}

	while (true)
	{
		cout << "Enter Attack and Defense: ";
		cin >> playerstat[2];
		cin >> playerstat[3];

		if (playerstat[2] < 50 || playerstat[3] < 50)
		{
			cout << "Attack or Defense is too low. Try again." << endl;
		}

		else {
			break;
		}
	}
}

bool startBattle(Player* player, Monster& monster) {
	cout << endl;
	cout << " [ Battle Start! ] " << player->getName() << "(" << player->getJob() << ") vs " << monster.getName() << endl;
	cout << endl;

	while (player->getHp() > 0 && monster.getHp() > 0) {
		cout << "--- Player Turn ---" << endl;
		cout << "1. Attack" << endl;
		cout << "2. Use Item" << endl;
		cout << "3. Run" << endl;
		cout << "Choose: ";
		int turnChoice;
		cin >> turnChoice;
		cout << endl;

		if (turnChoice == 2) {
			cout << "[ Inventory ]" << endl;
			if (inventory.GetSize() == 0) {
				cout << "The inventory is empty!" << endl << endl;
			}
			else {
				for (int i = 0; i < inventory.GetSize(); i++) {
					cout << (i+1) << ". " << inventory[i].name << " (" << inventory[i].price << "G)" << endl;
				}
				cout << "0. Cancel" << endl;
				cout << "Choose item: ";
				int itemChoice;
				cin >> itemChoice;
				cout << endl;

				if (itemChoice > 0 && itemChoice <= inventory.GetSize()) {
					int idx = itemChoice - 1; 
					string itemName = inventory[idx].name;

					if (itemName == "HPPotion" || itemName == "HP Potion") {
						int oldHp = player->getHp();
						player->setHp(min(oldHp + 50, player->getMaxHp()));
						cout << "* " << itemName << " used! HP restored by 50 (" << oldHp << " -> " << player->getHp() << ")" << endl << endl;

						inventory.RemoveItemAt(idx);
					}
					else if (itemName == "MPPotion" || itemName == "MP Potion") {
						int oldMp = player->getMp();
						player->setMp(min(oldMp + 50, player->getMaxMp()));
						cout << "* " << itemName << " used! MP restored by 50 (" << oldMp << " -> " << player->getMp() << ")" << endl << endl;

						inventory.RemoveItemAt(idx);
					}
					else {
						cout << "You cannot use this item in battle." << endl << endl;
					}
				}
				else if (itemChoice == 0) {
					cout << "Canceled item use." << endl << endl;
					continue;
				}
				else {
					cout << "Invalid item number!" << endl << endl;
				}
			}
		}
		else if (turnChoice == 1) {
			player->attack(&monster);
		}
		else if (turnChoice == 3) {
			cout << "_.,,_.. =3 =3 " << player->getName() << " ran away safely!" << endl;
			return false;
		}
		else {
			cout << "Invalid choice. Please try again." << endl;
			continue;
		}

		if (monster.getHp() <= 0) {
			cout << " (Dead) ";
			cout << endl << endl;
			cout << "★ Victory!" << endl;

			player->gainExp(monster.getExpReward());
			cout << endl;

			cout << "  -> Got: " << monster.getDropItemName() << "!" << endl;
			cout << "  -> Saved to inventory." << endl << endl;

			Item droppedItem;
			droppedItem.name = monster.getDropItemName();
			droppedItem.price = monster.getDropItemPrice();
			inventory.AddItem(droppedItem);

			return true;
		}

		cout << endl << endl;
		cout << "--- Monster Turn ---" << endl;
		monster.attack(player);

		int monsterDamage = monster.getPower() - player->getDefence();
		if (monsterDamage <= 0) {
			monsterDamage = 1;
		}

		int playerOldHp = player->getHp();
		player->setHp(playerOldHp - monsterDamage);

		cout << monsterDamage << " damage to " << player->getName() << "!" << endl;
		cout << player->getName() << " HP : " << playerOldHp << " -> " << player->getHp();
		cout << endl << endl;

		if (player->getHp() <= 0) {
			cout << " (Dead) " << endl;
			cout << endl;
			cout << " Game Over..." << endl;
			return false;
		}
	}
	return false;
}

void AlchemyWorkshop() {
	int ChoiceShop;

	while (true) {
		cout << "=== Potion Shop ===" << endl;
		cout << "1. Show all recipes" << endl;
		cout << "2. Search by potion name" << endl;
		cout << "3. Search by ingredient" << endl;
		cout << "4. Check Potion Stocks" << endl;
		cout << "5. [Test] Dispense HP Potion" << endl;
		cout << "6. [Test] Return HP Potion" << endl;
		cout << "0. Go back" << endl;
		cout << endl;

		cout << "Choose : ";
		cin >> ChoiceShop;
		cout << endl;

		switch (ChoiceShop) {
		case 0:
			system("cls");
			printTitle();
			return;

		case 1:
			for (const PotionRecipe& PR : recipes) {
				PR.PrintRecipe();
			}
			cout << endl;
			break;

		case 2:
		{
			string searchName;
			cout << "Search potion name: ";
			cin.ignore();
			getline(cin, searchName);

			bool isFound = false;
			for (const PotionRecipe& PR : recipes) {
				if (PR.potionName == searchName) {
					PR.PrintRecipe();
					isFound = true;
					break;
				}
			}

			if (!isFound) {
				cout << "It cannot be found." << endl;
			}
			cout << endl;
			break;
		}

		case 3: {
			string searchIngredient;
			cout << "Search ingredient: ";
			cin.ignore();
			getline(cin, searchIngredient);

			int count = 0;
			for (const PotionRecipe& PR : recipes) {
				if (PR.ingredient1 == searchIngredient || PR.ingredient2 == searchIngredient)
				{
					PR.PrintRecipe();
					count++;
				}
			}

			if (count == 0) {
				cout << "It cannot be found." << endl;
			}
			else {
				cout << "Found " << count << " recipes." << endl;
			}
			cout << endl;
			break;
		}

		case 4:
			for (const auto& pair : potionStock_) {
				cout << pair.first << " stock: " << pair.second << endl;
			}
			cout << endl;
			break;

		case 5:
			DispensePotion("HPPotion");
			cout << endl;
			break;

		case 6:
			ReturnPotion("HPPotion");
			cout << endl;
			break;

		default:
			cout << "Please choose another number." << endl << endl;
			break;
		}
	}
}

void mainMenu(Player* player)
{
	int choiceMenu;

	while (true) {
		cout << "=== Main Menu ===" << endl;
		cout << "1. Enter Dungeon" << endl;
		cout << "2. Check Inventory" << endl;
		cout << "3. Potion Shop" << endl;
		cout << "4. Sort Inventory (by Price)" << endl;
		cout << "0. Quit" << endl;
		cout << endl;
		
		cout << "Choose : ";
		cin >> choiceMenu;
		cout << endl;

		switch (choiceMenu) {
		case 0:
			system("cls");
			printTitle();
			cout << "Exit Game.." << endl;
			return;

		case 1:
		{
			vector<Monster> floor1Rooms = {
				Monster("Slime", 30, 0, 15, "Slime Jelly", 30, 30),
				Monster("Goblin", 50, 0, 25, "Goblin Ear", 50, 50),
				Monster("Orc", 80, 0, 35, "Orc Axe", 100, 80)
			};
			Monster floor1Boss("Dragon", 200, 50, 60, "Dragon Scale", 500, 200);

			Dungeon dungeon1("Dungeon Floor 1", floor1Rooms, floor1Boss);

			vector<Monster> floor2Rooms = {
				Monster("Skeleton", 100, 0, 45, "Bone", 150, 100),
				Monster("Dark Knight", 150, 0, 55, "Dark Sword", 250, 150),
				Monster("Lich", 200, 50, 70, "Magic Stone", 400, 200)
			};
			Monster floor2Boss("Demon Lord", 500, 100, 100, "Demon Horn", 1000, 500);

			Dungeon dungeon2("Dungeon Floor 2", floor2Rooms, floor2Boss);
			
			bool isCleared1 = dungeon1.enter(player);

			if (isCleared1) {
				cout << "Do you want to enter Dungeonn Floor 2? (1. Yes / 2. No, return to town): ";
				int nextChoice;
				cin >> nextChoice;
				cout << endl;

				if (nextChoice == 1) {
					bool isCleared2 = dungeon2.enter(player);

					if (isCleared2) {
						cout << "★ You Have Cleared All Dungeons! Congratulations!" << endl;
						exit(0);
					}
				}
				else {
					cout << "Returning to town to rest..." << endl << endl;
				}
			}
			break;
		}

		case 2:
			system("cls");
			printTitle();
			cout << "[ Inventory (" << inventory.GetSize() << "/" << inventory.GetCapacity() << ") ]" << endl;
			inventory.PrintAllItems();
			cout << endl;
			break;

		case 3:
			system("cls");
			printTitle();
			AlchemyWorkshop();
			break;

		case 4:
			system("cls");
			printTitle();
			if (inventory.GetSize() == 0) {
				cout << "The inventory is empty." << endl << endl;
			}
			else {
				inventory.SortItems(compareByPrice);

				cout << "[ Inventory sorted by price ]" << endl;
				inventory.PrintAllItems();
				cout << endl;
			}
			break;

		default:
			cout << "Please choose another number." << endl << endl;
			break;
		}
	}
}

void setPotion(int count, int* p_HPPotion, int* p_MPPotion) {
	*p_HPPotion = count;
	*p_MPPotion = count;
}

int main() {
	printTitle();

	InitPotionStock();

	cout << "Enter your hero's name: ";
	cin >> name;
	cout << endl;

	enterStats();

	system("cls");
	printTitle();
	statsMenu();

	setPotion(5, &PotionHP, &PotionMP);

	cout << "* You received " << PotionHP << " HP Potions and " << PotionMP << " MP Potions." << endl;

	Player* player = statsCustom();
	player->printPlayerStatus();

	mainMenu(player);

	delete player;
	return 0;

}
