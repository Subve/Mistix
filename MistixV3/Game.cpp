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
	this->window= new sf::RenderWindow(this->videMode, "Mistix", sf::Style::Titlebar | sf::Style::Close);
	
}
//Constructors					//Destructors
Game::Game()
{

}

Game::~Game()
{

}
//Functions
void Game::update()
{

}

void Game::render()
{

}
