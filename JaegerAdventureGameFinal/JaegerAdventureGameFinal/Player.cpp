#include "Player.h"


Player::Player()
{
	pLoc = mStart;
}

void Player::getInventory()
{
	vector<string>::iterator iter;

	if (inventory.size() != 0)
	{
		cout << "\nYou have the following items: " << endl;
		for (iter = inventory.begin(); iter != inventory.end(); ++iter)
		{
			cout << *iter << endl;
		}
	}
	else
		cout << "\nYou are not currently holding any items!" << endl;
}

void Player::useItems(string item) {
	vector<string>::iterator trash = find(inventory.begin(), inventory.end(), item);
	inventory.erase(trash);
}