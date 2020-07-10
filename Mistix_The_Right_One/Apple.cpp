#include "Apple.h"
Apple::Apple()
{
	if (apple_texture.loadFromFile("tekstury/apple.png"))
	{
		std::cout << "Successfully loaded apple Texture \n";

	}


	apple_texture.setSmooth(true);
	this->setTexture(apple_texture);
	this->setScale(0.5f, 0.5f);
	
	
	
}

Apple::~Apple()
{
	
}

void Apple::addPlayerHP(Player& gracz)
{
	
}

