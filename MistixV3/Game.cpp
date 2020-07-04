#include "Game.h"
//Private Functions
void Game::initVariables()
{
	this->window = nullptr;
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

void Game::update()
{
	this->pollEvents();

	//Update Mouse position
	//Relative to the screen
	/*std::cout << "Mouse pos: " << sf::Mouse::getPosition().x << " "
		<< sf::Mouse::getPosition().y << std::endl;*/
	//Relative to the window
	std::cout << "Mouse pos: " << sf::Mouse::getPosition(*this->window).x << " "
		<< sf::Mouse::getPosition(*this->window).y << std::endl;
	
}

void Game::render()
{
	this->window->clear(sf::Color::Cyan);

	//draw game objects
	this->window->draw(this->enemy);


	this->window->display();
}
