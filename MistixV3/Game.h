#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

//Class that acts as the game engine

class Game
{
private:
	//Variables

	//Window
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videMode;

	//Game objects
	sf::RectangleShape enemy;



	//Private functions
	void initVariables();
	void initWindow();
	void initEnemies();




public:
	//Constructor //Destructor
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;

	//Functions
	void pollEvents();
	void update();
	void render();
};

