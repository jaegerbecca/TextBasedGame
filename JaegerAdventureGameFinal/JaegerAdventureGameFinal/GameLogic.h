#include "Player.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class GameLogic {
public:
	string GetAction();
	bool HandleAction(string choice, Player* Av, bool& f1, bool& f2, bool& f3, bool& f4, bool& f5);
	void Events(Player* Av, bool flag1, bool flag2, bool flag3, bool flag4, bool flag5);
};