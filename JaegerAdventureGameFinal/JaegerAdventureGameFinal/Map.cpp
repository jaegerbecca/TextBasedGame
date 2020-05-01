#include "Map.h"

Map::~Map()
{
	delete mStart->pNorth;
	delete mStart->pEast;
	delete mStart->pSouth;
	delete mStart->pWest;
	delete mStart->pDown;
	delete mStart->pUp;
}

Map::Map()
{
	Room* p1 = new Room("Clearing", "You see a field to the east with a barn in the distance, a forest to the north, and a small brick house to the west.");
	mStart = p1;

	Room* p2 = new Room("Field", "You see the grassy clearing with grandpa's house to the west and an old barn to the south.");

	Room* p3 = new Room("Barn", "There are worn saddles and bridles hanging neatly on the barn wall, but no sign of the horses they belonged to.\n It smells faintly of hay and manure. The field is to the north.\n You see a ladder leading to the loft above you.");
	p3->setRoomItems("lantern");

	Room* p4 = new Room("Barn Loft", "There is an empty hook where the  key hung on the wall of the loft and a ladder leading down into the barn.");
	p4->setRoomItems("key");

	Room* p5 = new Room("Kitchen", "You enter the kitchen.\n Everything is organized and put away neatly, if a little dusty from lack of recent use.\n The door leading outside is to the east and the living room is to the west.");
	p5->setRoomItems("potion");

	Room* p6 = new Room("Living Room", "There is an old school TV set in the living room in front of a plaid couch.\n You see the kitchen to the east and a hallway to the north.");

	Room* p7 = new Room("Hallway", "You see the living room to the south, an attic door above you, and a bedroom to the west.");

	Room* p8 = new Room("Attic", "The only thing up here besides the ladder down to the hallway and the contents of the lockbox is dust.");
	p8->setRoomItems("map");

	Room* p9 = new Room("Bedroom", "The hallway is to the east.\n There is a full sized bed in the middle of the bedroom with a small nightstand next to it and a trapdoor in the corner leading down to the basement.\n The room seems unusually warm compared to the rest of the house.");
	p9->setRoomItems("ukulele");

	Room* p10 = new Room("Basement", "The basement's one dim light bulb buzzes faintly as it flickers in the damp air.\n You see stairs leading back up to the bedroom.");
	p10->setRoomItems("shovel");

	Room* p11 = new Room("Forest", "The clearing with grandpa's house is to the south and there's a narrow path through the forest to the north.");

	Room* p12 = new Room("Forest Path", "The forest entrance is to the south and a sunny meadow opens up to the north.");

	Room* p13 = new Room("Forest Meadow", "The forest path is south of the meadow.\n The dragon's cave is to the east.");

	Room* p14 = new Room("Cave", "The meadow is to the west.\n The cave seems a little cool and cramped for a dragon's den.");
	p14->setRoomItems("treasure");

	//clearing
	p1->pNorth = p11;
	p1->pEast = p2;
	p1->pSouth = 0;
	p1->pWest = p5;
	p1->pDown = 0;
	p1->pUp = 0;
	//field
	p2->pNorth = 0;
	p2->pEast = 0;
	p2->pSouth = p3;
	p2->pWest = p1;
	p2->pDown = 0;
	p2->pUp = 0;
	//barn
	p3->pNorth = p2;
	p3->pEast = 0;
	p3->pSouth = 0;
	p3->pWest = 0;
	p3->pUp = p4;
	p3->pDown = 0;
	//loft
	p4->pNorth = 0;
	p4->pEast = 0;
	p4->pSouth = 0;
	p4->pWest = 0;
	p4->pDown = p3;
	p4->pUp = 0;
	//kitchen
	p5->pNorth = 0;
	p5->pEast = p1;
	p5->pSouth = 0;
	p5->pWest = p6;
	p5->pDown = 0;
	p5->pUp = 0;
	//living room
	p6->pNorth = p7;
	p6->pEast = p5;
	p6->pSouth = 0;
	p6->pWest = 0;
	p6->pDown = 0;
	p6->pUp = 0;
	//hallway
	p7->pNorth = 0;
	p7->pEast = 0;
	p7->pSouth = p6;
	p7->pWest = p9;
	p7->pUp = p8;
	p7->pDown = 0;
	//attic
	p8->pNorth = 0;
	p8->pEast = 0;
	p8->pSouth = 0;
	p8->pWest = 0;
	p8->pDown = p7;
	p8->pUp = 0;
	//bedroom
	p9->pNorth = 0;
	p9->pEast = p7;
	p9->pSouth = 0;
	p9->pWest = 0;
	p9->pDown = p10;
	p9->pUp = 0;
	//basement
	p10->pNorth = 0;
	p10->pEast = 0;
	p10->pSouth = 0;
	p10->pWest = 0;
	p10->pUp = p9;
	p10->pDown = 0;
	//forest
	p11->pNorth = p12;
	p11->pEast = 0;
	p11->pSouth = p1;
	p11->pWest = 0;
	p11->pDown = 0;
	p11->pUp = 0;
	//path
	p12->pNorth = p13;
	p12->pEast = 0;
	p12->pSouth = p11;
	p12->pWest = 0;
	p12->pDown = 0;
	p12->pUp = 0;
	//meadow
	p13->pNorth = 0;
	p13->pEast = p14;
	p13->pSouth = p12;
	p13->pWest = 0;
	p13->pDown = 0;
	p13->pUp = 0;
	//cave
	p14->pNorth = 0;
	p14->pEast = 0;
	p14->pSouth = 0;
	p14->pWest = p13;
	p14->pDown = 0;
	p14->pUp = 0;
};