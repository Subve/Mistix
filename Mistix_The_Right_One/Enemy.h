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
#include "Bullet.h"
class Enemy :public sf::Sprite
{

private:

public:

	Enemy() :Sprite() {}
		;
	virtual ~Enemy() = default;
	virtual void Follow() = 0;
	virtual void Attack(Player& gracz) = 0;
	virtual void Rotate(sf::Vector2f& playermove) = 0;
	virtual void adMove(sf::Vector2f& vektorRuchu) = 0;
	virtual void setDirection(sf::Vector2u& direction2) = 0;
	virtual void setMove(sf::Vector2f& playermove) = 0;
	virtual void killedZombie(Score& wynik, std::vector<Bullet>& pociski, std::vector<std::unique_ptr<Enemy>>& enemies) = 0;
	virtual void setTrafiony() = 0;
	virtual void setZabity() = 0;
	float angle;
	sf::Vector2u direction;
	sf::Vector2f playerCenter;
	sf::Vector2f mousePosWindow;
	sf::Vector2f aimDir;
	sf::Vector2f aimDirNorm;
	sf::Vector2f enemyPos;
	bool trafiony;
	bool zabity;
	int HP;

};

