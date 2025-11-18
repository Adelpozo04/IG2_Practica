#pragma once
#include <vector>
#include <utility>
class Bomb;
class BombsManager
{
public:
	BombsManager();
	bool canPutABomb() { return nBombs < maxBombs; }
private:
	unsigned int maxBombs;
	unsigned int nBombs;
	std::vector<std::pair<Bomb*,bool>> bombVector;
};