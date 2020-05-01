#include "GameLogic.h"

string GameLogic::GetAction() {
	string choice;
	cout << "What will you do?\n";
	cin >> choice;
	return choice;
}

bool GameLogic::HandleAction(string choice, Player* Av, bool& f1, bool& f2, bool& f3, bool& f4, bool& f5) {
	string itemT, itemD, itemU;
	string rName = Av->pLoc->roomName();
	bool win = 0;
	if (choice == "look") {//handles look
		Events(Av, f1, f2, f3, f4, f5);
	}
	else if (choice == "north") {//move north
		if (Av->pLoc->pNorth == 0) {
			cout << "You can't go that way!\n";
		}
		else if (rName == "Forest" && f2 == 1) {
			cout << "The gnomes are blocking the path!\n They chatter angrily and force you back every time you try to go around." << endl;
		}
		else {
			Av->pLoc = Av->pLoc->pNorth;
			Av->pLoc->pRoomName();
			Events(Av, f1, f2, f3, f4, f5);
		}
	}
	else if (choice == "south") {//move south
		if (Av->pLoc->pSouth == 0) {
			cout << "You can't go that way!\n";
		}
		else {
			Av->pLoc = Av->pLoc->pSouth;
			Av->pLoc->pRoomName();
			Events(Av, f1, f2, f3, f4, f5);
		}
	}
	else if (choice == "east") {//move east
		if (Av->pLoc->pEast == 0) {
			cout << "You can't go that way!\n";
		}
		else if (rName == "Forest Meadow" && f3 == 1) {
			cout << "The dragon is watching you closely, small trails of smoke drifting menacingly from its mouth. \n Better not try and sneak past it unless you want to end up extra crispy." << endl;
		}
		else {
			Av->pLoc = Av->pLoc->pEast;
			Av->pLoc->pRoomName();
			Events(Av, f1, f2, f3, f4, f5);
		}
	}
	else if (choice == "west") {//move west
		if (Av->pLoc->pWest == 0) {
			cout << "You can't go that way!\n";
		}
		else {
			Av->pLoc = Av->pLoc->pWest;
			Av->pLoc->pRoomName();
			Events(Av, f1, f2, f3, f4, f5);
		}
	}
	else if (choice == "up") {//move up
		if (Av->pLoc->pUp == 0) {
			cout << "There's nothing there!\n";
		}
		else {
			Av->pLoc = Av->pLoc->pUp;
			Av->pLoc->pRoomName();
			Events(Av, f1, f2, f3, f4, f5);
		}
	}
	else if (choice == "down") {//move down
		if (Av->pLoc->pDown == 0) {
			cout << "There's nothing there!\n";
		}
		else {
			Av->pLoc = Av->pLoc->pDown;
			Av->pLoc->pRoomName();
			Events(Av, f1, f2, f3, f4, f5);
		}
	}
	else if (choice == "take") {//pick up an item
		cout << "Take what?\n";
		cin >> itemT;
		Av->pLoc->takeRoomItems(itemT);
		Av->inventory.push_back(itemT);
		Av->getInventory();
		Events(Av, f1, f2, f3, f4, f5);
		if (itemT == "treasure") {
			win = 1;
		}
	}
	else if (choice == "drop") {//drop an item
		cout << "Drop what?\n";
		cin >> itemD;
		Av->useItems(itemD);
		Av->pLoc->setRoomItems(itemD);
		Av->getInventory();
		Events(Av, f1, f2, f3, f4, f5);
	}
	else if (choice == "use") {//use an item
		cout << "Use what?\n";
		cin >> itemU;
		if (rName == "Attic" && itemU == "key") {			
			if (any_of(Av->inventory.begin(), Av->inventory.end(), [](string s) {return s == "key"; })) {//check to see if player has item before attempting to remove from inventory
				Av->useItems(itemU);//removes item from player inventory
				f1 = 0;
				cout << "\nThe lockbox opens to reveal a map!" << endl;
			}
			else {
				cout << "\nYou don't have that item!" << endl;
			}
		}
		else if (rName == "Forest" && itemU == "potion") {
			if (any_of(Av->inventory.begin(), Av->inventory.end(), [](string s) {return s == "potion"; })) {
				Av->useItems(itemU);
				f2 = 0;
				cout << "\nThe gnomes babble excitedly in some strange language of their own, but step aside." << endl;
			}
			else {
				cout << "\nYou don't have that item!" << endl;
			}
		}
		else if (rName == "Forest Meadow" && itemU == "ukulele") {
			if (any_of(Av->inventory.begin(), Av->inventory.end(), [](string s) {return s == "ukulele"; })) {
				Av->useItems(itemU);
				f3 = 0;
				cout << "\nThe ukulele begins to glow brightly as you play it and the dragon starts to sway slightly.\n After a few minutes, the dragon slumps to the ground snoring loudly." << endl;
			}
			else {
				cout << "\nYou don't have that item!" << endl;
			}
		}
		else if (rName == "Cave" && itemU == "lantern") {
			if (any_of(Av->inventory.begin(), Av->inventory.end(), [](string s) {return s == "lantern"; })) {
				Av->useItems(itemU);
				f4 = 0;
				cout << "\nThe lantern light reveals an empty cave. \nThe dirt of the cave floor looks recently disturbed." << endl;
			}
			else {
				cout << "\nYou don't have that item!" << endl;
			}
		}
		else if (rName == "Cave" && itemU == "shovel") {
			if (any_of(Av->inventory.begin(), Av->inventory.end(), [](string s) {return s == "shovel"; })) {
				Av->useItems(itemU);
				f5 = 0;
				cout << "\nThe shovel hits something hard. You brush away damp earth to reveal a large, ornate chest." << endl;
			}
			else {
				cout << "\nYou don't have that item!" << endl;
			}
		}
		else {
			cout << "\nYou can't use that here!" << endl;
		}
		Events(Av, f1, f2, f3, f4, f5);
	}
	else {//invalid choice
		cout << "\nCan't just stand there! What will you do?";
	}

	return win;
}

void GameLogic::Events(Player* Av, bool flag1, bool flag2, bool flag3, bool flag4, bool flag5) {
	string rName = Av->pLoc->roomName();

	if (rName == "Attic" && flag1 == 1) {
		bool locked = flag1;
		if (locked) {
			cout << "\nThere's a lockbox sitting in the attic.\n Maybe there's a key?" << endl;
		}
	}
	else if (rName == "Forest" && flag2 == 1) {
		bool blocked = flag2;
		if (blocked) {
			cout << "\nThe clearing with grandpa's house is to the south and there's a narrow path through the forest to the north.\n Gnomes block the path. They seem to want something.\n Perhaps you have something to offer them?" << endl;
		}
	}
	else if (rName == "Forest Meadow" && flag3 == 1) {
		bool awake = flag3;
		if (awake) {
			cout << "\nThe forest path is south of the meadow.\n There is a cave guarded by a large dragon to the east.\n You can't fight it, but perhaps you can soothe the beast somehow." << endl;
		}
	}
	else if ((rName == "Cave") && (flag4 == 1 || flag5 == 1)) {
		bool dark = flag4;
		bool buried = flag5;
		if (dark) {
			cout << "\nIt's too dark to see anything in the cave! Maybe you have a light of some sort?" << endl;
		}
		else if (buried) {
			cout << "\nThe meadow is to the west.\n The cave appears disappointingly empty, but the dirt looks to have been disturbed recently." << endl;
		}
	}
	else if (rName == "Barn" && Av->pLoc->roomInventory.size() != 0) {
		cout << "\nThe field is to the north.\n You see a lantern sitting on the barn floor and a ladder leading to the loft above you." << endl;
		Av->pLoc->getRoomItems();
	}
	else if (rName == "Barn Loft" && Av->pLoc->roomInventory.size() != 0) {
		cout << "\nThere is an old skeleton key hanging on the wall of the loft and a ladder leading down into the barn." << endl;
		Av->pLoc->getRoomItems();
	}
	else if (rName == "Kitchen" && Av->pLoc->roomInventory.size() != 0) {
		cout << "\nYou enter the kitchen.\n There is a mysterious potion on the table - the bottle has a picture of what appears to be a garden gnome on the front.\n The door leading outside is to the east and the living room is to the west." << endl;
		Av->pLoc->getRoomItems();
	}
	else if (rName == "Bedroom" && Av->pLoc->roomInventory.size() != 0) {
		cout << "\nThe hallway is to the east.\n There is a ukulele with a dragon design cut into the body laying on the bed in the bedroom and a trapdoor in the corner leading down to the basement.\n The ukulele looks normal, but every time you look away it seems to start glowing faintly..." << endl;
		Av->pLoc->getRoomItems();
	}
	else if (rName == "Basement" && Av->pLoc->roomInventory.size() != 0) {
		cout << "\nYou see stairs leading back up to the bedroom and a sturdy shovel leaning against the basement wall." << endl;
		Av->pLoc->getRoomItems();
	}
	else {
		Av->pLoc->pRoomDesc();
		Av->pLoc->getRoomItems();
	}
}