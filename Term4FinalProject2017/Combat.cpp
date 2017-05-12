#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	int choice;
	int mhp, hp, i, init, atk, def, matk, mdef, hurt, mhurt, agi, magi;
	atk = 10;
	def = 15;
	agi = 5;
	matk = 10;
	mdef = 15;
	magi = 5;

	srand((unsigned)time(0));
	init = rand() % 2 + 1;
	mhp = rand() % 50 + 60;
	hp = rand() % 20 + 80;
	if (init == 1) {
		cout << "You start.\n";
		while (hp > 0 || mhp > 0) {
			cout << "What do you want to do?\n1 - Fierce Attack\n2 - Light Attack\n3 - Defensive moves\n";
			do { cin >> choice; } while (choice>3 || choice<1);
			switch (choice) {
			case 1:
				atk = rand() % 20 + 10;
				def = rand() % 10 + 10;
				agi = rand() % 5;
				break;
			case 2:
				atk = rand() % 5 + 10;
				def = rand() % 10 + 10;
				agi = rand() % 15;
				break;
			case 3:
				atk = rand() % 10 + 10;
				def = rand() % 20 + 10;
				agi = rand() % 5;
				break;
			}
			choice = rand() % 3;
			switch (choice) {
			case 1:
				matk = rand() % 20 + 10;
				mdef = rand() % 10 + 10;
				magi = rand() % 5;
				break;
			case 2:
				matk = rand() % 5 + 10;
				mdef = rand() % 10 + 10;
				magi = rand() % 15;
				break;
			case 3:
				matk = rand() % 10 + 10;
				mdef = rand() % 20 + 10;
				magi = rand() % 5;
				break;
			}

			//
			mhurt = (atk - magi) - (mdef / atk);
			if (mhurt < 0) {
				mhurt = 0;
			}
			mhp = mhp - mhurt;
			cout << "You did " << mhurt << " damage to the monster!\n";
			cin.get();
			//Death of the beast!
			if (mhp < 1) {
				cout << "You killed the beast! You won with " << hp << " hp left.\n";
				cin.get();
				return 0;
			}
			cout << "The monster now has " << mhp << " hp left.\n";
			hurt = (matk - agi) - (def / matk);
			if (hurt < 0) {
				hurt = 0;
			}
			hp = hp - hurt;
			cout << "The monster hits you for " << hurt << " damage.\n";
			//More death
			if (hp < 1) {
				cout << "You died. The beast still has " << mhp << " hp left.\n";
				cin.get();
				return 0;
			}
			cout << "You now have " << hp << " hp left.\n\n";
		}
	}

	//Monster start
	else {
		cout << "Monster starts.\n";
		while (hp > 0 || mhp > 0) {
			choice = rand() % 3;
			switch (choice) {
			case 1:
				matk = rand() % 20 + 10;
				mdef = rand() % 10 + 10;
				magi = rand() % 5;
				break;
			case 2:
				matk = rand() % 5 + 10;
				mdef = rand() % 10 + 10;
				magi = rand() % 15;
				break;
			case 3:
				matk = rand() % 10 + 10;
				mdef = rand() % 20 + 10;
				magi = rand() % 5;
				break;
			}
			//Player Damage
			hurt = (matk - agi) - (def / matk);
			if (hurt < 0) {
				hurt = 0;
			}
			hp = hp - hurt;
			cout << "The monster hits you for " << hurt << " damage.\n";
			//Death
			if (hp < 1) {
				cout << "You died. The beast still has " << mhp << " hp left.\n";
				cin.get();
				return 0;
			}
			cout << "You now have " << hp << " hp left.\n\n";
			cout << "What do you want to do?\n1 - Fierce Attack\n2 - Lithe Attack\n3 - Defensive moves\n";
			do { cin >> choice; } while (choice>3 || choice<1);
			switch (choice) {
			case 1:
				atk = rand() % 20 + 10;
				def = rand() % 10 + 10;
				agi = rand() % 5;
				break;
			case 2:
				atk = rand() % 5 + 10;
				def = rand() % 10 + 10;
				agi = rand() % 15;
				break;
			case 3:
				atk = rand() % 10 + 10;
				def = rand() % 20 + 10;
				agi = rand() % 5;
				break;
			}


			//Monster Damage
			mhurt = (atk - magi) - (mdef / atk);
			if (mhurt < 0) {
				mhurt = 0;
			}
			mhp = mhp - mhurt;
			cout << "You did " << mhurt << " damage to the monster!\n";
			cin.get();
			//Death:
			if (mhp < 1) {
				cout << "You killed the beast!! You won with " << hp << " hp left.\n";
				cin.get();
				return 0;
			}
			cout << "The monster now has " << mhp << " hp left.\n";
		}
	}
}