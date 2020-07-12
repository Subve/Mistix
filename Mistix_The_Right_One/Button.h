#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "EntityManager.h"
#include "Menu.h"
#include <cmath>
#include <math.h>
#include <memory>
#include <sstream>
#include "Score.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "LittleEnemy.h"
#include "CustomMouse.h"
#include "Background.h"
#include "HighScore.h"
class Button
{
private:
	sf::Sprite button_sprite;
	sf::Texture	button_texture;
public:
	Button();
	~Button();
	bool isClicked(sf::RenderWindow& window,Score&wynik);
	void UpgradeBulletSpeed(Bullet&pocisk, Score& wynik);
	void RenderUpgradeButton(sf::RenderTarget& window, Score& wynik, Bullet& pocisk);
	int UpgradeCost = 20;
};

