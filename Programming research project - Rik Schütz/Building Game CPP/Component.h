#pragma once

#include <SFML\Graphics.hpp>
#include <iostream>
#include "GameObject.h"

class GameObject;
class Component
{
public:
	virtual void Start(GameObject * gameObject);
	virtual void Update(sf::RenderWindow * renderWindow);
	virtual void OnDestroy();
	GameObject * gameObject;
};
