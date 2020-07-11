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
#include "HPBar.h"
#include "OptionsMenu.h"
#include "OptionsMenuSelect.h"
#include <fstream>
class Barricade:public sf::Sprite
{
private:

public:
	Barricade();
	~Barricade();

	

	bool used;
	bool used_kill;
	

	sf::Texture barricade_texture;
	sf::Sprite barricade_sprite;
};

