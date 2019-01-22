#include "Player.h"

int Player::currentBlockIndex = 0;
bool Player::canSwitch = true;

void Player::Update()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && canSwitch == true)
	{
		Player::currentBlockIndex = (Player::currentBlockIndex + 1 > skyBlock - 1) ? 0 : Player::currentBlockIndex + 1;
		canSwitch = false;
	}

	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		canSwitch = true;
}

BlockTypeEnum Player::GetCurrentBlockType()
{
	return (BlockTypeEnum)Player::currentBlockIndex;
}