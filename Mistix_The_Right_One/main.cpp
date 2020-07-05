
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Menu.h"

static const unsigned int VIEW_HEIGHT = 800.0f;
static const unsigned int VIEW_WIDTH = 800.0f;

class Player :public sf::Sprite
{
private:
	sf::Vector2i mouse;
	float angle;
	sf::Texture player_texture;
	sf::Vector2f player_startPosition=sf::Vector2f(300.0f,300.0f);
	sf::Vector2f player_position;
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
		this->setOrigin(this->getGlobalBounds().width / 2, this->getGlobalBounds().height / 2);
		this->scale(0.125f,0.2f);
		
		
		
	};
	void playerMove()
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			this->move(0.0f, -1.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			this->move(0.0f, 1.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			this->move(-1.0f, 0.0f);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			this->move(1.0f, 0.0f);
		}
	}
	void playerRotate(sf::RenderWindow &window)
	{
		/*window.convertCoords(mouse);

		//gets sprite origin coordinates and mouse coordinates
		this->spritePosition = sprite.getPosition();
		this->mouse = sf::Mouse::getPosition();

		mouseAngle = -atan2(mouse.x - spritePosition.x, mouse.y - spritePosition.y) * 180 / 3.14159; //angle in degrees of rotation for sprite

		playerSprite.setRotation(mouseAngle);*/
		window.mapPixelToCoords(mouse);
		this->mouse = sf::Mouse::getPosition(window);
		this->player_position = this->getPosition();
		angle = -atan2(mouse.x - player_position.x, mouse.y - player_position.y) * 180 / 3.14159;
		this->setRotation(angle+90);
	}
	void playerShot(sf::RenderWindow& window)
	{

	}
	void playerUpdate(sf::RenderWindow& window)
	{
		this->playerMove();
		this->playerRotate(window);
	}
};

class StateMachine
{

};

int main()
{
	//Creating player
	Player player;
	
	
	//Creating window
	sf::RenderWindow window(sf::VideoMode(VIEW_WIDTH,VIEW_HEIGHT), "Mistix", sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(144);
	/*Menu menu(VIEW_WIDTH, VIEW_HEIGHT);*/
	
	

	//Timer
	while (window.isOpen())
	{
		
		sf::Event ev;
		while(window.pollEvent(ev))
			switch (ev.type)
			{	
			//MENU Option switch
			/*case sf::Event::KeyPressed:
			{	switch (ev.key.code)
			{
			case sf::Keyboard::Up:
					menu.MoveUp();
					break;
			case sf::Keyboard::Down:
					menu.MoveDown();
					break;
			case sf::Keyboard::Return:
				switch (menu.GetPressedItem())
				{
				case 0:
					std::cout << "Play button has been pressed\n";
					
					break;
				case 1:
				{
					std::cout << "Option button has been pressed\n";
					

					break;
				}
				case 2:
					std::cout << "Quit button has been pressed\n";
					window.close();
					
					break;

				default:
					break;
				}
			}
				
				break;
			}*/
			


				//Closing the window
			case sf::Event::Closed:
				window.close();
				break;
			}
		//Update the game
		
		player.playerUpdate(window);

		//Clear the window

		window.clear(sf::Color::Magenta);
		
		//Draw current Frame


		window.draw(player);

		/*menu.draw(window);*/

		//Display everything

		window.display();

	}


	return 0;
}