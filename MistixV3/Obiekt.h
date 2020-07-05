#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <ctime>
class Obiekt :
	public sf::Sprite
{
public:
	Obiekt() :Sprite() {};
	virtual ~Obiekt() = default;
	virtual void Ruszaj(float speed_x, float speed_y) = 0;
};

