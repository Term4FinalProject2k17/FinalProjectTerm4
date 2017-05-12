#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	int choice;
	int monsterHp, playerHp, i, init, playerAttack, playerDefence, monsterAttack, monsterDefence, playerHurt, monsterHurt, playerAgility, monsterAgility;
	playerAttack = 10;
	playerDefence = 15;
	playerAgility = 5;
	monsterAttack = 10;
	monsterDefence = 15;
	monsterAgility = 5;

	srand((unsigned)time(0));
	init = rand() % 2 + 1;
	monsterHp = 100;
	playerHp = 100;
	if (init == 1) {
		cout << "Player start.\n";
		while (playerHp > 0 ||monsterHp > 0) {
			cout << "What do you want to do?\n1 - Heavy Attack\n2 - Light Attack\n3 - Defensive moves\n";
			do { cin >> choice; } while (choice>3 || choice<1);
			switch (choice) {
			case 1:
				playerAttack = rand() % 20 + 10;
				playerDefence = rand() % 10 + 10;
				playerAgility = rand() % 5;
				break;
			case 2:
				playerAttack = rand() % 5 + 10;
				playerDefence = rand() % 10 + 10;
				playerAgility = rand() % 15;
				break;
			case 3:
				playerAttack = rand() % 10 + 10;
				playerDefence = rand() % 20 + 10;
				playerAgility = rand() % 5;
				break;
			}
			choice = rand() % 3;
			switch (choice) {
			case 1:
				monsterAttack = rand() % 20 + 10;
				monsterDefence = rand() % 10 + 10;
				monsterAgility = rand() % 5;
				break;
			case 2:
				monsterAttack = rand() % 5 + 10;
				monsterDefence = rand() % 10 + 10;
				monsterAgility = rand() % 15;
				break;
			case 3:
				monsterAttack = rand() % 10 + 10;
				monsterDefence = rand() % 20 + 10;
				monsterAgility = rand() % 5;
				break;
			}

			//Monster Damage
			monsterHurt = (playerAttack - monsterAgility) - (monsterDefence / playerAttack);
			if (monsterHurt < 0) {
				monsterHurt = 0;
			}
			monsterHp = monsterHp - monsterHurt;
			cout << "You did " << monsterHurt << " damage to the monster!\n";
			cin.get();
			//Death of the beast!
			if (monsterHp < 1) {
				cout << "You killed the beast! It falls to the ground with a loud thud.\n You won with " << playerHp << " hp left.\n";
				cin.get();
				return 0;
			}
			cout << "The monster now has " << monsterHp << " hp left.\n";
			playerHurt = (monsterAttack - playerAgility) - (playerDefence / monsterAttack);
			if (playerHurt < 0) {
				playerHurt = 0;
			}
			playerHp = playerHp - playerHurt;
			cout << "The monster hits you for " << playerHurt << " damage.\n";
			//More death
			if (playerHp < 1) {
				cout << "You died. The monster rips out your entrails, devouring them.\nThe beast still has " << monsterHp << " hp left.\n";
				cin.get();
				return 0;
			}
			cout << "You now have " << playerHp << " hp left.\n\n";
		}
	}

	//Monster start
	else {
		cout << "Monster starts.\n";
		while (playerHp > 0 || monsterHp > 0) {
			choice = rand() % 3;
			switch (choice) {
			case 1:
				monsterAttack = rand() % 20 + 10;
				monsterDefence = rand() % 10 + 10;
				monsterAgility = rand() % 5;
				break;
			case 2:
				monsterAttack = rand() % 5 + 10;
				monsterDefence = rand() % 10 + 10;
				monsterAgility = rand() % 15;
				break;
			case 3:
				monsterAttack = rand() % 10 + 10;
				monsterDefence = rand() % 20 + 10;
				monsterAgility = rand() % 5;
				break;
			}
			//Player Damage
			playerHurt = (monsterAttack - playerAgility) - (playerDefence / monsterAttack);
			if (playerHurt < 0) {
				playerHurt = 0;
			}
			playerHp = playerHp - playerHurt;
			cout << "The monster hits you for " << playerHurt << " damage.\n";
			//Death
			if (playerHp < 1) {
				cout << "You died. The monster rip off your head off your shoulders.\n The beast had " << monsterHp << " hp left.\n";
				cin.get();
				return 0;
			}
			cout << "You now have " << playerHp << " hp left.\n\n";
			cout << "What do you want to do?\n1 - Heavy Attack\n2 - Light Attack\n3 - Defensive moves\n";
			do { cin >> choice; } while (choice>3 || choice<1);
			switch (choice) {
			case 1:
				playerAttack = rand() % 20 + 10;
				playerDefence = rand() % 10 + 10;
				playerAgility = rand() % 5;
				break;
			case 2:
				playerAttack = rand() % 5 + 10;
				playerDefence = rand() % 10 + 10;
				playerAgility = rand() % 15;
				break;
			case 3:
				playerAttack = rand() % 10 + 10;
				playerDefence = rand() % 20 + 10;
				playerAgility = rand() % 5;
				break;
			}


			//Monster Damage
			monsterHurt = (playerAttack - monsterAgility) - (monsterDefence / playerAttack);
			if (monsterHurt < 0) {
				monsterHurt = 0;
			}
			monsterHp = monsterHp - monsterHurt;
			cout << "You did " << monsterHurt << " damage to the monster!\n";
			cin.get();
			//Death:
			if (monsterHp < 1) {
				cout << "You killed the beast! It falls you the ground with a loud thud.\n You won with " << playerHp << " hp remaining.\n";
				cin.get();
				return 0;
			}
			cout << "The monster now has " << monsterHp << " hp left.\n";
		}
	}
}