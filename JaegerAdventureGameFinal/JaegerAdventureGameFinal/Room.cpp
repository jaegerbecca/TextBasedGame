#include "Room.h"

Room::Room(string n, string desc)
{
	rName = n;
	rDesc = desc;
}

void Room::setRoomItems(string items)
{
	roomInventory.push_back(items);
}

void Room::takeRoomItems(string item) {
	vector<string>::iterator trash = find(roomInventory.begin(), roomInventory.end(), item);
	roomInventory.erase(trash);
}

void Room::getRoomItems()
{

	vector<string>::iterator iter;


	if (roomInventory.size() != 0)
	{
		cout << "\nItems you can take: " << endl;
		for (iter = roomInventory.begin(); iter != roomInventory.end(); ++iter)
		{
			cout << *iter << endl;
		}
	}
	else
		cout << "\nThere are no items you can take here!" << endl;

}

void Room::pRoomName()
{
	cout << "Your location: " << rName << endl;
}

string Room::roomName() 
{
	return rName;
}

void Room::pRoomDesc()
{
	cout << rDesc << endl;
}