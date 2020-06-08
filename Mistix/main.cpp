#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(512, 512), "Mistix", sf::Style::Close | sf::Style::Resize);
	while (window.isOpen())
	{
		sf::Event e;
		while (window.pollEvent(e))
		{	switch(e.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				std::cout <<"New window width "<< e.size.width <<" New window height "<<e.size.height << std::endl;
				break;
			}
			
		}

	}



	return 0;
}
