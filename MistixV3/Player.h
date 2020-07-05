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
	Player(sf::Texture* texture);
	virtual ~Player() = 0;

	//Player 
	sf::RectangleShape body;

	//Init Player
	void initPlayer();

	//Player Update
	void playerUpdate();

	//Player Render
	void playerRender(sf::RenderWindow&window);


};

