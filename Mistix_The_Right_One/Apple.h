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
class Apple:public sf::Sprite
{
private:
	
	
public:
	Apple();
	~Apple();
	
	void addPlayerHP(Player& gracz);
	void renderApple(sf::RenderTarget&window);
	
	

	bool eaten;
	
	sf::Texture apple_texture;
	sf::Sprite apple_sprite;
};

