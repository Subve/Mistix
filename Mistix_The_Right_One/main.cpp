
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "Menu.h"
#include <cmath>
#include <math.h>
#include <memory>
#include <sstream>

#define VIEW_HEIGHT 600

#define  VIEW_WIDTH 800

inline double deg2rad(double degrees) {
	return degrees * 3,1429 / 360;
}


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
	sf::Vector2f playerCenter;
	sf::Vector2f mousePosWindow;
	sf::Vector2f aimDir;
	sf::Vector2f aimDirNorm;
};


class Bullet
{
private:


public:
	sf::CircleShape bullet;
	sf::Vector2f currVelocity;
	float maxSpeed;
	int bulletTimer=0;
	int maxbulletTimer;
	Bullet(float radius = 5.f) :currVelocity(0.f, 0.f), maxSpeed(15.f)
	{
		this->bullet.setRadius(radius);
		this->bullet.setFillColor(sf::Color::White);
		
	}
	//Setter
	void setAmmo(int n)
	{
		maxbulletTimer = n;
	};
	void setSpeed(float n)
	{
		maxSpeed = n;
	}
	sf::Vector2f playerCenter;
	sf::Vector2f mousePosWindow;
	sf::Vector2f aimDir;
	sf::Vector2f aimDirNorm;
};
class Enemy:public sf::Sprite
{

private:

public:

	Enemy():Sprite() {};
	virtual ~Enemy() = default;
	virtual void Follow() = 0;
	virtual void Attack() = 0;
	virtual void Rotate() = 0;
	virtual void adMove(sf::Vector2f&vektorRuchu) = 0;
	virtual void setDirection(sf::Vector2u& direction2) = 0;
	virtual void setMove(sf::Vector2f& playermove) = 0;
	
	sf::Vector2u direction;
	sf::Vector2f playerCenter;
	sf::Vector2f mousePosWindow;
	sf::Vector2f aimDir;
	sf::Vector2f aimDirNorm;
	
};

class LittleEnemy :public Enemy
{
private:
	sf::Texture littleenemy_Texture;

public:
	LittleEnemy() :Enemy() {

		if (littleenemy_Texture.loadFromFile("tekstury/Zombie_Szablon.png"))
		{
			std::cout<<"Successfully loaded LittleEnemy Texture \n";

		}
		littleenemy_Texture.setRepeated(true);
		this->setTexture(littleenemy_Texture);
		this->setScale(sf::Vector2f(0.1f, 0.15f));
		


	};
	virtual void Follow() {};
	virtual void Attack() {};
	virtual void Rotate() 
	{
	
	};
	virtual void adMove(sf::Vector2f &vektorRuchu)
	{
		this->move(-1*vektorRuchu.x,-1*vektorRuchu.y);
	}
	virtual void setDirection(sf::Vector2u &direction2)
	{
		direction.x = -1 *  direction2.x;
		direction.y = -1 * direction2.y;
	}
	virtual void setMove(sf::Vector2f& playermove)
	{
		this->playerCenter = playermove;
		this->mousePosWindow = this->getPosition();
		this->aimDir =
			this->mousePosWindow - this->playerCenter;
		this->aimDirNorm = this->
			aimDir / (sqrt(pow(this->aimDir.x, 2) + pow(this->aimDir.y, 2)));
		/*enemies[i]->move(-1*(enemies[i]->aimDirNorm.x),-1*(enemies[i]->aimDirNorm.y));*/
		this->adMove(this->aimDirNorm);
	}
	sf::Vector2f playerCenter;
	sf::Vector2f mousePosWindow;
	sf::Vector2f aimDir;
	sf::Vector2f aimDirNorm;
	sf::Vector2u direction;
};
class CustomMouse
{
	public:
	sf::Texture m_mouseTexture;
	sf::Sprite m_mouseSprite;
	sf::Vector2f playerCenter;
	sf::Vector2f mousePosWindow;
	sf::Vector2f aimDir;
	sf::Vector2f aimDirNorm;
	
	
public:
	
	CustomMouse(){
		m_mouseTexture.loadFromFile("tekstury/Aim.png");
	  if(m_mouseTexture.loadFromFile("tekstury/Aim.png"))
		{
			std::cout << "Successfully loaded Cursor Texture \n";

		}
		m_mouseTexture.setRepeated(true);
		this->m_mouseSprite.setTexture(m_mouseTexture);
		this->m_mouseSprite.setOrigin(this->m_mouseSprite.getGlobalBounds().width / 2, this->m_mouseSprite.getGlobalBounds().height / 2);
		this->m_mouseSprite.setScale(0.125f,0.125f);
		this->m_mouseSprite.setPosition(mousePosWindow.x, mousePosWindow.y);
	}
	
	void mouseUpdate()
	{
		this->m_mouseSprite.setPosition(mousePosWindow.x, mousePosWindow.y);
	}
	void mouseRender(sf::RenderWindow& window)
	{
		window.draw(this->m_mouseSprite);
	}

};
class Score
{
private:
	sf::Text score_Text;
	int value;
	sf::Font score_Font;
	std::ostringstream ssScore;
	int m_addValue;
public:
	Score()
	{
		score_Font.loadFromFile("fonts/arial.ttf");
		if (score_Font.loadFromFile("fonts/arial.ttf"))
		{
			std::cout << "Score font loaded successfully \n";
		}
		else
		{
			std::cout << " Score font FAILED TO LOAD \n";
		}
		
		this->ssScore<< "Points : "<<this->value;
		this->score_Text.setFont(score_Font);
		this->score_Text.setCharacterSize(24);
		this->score_Text.setPosition(10, 10);
		this->score_Text.setString(ssScore.str());
	}
	void setValue(int n)
	{
		value = n;
	}
	void pointsRender(sf::RenderWindow& window)
	{
		window.draw(this->score_Text);
	}
	void setaddPoint(float n)
	{
		m_addValue = n;
	}

	void addPoints()
	{	
		value += m_addValue;
	}
};
class StateMachine
{

};

int main()
{
	std::srand(static_cast<unsigned>(time(NULL)));
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

	//Creating bullets
	Bullet b1(5.f);
	std::vector<Bullet> bulets;
	bulets.push_back(Bullet(b1));
	//Creating enemies
	std::vector<std::unique_ptr<Enemy>> enemies;
	int iteracja_tworzenie_obiektow = 0;
	while (iteracja_tworzenie_obiektow < 25)
	{

		while (iteracja_tworzenie_obiektow < 25)
		{
			int losowanie_x = rand() % 1+1;
			if (losowanie_x == 0)
			{
				auto littleEnemy_pozycja_x =0;
				auto littleEnemy_pozycja_y = rand() % 400+100;
				
				enemies.emplace_back(std::make_unique<LittleEnemy>());
				enemies[iteracja_tworzenie_obiektow]->setPosition(littleEnemy_pozycja_x, littleEnemy_pozycja_y);
				/*sf::Vector2u e_direction = normalize(player.getPosition() - enemies[iteracja_tworzenie_obiektow]->getPosition());*/
				/*enemies[iteracja_tworzenie_obiektow]->move(enemies[iteracja_tworzenie_obiektow]->direction = normalize(player.getPosition() - enemies[iteracja_tworzenie_obiektow].getPosition()));*/
				iteracja_tworzenie_obiektow++;
			}
			if (losowanie_x == 1)
			{
				auto littleEnemy_pozycja_x =700 ;
				auto littleEnemy_pozycja_y = rand() % 400 + 100;
				
				enemies.emplace_back(std::make_unique<LittleEnemy>());
				enemies[iteracja_tworzenie_obiektow]->setPosition(littleEnemy_pozycja_x, littleEnemy_pozycja_y);
				
				iteracja_tworzenie_obiektow++;
			}
			if (losowanie_x == 2)
			{
				auto littleEnemy_pozycja_x = rand() % 600+100;
				auto littleEnemy_pozycja_y =0;
				
				enemies.emplace_back(std::make_unique<LittleEnemy>());
				enemies[iteracja_tworzenie_obiektow]->setPosition(littleEnemy_pozycja_x, littleEnemy_pozycja_y);
				iteracja_tworzenie_obiektow++;
			}
			if (losowanie_x == 3)
			{
				auto littleEnemy_pozycja_x = rand() % 600+100;
				auto littleEnemy_pozycja_y =500;
				
				enemies.emplace_back(std::make_unique<LittleEnemy>());
				enemies[iteracja_tworzenie_obiektow]->setPosition(littleEnemy_pozycja_x, littleEnemy_pozycja_y);
				iteracja_tworzenie_obiektow++;
			}
		}
	}

	//Creating window
	sf::RenderWindow window(sf::VideoMode(VIEW_WIDTH,VIEW_HEIGHT), "Mistix", sf::Style::Close | sf::Style::Titlebar);
	window.setFramerateLimit(144);

	//Creating cursor
	window.setMouseCursorVisible(false);
	CustomMouse custom_mouse;

	/*Menu menu(VIEW_WIDTH, VIEW_HEIGHT);*/
	
	//Creating ScoreBoard
	Score m_scorePoints;
	m_scorePoints.setValue(0);
	m_scorePoints.setaddPoint(1);
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
		player.playerCenter = sf::Vector2f(player.getPosition().x, player.getPosition().y);
		player.mousePosWindow = sf::Vector2f(sf::Mouse::getPosition(window));
		player.aimDir = player.mousePosWindow - player.playerCenter;
		player.aimDirNorm = player.aimDir/ (sqrt(pow(player.aimDir.x, 2) + pow(player.aimDir.y, 2)));

		b1.playerCenter=player.playerCenter;
		b1.mousePosWindow=player.mousePosWindow;
		b1.aimDir =player.aimDir;
		b1.aimDirNorm=player.aimDirNorm;

		custom_mouse.playerCenter = player.playerCenter;
		custom_mouse.mousePosWindow = player.mousePosWindow;
		custom_mouse.aimDir = player.aimDir;
		custom_mouse.aimDirNorm = player.aimDirNorm;


		
		
		

		/*std::cout << aimDirNorm.x << " " << aimDirNorm.y << std::endl;*/
		//Shooting
		b1.setAmmo(20);
		b1.setSpeed(5.f);
		if (b1.bulletTimer<b1.maxbulletTimer)
		{
			b1.bulletTimer++;
		}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)&&b1.bulletTimer>=b1.maxbulletTimer)
			{
				b1.bullet.setPosition(b1.playerCenter);
				b1.currVelocity = b1.aimDirNorm * b1.maxSpeed;

				bulets.push_back(Bullet(b1));
				b1.bulletTimer = 0;
			}
		
			for (auto i = 0;i < bulets.size();i++)
			{
				bulets[i].bullet.move(bulets[i].currVelocity);
				if (bulets[i].bullet.getPosition().x < 0 || bulets[i].bullet.getPosition().x > 800 || bulets[i].bullet.getPosition().y < 0 || bulets[i].bullet.getPosition().y > 600)
					bulets.erase(bulets.begin() + i);
			}
		//Update the mouse
			custom_mouse.mouseUpdate();

			//Update of Enemies
			for (int i = 0;i < enemies.size();i++)
			{
				sf::Vector2f playerpos = sf::Vector2f(player.getPosition());
				enemies[i]->setMove(playerpos);
			}
		
		//Clear the window

		window.clear();
		window.draw(background_Sprite);
		//Draw current Frame
		//Draw Player

		window.draw(player);
		for (int i = 0;i < bulets.size();i++)
		{
			window.draw(bulets[i].bullet);
		}

		//Draw Enemies
		for (int i=0;i<enemies.size();i++)
		{
			window.draw(*enemies[i]);
		}
		//Draw the cursor
		custom_mouse.mouseRender(window);
		m_scorePoints.pointsRender(window);
		//
		/*menu.draw(window);*/

		//Display everything

		window.display();

	}


	return 0;
}