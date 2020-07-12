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
#include "Enemy.h"
#include  "BigEnemy.h"
class LittleEnemy :public Enemy
{
private:
	sf::Texture littleenemy_Texture;
	

public:
	LittleEnemy();
	virtual void Follow();
	virtual void Attack(Player& gracz,sf::Time &elapsed_time, sf::Time &delta_time);
	virtual void Rotate(sf::Vector2f& playerpos);
	virtual void adMove(sf::Vector2f& vektorRuchu);
	virtual void setDirection(sf::Vector2u& direction2);
	virtual void setMove(sf::Vector2f& playermove);
	virtual void killedZombie(Score& wynik, std::vector<Bullet>& pociski, std::vector<std::unique_ptr<Enemy>>& enemies);
	virtual void setTrafiony();
	virtual void setZabity();
	virtual void setID(int& i);
	
	
	sf::Vector2f playerCenter;
	sf::Vector2f mousePosWindow;
	sf::Vector2f aimDir;
	sf::Vector2f aimDirNorm;
	sf::Vector2u direction;
	float angle;
	int mobID;
	sf::Vector2f enemyPos;
	bool trafiony;
	bool ableToMove;
	bool zabity;
	bool polaczone;
	int HP;
	
	
};

