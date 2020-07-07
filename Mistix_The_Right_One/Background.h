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
class Background
{
private:
	sf::Texture background;
	sf::Sprite background_Sprite;
public:
	/*if (background.loadFromFile("tekstury/Background_Desert.png"))
	{
		std::cout << "Background texture successfully loaded\n";
	}
	background.setSmooth(true);
	sf::Sprite background_Sprite;
	background_Sprite.setTexture(background);*/
	Background();
	void initBackground();
	void LoadBackgroundTexture();
	void SetBackgroundSprite();
	void renderBackground(sf::RenderTarget& window);

};

