#include "Background.h"

Background::Background(const std::string& filename)
{
	this->initBackground(filename);
}

void Background::initBackground(const std::string& filename)
{
	this->LoadBackgroundTexture(filename);
	this->SetBackgroundSprite();
}

void Background::LoadBackgroundTexture(const std::string& filename)
{
	this->background.loadFromFile(filename);
	if (this->background.loadFromFile(filename))
	{
		std::cout << "Background texture successfully loaded\n";
	}
	else
	{
		std::cout << "Background failed to LOAD \n";
	}
	this->background.setSmooth(true);

}

void Background::SetBackgroundSprite()
{
	this->background_Sprite.setTexture(this->background);
}

void Background::renderBackground(sf::RenderTarget& window)
{
	window.draw(this->background_Sprite);
}
