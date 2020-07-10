#include "Player.h"

Player::Player()
{
	if (player_texture.loadFromFile("tekstury/Player1.png"))
	{

		std::cout << "Player1 texture loaded successfully! \n";
	}

	else
	{
		std::cout << "Player1 texture loaded FAILED!!!\n";
	}
	this->setTexture(player_texture);
	this->setPosition(player_startPosition);
	this->setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height / 2);
	this->scale(0.125f, 0.2f);
	this->m_playerHealth = 100;



}

void Player::playerMove()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		this->move(0.0f, -1.0f);
		
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		this->move(0.0f, 1.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->move(-1.0f, 0.0f);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->move(1.0f, 0.0f);
	}
}

void Player::updateMousePos(sf::RenderWindow& window)
{
	this->mouse = sf::Mouse::getPosition(window);
	this->player_position = this->getPosition();
}

void Player::playerRotate(sf::RenderWindow& window)
{
	/*window.convertCoords(mouse);

	//gets sprite origin coordinates and mouse coordinates
	this->spritePosition = sprite.getPosition();
	this->mouse = sf::Mouse::getPosition();

	mouseAngle = -atan2(mouse.x - spritePosition.x, mouse.y - spritePosition.y) * 180 / 3.14159; //angle in degrees of rotation for sprite

	playerSprite.setRotation(mouseAngle);*/
	window.mapPixelToCoords(mouse);
	/*this->mouse = sf::Mouse::getPosition(window);
	this->player_position = this->getPosition();*/
	this->updateMousePos(window);
	angle = static_cast<float>(-atan2(mouse.x - player_position.x, mouse.y - player_position.y) * 180 / 3.14159);
	this->setRotation(angle + 90);
}

void Player::playerUpdate(sf::RenderWindow& window)
{
	this->playerMove();
	this->playerRotate(window);


}
