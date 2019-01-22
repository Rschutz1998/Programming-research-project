#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>
#include "Vector.h"
#include "GameManager.h"
#include "BlockComponent.h"
#include "GameManager.h"

class GameManager;

class BlockManager {

private:
	int terrain_MaxHeight;
	int terrain_MaxDifference;
	int terrain_MinDifference;

	int GetRandomInt(int min, int max);
	int getRandomYDirection();

public:
	BlockManager();
	void GenerateTerrain(GameManager * _gameManager);
};
