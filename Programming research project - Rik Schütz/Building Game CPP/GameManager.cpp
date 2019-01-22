#include "GameManager.h"

//start of the game
void GameManager::StartGame()
{
	blockManager = new BlockManager();
	blockManager->GenerateTerrain(this);

	if (!font.loadFromFile("arial.ttf"))
	{
		std::cout << "Failed to load font!" << std::endl;
	}

	blockTypeText.setFont(font);
	blockTypeText.setString("Current Block Type:");
	blockTypeText.setCharacterSize(24);
	blockTypeText.setFillColor(sf::Color::Black);
	blockTypeText.setPosition(10, 10);

	infoText_1.setFont(font);
	infoText_1.setString("Press E to switch type");
	infoText_1.setCharacterSize(18);
	infoText_1.setFillColor(sf::Color::Black);
	infoText_1.setPosition(10, 40);

	infoText_2.setFont(font);
	infoText_2.setString("Left mouse to place blocks");
	infoText_2.setCharacterSize(18);
	infoText_2.setFillColor(sf::Color::Black);
	infoText_2.setPosition(10, 70);

	infoText_3.setFont(font);
	infoText_3.setString("Right mouse to remove blocks");
	infoText_3.setCharacterSize(18);
	infoText_3.setFillColor(sf::Color::Black);
	infoText_3.setPosition(10, 100);

	infoText_4.setFont(font);
	infoText_4.setString("Press right arrow to remove blocks");
	infoText_4.setCharacterSize(18);
	infoText_4.setFillColor(sf::Color::Black);
	infoText_4.setPosition(10, 130);

	previewObject = new GameObject(new Vector(235, 5, 0), Player::GetCurrentBlockType());
}

//updates all gameobjects in the scene
void GameManager::UpdateGame(sf::RenderWindow * _renderWindow)
{
	Player::Update();

	for (std::list<GameObject *>::iterator iter = gameObjects.begin(); iter != gameObjects.end(); iter++)
	{
		GameObject * gameObject = *iter;
		gameObject->Update(_renderWindow);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		ResetGame();

	_renderWindow->draw(blockTypeText);
	_renderWindow->draw(infoText_1);
	_renderWindow->draw(infoText_2);
	_renderWindow->draw(infoText_3);
	_renderWindow->draw(infoText_4);

	previewObject->SetTextureType(Player::GetCurrentBlockType());
	previewObject->Update(_renderWindow);
}

//adds gameobject to the scene
void GameManager::AddGameObject(GameObject * _gameObject)
{
	gameObjects.push_back(_gameObject);
	_gameObject->Start();
}

//makes a new map
void GameManager::ResetGame()
{
	for (std::list<GameObject *>::reverse_iterator revIter = gameObjects.rbegin(); revIter != gameObjects.rend(); revIter++)
	{
		GameObject * gameObject = *revIter;
		gameObject->OnDestroy();
	}

	gameObjects.clear();

	blockManager->GenerateTerrain(this);
}

//deletes everything from the game and memory
void GameManager::EndGame()
{
	for (std::list<GameObject *>::reverse_iterator revIter = gameObjects.rbegin(); revIter != gameObjects.rend(); revIter++)
	{
		GameObject * gameObject = *revIter;
		gameObject->OnDestroy();
	}

	gameObjects.clear();

	delete blockManager;
	delete this;
}