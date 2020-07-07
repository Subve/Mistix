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
#include "Player.h"
class Bullet
{
private:


public:
	sf::CircleShape bullet;
	sf::Vector2f currVelocity;
	float maxSpeed;
	int bulletTimer = 0;
	int maxbulletTimer;
	Bullet(float radius );
	//Setter
	void setAmmo(int n);
	void setSpeed(float n);

	sf::Vector2f playerCenter;
	sf::Vector2f mousePosWindow;
	sf::Vector2f aimDir;
	sf::Vector2f aimDirNorm;
};

