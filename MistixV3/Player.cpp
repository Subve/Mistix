#include "Player.h"
//Create Player

Player::Player(sf::Texture* texture)
{
	this->initPlayer();
	this->body.setTexture(texture);
	
}
Player::~Player()
{

}

//Initialize player
void Player::initPlayer()
{	
	this->body.setSize(sf::Vector2f(100.0f, 100.0f));
	this->body.setOrigin(body.getSize().x / 2, body.getSize().y / 2);
	
	this->body.setPosition(this->startPlayerPos);
}
void Player::initPlayerVar()
{
	this->startPlayerPos = sf::Vector2f(400.0f, 400.0f);
}
//Update the player state
void Player::playerUpdate()
{

}
//draw player
void Player::playerRender()
{
	
}
