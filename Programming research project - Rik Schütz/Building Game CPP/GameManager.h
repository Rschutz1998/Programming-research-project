#pragma once
#include <list>
#include <SFML\Graphics.hpp>
#include "BlockManager.h"
#include "GameObject.h"
#include "Player.h"

class GameObject;
class BlockManager;

class GameManager 
{

private:
	std::list<GameObject *> gameObjects;

	BlockManager * blockManager;

	sf::Text blockTypeText;

	sf::Text infoText_1;
	sf::Text infoText_2;
	sf::Text infoText_3;
	sf::Text infoText_4;

	sf::Font font;

	GameObject * previewObject;

	void ResetGame();

public:
	void StartGame();
	void UpdateGame(sf::RenderWindow * _renderWindow);
	void EndGame();
	void AddGameObject(GameObject * _gameObject);
};
