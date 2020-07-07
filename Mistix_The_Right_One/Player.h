#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Menu.h"
#include <cmath>
#include <math.h>
#include <memory>
#include <sstream>
#include "Score.h"
class Player :public sf::Sprite
{
private:
	sf::Vector2i mouse;
	float angle;
	sf::Texture player_texture;
	sf::Vector2f player_startPosition = sf::Vector2f(300.0f, 300.0f);
	sf::Vector2f player_position;
	sf::Vector2f bullet_startPos;




public:

	Player();
	void playerMove();
	void updateMousePos(sf::RenderWindow& window);
	void playerRotate(sf::RenderWindow& window);



	void playerUpdate(sf::RenderWindow& window);
	sf::Vector2f playerCenter;
	sf::Vector2f mousePosWindow;
	sf::Vector2f aimDir;
	sf::Vector2f aimDirNorm;
};

