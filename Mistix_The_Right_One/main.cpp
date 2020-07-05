
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

static const float VIEW_HEIGHT = 800.0f;
static const float VIEW_WIDTH = 800.0f;





int main()
{
	std::cout << "Nowe podejscie " << std::endl;
	sf::RenderWindow window(sf::VideoMode(VIEW_WIDTH,VIEW_HEIGHT), "Mistix", sf::Style::Close | sf::Style::Titlebar);

	while (window.isOpen())
	{
		sf::Event ev;
		while(window.pollEvent(ev))
			switch (ev.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		//Update the game



		//Clear the window

		window.clear(sf::Color::Magenta);

		//Draw current Frame



		//Display everything
		window.display();

	}


	return 0;
}