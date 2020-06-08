#include <iostream>
#include <SFML/Graphics.hpp>
#include "Animation.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 512), "Mistix", sf::Style::Close | sf::Style::Resize);
	
	sf::RectangleShape player(sf::Vector2f(100.0f, 150.0f));
	player.setPosition(206.0f, 206.0f);
	sf::Texture playerTexture;
	playerTexture.loadFromFile("tux_from_linux.png");
	player.setTexture(&playerTexture);

	Animation animation(&playerTexture,sf::Vector2u(3,9),0.3f);

	float deltaTime = 0.0f;
	sf::Clock clock;

	while (window.isOpen())
	{
		deltaTime=clock.restart().asSeconds();

		sf::Event e;
		while (window.pollEvent(e))
		{	switch(e.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			
				
			}
			
		}
		
		animation.Update(0, deltaTime);
		player.setTextureRect(animation.uvRect);

		window.clear();

		window.draw(player);
		window.display();

	}
	


	return 0;
}
