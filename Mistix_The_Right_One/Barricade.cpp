#include "Barricade.h"

Barricade::Barricade()
{
	if (barricade_texture.loadFromFile("tekstury/Barricade.png"))
	{
		std::cout << "Successfully loaded barricade Texture \n";

	}


	barricade_texture.setSmooth(true);
	this->setTexture(barricade_texture);
	
	this->setScale(0.05f, 0.05f);
}

Barricade::~Barricade()
{
	
}


