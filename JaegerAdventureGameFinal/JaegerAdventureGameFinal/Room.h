#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Room {
public:
	Room(string n, string desc);
	void pRoomName();
	string roomName();
	void pRoomDesc();
	void getRoomItems();
	void setRoomItems(string items);
	void takeRoomItems(string item);

	Room* pEast;
	Room* pWest;
	Room* pNorth;
	Room* pSouth;
	Room* pDown;
	Room* pUp;

	vector<string> roomInventory;

private:
	string rName;
	string rDesc;
};