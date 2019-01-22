#include <SFML\Graphics.hpp>
#include "GameManager.h"

int main()
{
	sf::RenderWindow * window = new sf::RenderWindow(sf::VideoMode(1280, 720), "BUILDING GAME");

	GameManager * gameManager = new GameManager();
	gameManager->StartGame();

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

		window->clear();

		gameManager->UpdateGame(window);

		window->display();
	}

	gameManager->EndGame();

	return 0;
}