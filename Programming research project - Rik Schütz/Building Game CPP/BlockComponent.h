#pragma once
#include "Component.h"
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Player.h"

class BlockComponent : public Component
{
public:
	void Start(GameObject * gameObject);
	void Update(sf::RenderWindow * renderWindow);
	void OnDestroy();
};
