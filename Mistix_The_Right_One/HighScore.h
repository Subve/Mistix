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
#include <fstream>
class HighScore
{
private:
	sf::Text highscore_Text;
	
	sf::Font highscore_Font;
	std::ostringstream ssHighScore;
	int m_highscore;
public:
	HighScore();
	~HighScore();

	
	void updateHighScore(Score&obj);
	void renderHighscore(sf::RenderTarget &window);
	int getHighscore();
	int setHighscore(Score&obj);
	void loadHighscore();
	void saveHighScore(Score &obj);
	void showText();
	
	

};

