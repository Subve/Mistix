#include "Game.h"
//Private Functions
void Game::initVariables()
{
	this->window = nullptr;

	//Game logic
	this->points = 0;
	this->enemySpawnTimerMax = 10.0f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	
	this->maxEnemies = 5;
}

void Game::initWindow()
{
	this->videMode.height = 600;
	this->videMode.width = 800;
	
	this->window= new sf::RenderWindow(this->videMode, "Mistix",
		sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
	
}
void Game::initEnemies()
{
	this->enemy.setSize(sf::Vector2f(100.0f, 100.0f));
	this->enemy.setScale(sf::Vector2f(0.5f,0.5f));
	this->enemy.setFillColor(sf::Color::Blue);
	this->enemy.setOutlineColor(sf::Color::Green);
	this->enemy.setOutlineThickness(1.0f);
}
//Constructors					//Destructors
Game::Game()
{
	this->initVariables();
	this->initWindow();
	this->initEnemies();
	
}

Game::~Game()
{
	delete this->window;
}

//Accessors
const bool Game::running() const
{
	return this->window->isOpen();
}

//Functions

void Game::pollEvents()
{
	//Event polling
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (ev.key.code == sf::Keyboard::Escape)
			this->window->close();
			break;
		}
	}
}

void Game::spawnEnemy()
{
	/*
	Spawns enemies and sets their color and positions
	set a random position
	set a random color
	adds enemy to the vector
	*/
	this->enemy.setPosition(
		static_cast<float>(rand()%static_cast<int>(this->window->getSize().x-this->enemy.getSize().x)),
		0.0f
	);
	this->enemy.setFillColor(sf::Color::Green);
	
	//spawns the enemy
	this->enemies.push_back(this->enemy);
}

void Game::updateMousePosition()
{
		/*
	return void
	updates the mouse position
	mouse position relative to winow(vector 2i)
		*/
	this->mousePosWindow = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

void Game::updateEnemies()
	/*
	Return void 
	updates the enemy spawn timer and spawns enemies when the total amount
	of enemies is smaller than max
	moves the enemies downwards
	*/
{	//Updating the timer for enemy spawnining
	if(this->enemies.size()<this->maxEnemies)
	{
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
		{	//spawn the enemy and reset the timer
			this->spawnEnemy();
			this->enemySpawnTimer = 0.0f;
		}
		else
		{
			this->enemySpawnTimer += 1.0f;
		}
	}
	//move the enemies
	for (int i=0;i<this->enemies.size();i++)
	{
		this->enemies[i].move(0.0f, 5.0f);
	}
}

void Game::update()
{
	this->pollEvents();

	this->updateMousePosition();
	
	this->updateEnemies();
	
}

void Game::renderEnemies()
{	//rendering all the enemies
	for (auto& e : enemies)
	{
		this->window->draw(e);
	}
}

void Game::render()
{
	this->window->clear(sf::Color::Cyan);

	//draw game objects
	this->window->draw(this->enemy);
	this->renderEnemies();

	this->window->display();
}
