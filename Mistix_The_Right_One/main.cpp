
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Menu.h"
#include <cmath>
#include <math.h>

static const unsigned int VIEW_HEIGHT = 600.0f;
static const unsigned int VIEW_WIDTH = 800.0f;

inline double deg2rad(double degrees) {
	return degrees * 3,1429 / 360;
}
sf::Vector2f playerCenter;
sf::Vector2f mousePosWindow;
sf::Vector2f aimDir;
sf::Vector2f aimDirNorm;
class Player :public sf::Sprite
{
private:
	sf::Vector2i mouse;
	float angle;
	sf::Texture player_texture;
	sf::Vector2f player_startPosition=sf::Vector2f(300.0f,300.0f);
	sf::Vector2f player_position;
	sf::Vector2f bullet_startPos;
	

	
	
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
	void updateMousePos(sf::RenderWindow& window)
	{
		this->mouse = sf::Mouse::getPosition(window);
		this->player_position = this->getPosition();
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
		/*this->mouse = sf::Mouse::getPosition(window);
		this->player_position = this->getPosition();*/
		this->updateMousePos(window);
		angle = -atan2(mouse.x - player_position.x, mouse.y - player_position.y) * 180 / 3.14159;
		this->setRotation(angle+90);
	}
	
	
	void playerUpdate(sf::RenderWindow& window)
	{
		this->playerMove();
		this->playerRotate(window);
		
		
	}
};


class Bullet
{
private:


public:
	sf::CircleShape bullet;
	sf::Vector2f currVelocity;
	float maxSpeed;
	Bullet(float radius = 5.f) :currVelocity(0.f, 0.f), maxSpeed(15.f)
	{
		this->bullet.setRadius(radius);
		this->bullet.setFillColor(sf::Color::White);
		
	}
	
};



class StateMachine
{

};

int main()
{
	sf::Texture background;
	if (background.loadFromFile("tekstury/Background_Desert.png"))
	{
		std::cout << "Background texture successfully loaded\n";
	}
	background.setSmooth(true);
	sf::Sprite background_Sprite;
	background_Sprite.setTexture(background);
	//Creating player
	Player player;
	Bullet b1(5.f);
	std::vector<Bullet> bulets;
	bulets.push_back(Bullet(b1));
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
		playerCenter = sf::Vector2f(player.getPosition().x, player.getPosition().y);
		mousePosWindow = sf::Vector2f(sf::Mouse::getPosition(window));
		aimDir = mousePosWindow - playerCenter;
		aimDirNorm = aimDir/ (sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2)));
		

		/*std::cout << aimDirNorm.x << " " << aimDirNorm.y << std::endl;*/
		//Shooting
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			b1.bullet.setPosition(playerCenter);
			b1.currVelocity = aimDirNorm * b1.maxSpeed;

			bulets.push_back(Bullet(b1));
		}
		for (int i=0;i<bulets.size();i++)
		{
			bulets[i].bullet.move(bulets[i].currVelocity);
		}
		
		
		//Clear the window

		window.clear();
		window.draw(background_Sprite);
		//Draw current Frame
		

		window.draw(player);
		for (int i = 0;i < bulets.size();i++)
		{
			window.draw(bulets[i].bullet);
		}

		/*menu.draw(window);*/

		//Display everything

		window.display();

	}


	return 0;
}