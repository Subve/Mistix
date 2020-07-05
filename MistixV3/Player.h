#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <ctime>
#include "Game.h"
class Player
{

public:
	Player() = default;
	Player(sf::Texture* texture);
	~Player();
	//Variables
	sf::Vector2f startPlayerPos;
	//Player 
	sf::RectangleShape body;

	//Init Player
	void initPlayer();
	void initPlayerVar();

	//Player Update
	void playerUpdate();

	//Player Render
	void playerRender();


};

