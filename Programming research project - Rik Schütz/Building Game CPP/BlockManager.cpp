#include "BlockManager.h"

//constructor of the blockmanager
BlockManager::BlockManager()
{
	terrain_MaxHeight = 8;
	terrain_MaxDifference = 2;
}

//generates a new terrain
void BlockManager::GenerateTerrain(GameManager * _gameManager)
{
	// initialize random seed:
	srand(time(NULL));

	int prevHeight = 0;

	for (int x = 0; x < 26; x++)
	{
		//get a random height for this iteration.
		int currentHeight = (x <= 0) ? GetRandomInt(3, terrain_MaxHeight) : prevHeight + (getRandomYDirection() * GetRandomInt(terrain_MinDifference, terrain_MaxDifference));
		currentHeight = (currentHeight > terrain_MaxHeight) ? terrain_MaxHeight : currentHeight;
		currentHeight = (currentHeight < 1) ? 1 : currentHeight;

		//loop from start to height and place blocks with the right texture
		for (int height = 0; height < 15; height++)
		{
			BlockTypeEnum blockType = skyBlock;

			if (height < currentHeight)
			{
				if (height == (currentHeight - 1))
					blockType = grassBlock;
				else if (height < (currentHeight - 1) && height >= currentHeight - 3)
					blockType = dirtBlock;
				else if (height < currentHeight - 3)
					blockType = stoneBlock;
			}

			GameObject * newBlock = new GameObject(new Vector(0 + (x * 50), 670 - (height * 50), 0), blockType);
			newBlock->AddComponent(new BlockComponent());
			_gameManager->AddGameObject(newBlock);
		}

		//set the previous height to the last iterated height
		prevHeight = currentHeight;
	}
}

//returns a random int
int BlockManager::GetRandomInt(int min, int max)
{
	min = (min < 1) ? 1 : min;
	return rand() % max + min;
}

//returns a random direction int
int BlockManager::getRandomYDirection()
{
	int randomDir = rand() % 2 + 1;
	int dir = (randomDir == 1) ? -1 : 1;
	return dir;
}