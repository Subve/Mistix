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
class Score
{
private:
	sf::Text score_Text;
	int value;
	sf::Font score_Font;
	std::ostringstream ssScore;
	int m_addValue;
public:
	Score();
		
	
	void updateText();
	void setValue(int n);
	void pointsRender(sf::RenderWindow& window);
	int getScore();
	void setaddPoint(float n);

	void addPoints();
};

