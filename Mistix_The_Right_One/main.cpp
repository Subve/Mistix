
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

static const unsigned int VIEW_HEIGHT = 800.0f;
static const unsigned int VIEW_WIDTH = 800.0f;

class Player :public sf::Sprite
{
private:
	sf::Texture player_texture;
	sf::Vector2f player_startPosition=sf::Vector2f(300.0f,300.0f);
public:
	Player() 
	{
		if(player_texture.loadFromFile("tekstury/Player1.png"))
		{

			std::cout << "Player1 texture loaded successfully! \n";
		}

		else
		{
			std::cout << "Player1 texture loaded FAILED!!!\n";
		}
		this->setTexture(player_texture);
		this->setPosition(player_startPosition);
		this->scale(0.125f,0.2f);
		
	};
	void playerMove()
	{

	}
};



int main()
{
	//Creating player
	Player player;
	
	//Creating window
	sf::RenderWindow window(sf::VideoMode(VIEW_WIDTH,VIEW_HEIGHT), "Mistix", sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(144);


	//Timer
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
		window.draw(player);


		//Display everything
		window.display();

	}


	return 0;
}