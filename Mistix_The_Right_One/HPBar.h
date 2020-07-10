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
#include  "AppleManager.h"

class HPBar
{
private:
	
public:
	HPBar();
	sf::Font bh_font;
	sf::Text hpBarText;
	
	float hpBarMax;
	std::ostringstream hpBarString;
	sf::RectangleShape hpBarBack;
	sf::RectangleShape hpBarFront;
	
	void inithpbartext(Player&gracz);
	void initHPBAR(Player& gracz);
	void inithpbarback();
	void inithpbarfront();
	void UpdateHP(Player& gracz);
	void RenderHPBar(sf::RenderTarget& window1);
	
	
	
};

