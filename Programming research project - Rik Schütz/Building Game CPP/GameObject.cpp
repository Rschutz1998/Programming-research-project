#include "GameObject.h"

//gameobject constructor
GameObject::GameObject(Vector * _position, BlockTypeEnum type)
{
	position = _position;

	if (!grassTexture->loadFromFile("GrassBlock.png")) { std::cout << "Failed to load file" << std::endl; }
	if (!dirtTexture->loadFromFile("DirtBlock.png")) { std::cout << "Failed to load file" << std::endl; }
	if (!stoneTexture->loadFromFile("StoneBlock.png")) { std::cout << "Failed to load file" << std::endl; }
	if (!woodTexture->loadFromFile("WoodBlock.png")) { std::cout << "Failed to load file" << std::endl; }
	if (!skyTexture->loadFromFile("SkyBlock.png")) { std::cout << "Failed to load file" << std::endl; }

	SetTextureType(type);
}

//start is called from the gamemanager once.s
void GameObject::Start()
{
	for (std::list<Component *>::iterator iter = components.begin(); iter != components.end(); iter++)
	{
		Component * component = *iter;
		component->Start(this);
	}
}

//update is called from the gamemanager every frame.
void GameObject::Update(sf::RenderWindow * _renderWindow)
{
	sprite->setPosition(position->x, position->y);
	_renderWindow->draw(*sprite);

	for (std::list<Component *>::iterator iter = components.begin(); iter != components.end(); iter++)
	{
		Component * component = *iter;
		component->Update(_renderWindow);
	}
}

//destroys the gameobject
void GameObject::OnDestroy()
{
	for (std::list<Component *>::reverse_iterator revIter = components.rbegin(); revIter != components.rend(); revIter++)
	{
		Component * component = *revIter;
		component->OnDestroy();
	}

	components.clear();

	delete sprite;
	delete dirtTexture;
	delete grassTexture;
	delete stoneTexture;
	delete skyTexture;
	delete woodTexture;
	delete position;
	delete this;
}

void GameObject::AddComponent(Component * component)
{
	component->Start(this);
	components.push_back(component);
}

void GameObject::SetTextureType(BlockTypeEnum type)
{
	sf::Texture * texture = new sf::Texture();

	switch (type)
	{
	case grassBlock:
		texture = grassTexture;
		break;
	case dirtBlock:
		texture = dirtTexture;
		break;
	case stoneBlock:
		texture = stoneTexture;
		break;
	case skyBlock:
		texture = skyTexture;
		break;
	}

	sprite->setTexture(*texture);
}