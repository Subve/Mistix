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

class CustomMouse
{
private:
	


public:

	CustomMouse();

	void mouseUpdate();
	void mouseRender(sf::RenderWindow& window);
	
	sf::Texture m_mouseTexture;
	sf::Sprite m_mouseSprite;
	sf::Vector2f playerCenter;
	sf::Vector2f mousePosWindow;
	sf::Vector2f aimDir;
	sf::Vector2f aimDirNorm;
};

