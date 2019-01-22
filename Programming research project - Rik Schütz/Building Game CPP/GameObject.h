#pragma once

#include "Vector.h"
#include <list>
#include <SFML\Graphics.hpp>
#include "Component.h"

enum BlockTypeEnum
{
	grassBlock = 0,
	dirtBlock,
	stoneBlock,
	skyBlock
};

class Component;

class GameObject {

private:
	sf::Sprite * sprite = new sf::Sprite();
	std::list<Component *> components;

	sf::Texture * grassTexture = new sf::Texture();
	sf::Texture * dirtTexture = new sf::Texture();
	sf::Texture * stoneTexture = new sf::Texture();
	sf::Texture * woodTexture = new sf::Texture();
	sf::Texture * skyTexture = new sf::Texture();

public:
	GameObject(Vector * _position, BlockTypeEnum type);
	Vector * position;
	void Start();
	void Update(sf::RenderWindow * _renderWindow);
	void OnDestroy();
	void AddComponent(Component * component);
	void SetTextureType(BlockTypeEnum type);
};
