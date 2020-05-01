#include "GameLogic.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string choice;
	bool win = 0;
	bool flag1 = 1, flag2 = 1, flag3 = 1, flag4 = 1, flag5 = 1;
	bool& f1 = flag1; bool& f2 = flag2; bool& f3 = flag3; bool& f4 = flag4; bool& f5 = flag5;

	Map GameMap;
	GameLogic Game;

	//Create standard player class
	Player *Avatar = new Player();

	cout << "Instructions: 'look' - room description, 'take' - pick up an item, 'use' - use an item, drop - drop an item" << endl << "All rooms have north, south, east, west, up, and down as possible directions." << endl << "All commands in lower case. " << endl << endl;
	cout << "You have just arrived at the property your eccentric grandfather left you." << endl << "The letter he left hinted that the property had a few secrets of it's own - better start checking it out!" << endl << endl << endl;

	Avatar->pLoc->pRoomName();
	Avatar->pLoc->pRoomDesc();

	cout << endl;

	while (win == 0) {
		choice = Game.GetAction();
		cout << endl;
		win = Game.HandleAction(choice, Avatar, f1, f2, f3 ,f4, f5);
		cout << endl;
	}

	if (win == 1) {
		char again;
		cout << "Game Over! You win!" << endl;
		cout << "Press 'y' to play again or 'n' to quit." << endl;
		cin >> again;
		if (again == 'y') {
			system("start RestartJaegerAdventureGameFinal.cmd");
		}
		else if (again == 'n') {
			return 0;
		}
		else {
			cout << "Invalid choice! Please use 'y' or 'n'.";
		}
	}	
}