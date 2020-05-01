#include "Map.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Player : public Map
{
public:
	Player();
	Room* pLoc;

	vector<string> inventory;

	void getInventory();
	void useItems(string item);
};
