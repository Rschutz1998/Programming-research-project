#include "BlockComponent.h"

void BlockComponent::Start(GameObject * gameObject)
{
	this->gameObject = gameObject;
}

void BlockComponent::Update(sf::RenderWindow * renderWindow)
{
	if (sf::Mouse::getPosition(*renderWindow).x > gameObject->position->x
		&& sf::Mouse::getPosition(*renderWindow).x < gameObject->position->x + 50
		&& sf::Mouse::getPosition(*renderWindow).y < gameObject->position->y + 50
		&& sf::Mouse::getPosition(*renderWindow).y > gameObject->position->y)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			gameObject->SetTextureType(Player::GetCurrentBlockType());
		else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			gameObject->SetTextureType(skyBlock);
	}
}

void BlockComponent::OnDestroy()
{
	delete this;
}