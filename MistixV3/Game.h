#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <ctime>
#include "Player.h"
//Class that acts as the game engine
class Player;
class Game
{
private:
	
public:
	//Variables
	
	//Window
	sf::RenderWindow* window;
	sf::Event ev;
	sf::VideoMode videMode;

	//Mouse Positions
	sf::Vector2i mousePosWindow;
	sf::Vector2f mousePosView;

	//Game logic
	int points;
	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;


	//Game objects
	sf::RectangleShape enemy;
	
	sf::Texture playerTexture;
	
	
	std::vector<sf::RectangleShape> enemies;
	

	//Private functions
	void initVariables();
	void initWindow();
	void initEnemies();
	void initPlayer();




public:
	//Constructor //Destructor
	Game();
	virtual ~Game();

	//Accessors
	const bool running() const;
	std::vector<std::unique_ptr<Player>> players1;
	//Functions
	void pollEvents();
	void spawnEnemy();
	void updateMousePosition();
	void updateEnemies();
	void update();
	void renderEnemies();
	void renderPlayer();
	void render();
};



