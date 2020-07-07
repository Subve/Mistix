#include "Background.h"

Background::Background()
{
	this->initBackground();
}

void Background::initBackground()
{
	this->LoadBackgroundTexture();
	this->SetBackgroundSprite();
}

void Background::LoadBackgroundTexture()
{
	this->background.loadFromFile("tekstury/Background_Desert.png");
	if (this->background.loadFromFile("tekstury/Background_Desert.png"))
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
