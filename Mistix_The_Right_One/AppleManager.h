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
#include "Button.h"
#include "Apple.h"
class AppleManager
{
public:
	AppleManager();

	void SpawnApple(std::vector<std::unique_ptr<Apple>>& jablka,sf::Time&elapsed_jablka, sf::Time&delta_jablka);
	void RenderApples(sf::RenderTarget& window, std::vector<std::unique_ptr<Apple>>& jablka);
	
	
	
};

