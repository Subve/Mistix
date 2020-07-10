
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "EntityManager.h"
#include "Menu.h"
#include <cmath>
#include <math.h>
#include <memory>
#include <sstream>
#include "Score.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "LittleEnemy.h"
#include "CustomMouse.h"
#include "Background.h"
#include "HighScore.h"
#include "Button.h"
#include "Apple.h"
#include  "AppleManager.h"
#include "HPBar.h"

#define VIEW_HEIGHT 600

#define  VIEW_WIDTH 800

inline double deg2rad(double degrees) {
	return degrees * 3,1429 / 360;
}

/*
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

		
		this->score_Text.setFont(score_Font);
		this->score_Text.setCharacterSize(24);
		this->score_Text.setPosition(10, 10);
		this->updateText();
	}
	void updateText()
	{
		ssScore.str("");
		ssScore.clear();
		this->ssScore << "Points : " << this->value;
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
		m_addValue = static_cast<int>(n);
	}

	void addPoints()
	{
		value += m_addValue;
	}
};*/
/*
class Player1 :public sf::Sprite
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
		/ *window.convertCoords(mouse);

		//gets sprite origin coordinates and mouse coordinates
		this->spritePosition = sprite.getPosition();
		this->mouse = sf::Mouse::getPosition();

		mouseAngle = -atan2(mouse.x - spritePosition.x, mouse.y - spritePosition.y) * 180 / 3.14159; //angle in degrees of rotation for sprite

		playerSprite.setRotation(mouseAngle);* /
		window.mapPixelToCoords(mouse);
		/ *this->mouse = sf::Mouse::getPosition(window);
		this->player_position = this->getPosition();* /
		this->updateMousePos(window);
		angle = static_cast<float>(-atan2(mouse.x - player_position.x, mouse.y - player_position.y) * 180 / 3.14159);
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
};*/


/*
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
};*/

/*
class Enemy:public sf::Sprite
{

private:

public:

	Enemy():Sprite() {};
	virtual ~Enemy() = default;
	virtual void Follow() = 0;
	virtual void Attack(Player& gracz) = 0;
	virtual void Rotate(sf::Vector2f& playermove) = 0;
	virtual void adMove(sf::Vector2f&vektorRuchu) = 0;
	virtual void setDirection(sf::Vector2u& direction2) = 0;
	virtual void setMove(sf::Vector2f& playermove) = 0;
	virtual void killedZombie(Score& wynik, std::vector<Bullet>& pociski, std::vector<std::unique_ptr<Enemy>> &enemies) = 0;

	float angle;
	sf::Vector2u direction;
	sf::Vector2f playerCenter;
	sf::Vector2f mousePosWindow;
	sf::Vector2f aimDir;
	sf::Vector2f aimDirNorm;
	sf::Vector2f enemyPos;
	bool trafiony;
	bool zabity;
	int HP;
	
};*/

/*
class LittleEnemy :public Enemy
{
private:
	sf::Texture littleenemy_Texture;

public:
	LittleEnemy() :Enemy() {

		if (littleenemy_Texture.loadFromFile("tekstury/skeleton-attack_0.png"))
		{
			std::cout<<"Successfully loaded LittleEnemy Texture \n";

		}
		littleenemy_Texture.setRepeated(true);
		this->setTexture(littleenemy_Texture);
		this->setScale(sf::Vector2f(0.1f, 0.15f));
		this->trafiony = false;
		this->zabity = false;

	};
	virtual void Follow() {};
	virtual void Attack(Player &gracz) {};
	virtual void Rotate(sf::Vector2f& playerpos)
	{
		this->enemyPos=this->getPosition();
		angle = static_cast<float>(-atan2(enemyPos.x - playerpos.x, enemyPos.y - playerpos.y) * 180 / 3.14159);
		this->setRotation(angle-90);
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
		/ *enemies[i]->move(-1*(enemies[i]->aimDirNorm.x),-1*(enemies[i]->aimDirNorm.y));* /
		this->adMove(this->aimDirNorm);
	}
	virtual void killedZombie(Score&wynik,std::vector<Bullet>&pociski, std::vector<std::unique_ptr<Enemy>> &enemies)
	{
		{
			for (int j = 0;j < enemies.size();j++)
			{
				for (int i = 0;i < pociski.size();i++)
				{
					if (pociski[i].bullet.getGlobalBounds().intersects(this->getGlobalBounds()))
					{
						this->trafiony = true;
						if (trafiony == true && zabity == false)
						{
							std::cout << "Trafiony zombiak" << "\n";
							
							
							
							
							pociski.erase(pociski.begin() + i);
							this->zabity = true;
							if (zabity)
							{
								wynik.setaddPoint(1);
								wynik.addPoints();
								wynik.updateText();

							}
							/ *enemies.erase(enemies.begin() + j);* /
							

						}
						

					}
				}
			}
		}
	}
	sf::Vector2f playerCenter;
	sf::Vector2f mousePosWindow;
	sf::Vector2f aimDir;
	sf::Vector2f aimDirNorm;
	sf::Vector2u direction;
	float angle;
	sf::Vector2f enemyPos;
	bool trafiony;
	bool zabity;
	int HP;
};*/
/*
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

};*/

class StateMachine
{

};
/*
class Background
{
private:
	sf::Texture background;
	sf::Sprite background_Sprite;
public:
	/ *if (background.loadFromFile("tekstury/Background_Desert.png"))
	{
		std::cout << "Background texture successfully loaded\n";
	}
	background.setSmooth(true);
	sf::Sprite background_Sprite;
	background_Sprite.setTexture(background);* /
	Background()
	{
		this->initBackground();
	};
	void initBackground()
	{
		this->LoadBackgroundTexture();
		this->SetBackgroundSprite();
	}
	void LoadBackgroundTexture()
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
	void SetBackgroundSprite()
	{
		this->background_Sprite.setTexture(this->background);
	}
	void renderBackground(sf::RenderTarget&window)
	{
		window.draw(this->background_Sprite);
	}
	
};*/

int main()
{
	std::srand(static_cast<unsigned>(time(NULL)));
	EntityManager entityManager;
	AppleManager apple_manager;
	Background background;
	HPBar m_hp_bar;
	
	//Creating player
	Player player;
	m_hp_bar.initHPBAR(player);
	//Creating bullets
	Bullet b1(5.f);
	std::vector<Bullet> bulets;
	bulets.push_back(Bullet(b1));
	int mobIDLicznik=0;
	int jablkaLicznik = 0;
	//Creating enemies
	int iteracja_tworzenie_obiektow = 0;
	std::vector<std::unique_ptr<Enemy>> enemies;
	std::vector<std::unique_ptr<Apple>> jablka;

	int newmobID;
	int howmanyenemies;
	entityManager.SpawnEnemy(enemies, mobIDLicznik,iteracja_tworzenie_obiektow);
	//Spawn an apple
	

	//Creating upgrade Button
	Button m_button;

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
	HighScore m_highscore;
		b1.setAmmo(50);
		
		b1.setSpeed(2.f);
	//Timer
		sf::Time elapsed_time, temp_time;
		sf::Clock r;
		sf::Time elapsed_time_player, temp_player;
		sf::Clock r_player;
		sf::Time elapsed_time_pause, temp_pause;
		sf::Clock r_pause;
		sf::Time elapsed_upgrades_time, temp_upgrades;
		sf::Clock r_upgrades;
		sf::Time elapsed_apples_time, temp_apples;
		sf::Clock r_apple;
		bool pause;
		pause = false;
	while (window.isOpen())
	{
		sf::Time delta_time = sf::milliseconds(1000);
		sf::Time delta_time_player = sf::milliseconds(1000);
		sf::Time delta_time_pause = sf::milliseconds(1000);
		sf::Time delta_time_upgrades = sf::milliseconds(1000);
		sf::Time delta_time_apple = sf::seconds(10);
		elapsed_time_pause += r_pause.restart();
		temp_time= r.restart();
		temp_player= r_player.restart();
		temp_upgrades = r_upgrades.restart();
		temp_apples = r_apple.restart();

		if(!pause)
		{
			elapsed_time += temp_time;

			elapsed_time_player += temp_player;
			
			elapsed_upgrades_time += temp_upgrades;

			elapsed_apples_time += temp_apples;
		}

		
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
			case sf::Event::KeyPressed:
				
			{
				if (ev.key.code == sf::Keyboard::P&&!pause)
				{
					pause = true;
					break;
					
				}
				if (ev.key.code == sf::Keyboard::P&&pause&&(elapsed_time_pause>=delta_time_pause))
				{
					pause = false;
					elapsed_time_pause -= delta_time_pause;
					break;
				}

				break;
			}
				
				

			}
		//Update the game
		if(!pause)
		{
			player.playerUpdate(window);
			player.playerCenter = sf::Vector2f(player.getPosition().x, player.getPosition().y);
			player.mousePosWindow = sf::Vector2f(sf::Mouse::getPosition(window));
			player.aimDir = player.mousePosWindow - player.playerCenter;
			player.aimDirNorm = player.aimDir / (sqrt(pow(player.aimDir.x, 2) + pow(player.aimDir.y, 2)));

			b1.playerCenter = player.playerCenter;
			b1.mousePosWindow = player.mousePosWindow;
			b1.aimDir = player.aimDir;
			b1.aimDirNorm = player.aimDirNorm;

			custom_mouse.playerCenter = player.playerCenter;
			custom_mouse.mousePosWindow = player.mousePosWindow;
			custom_mouse.aimDir = player.aimDir;
			custom_mouse.aimDirNorm = player.aimDirNorm;






			/*std::cout << aimDirNorm.x << " " << aimDirNorm.y << std::endl;*/

			//GUI
			
			if(elapsed_upgrades_time >= delta_time_upgrades)
			{
				if(m_button.isClicked(window,m_scorePoints))
				{
				m_button.UpgradeBulletSpeed(b1, m_scorePoints);
					m_scorePoints.updateText();
					std::cout << "Upgrade\n";
				}
				elapsed_upgrades_time -= delta_time_upgrades;
			}
			
			
			//Shooting

			if (b1.bulletTimer < b1.maxbulletTimer)
			{
				b1.bulletTimer++;
			}


			if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && b1.bulletTimer >= b1.maxbulletTimer)
			{
				b1.bullet.setPosition(b1.playerCenter);
				b1.currVelocity = b1.aimDirNorm * b1.maxSpeed;

				bulets.push_back(Bullet(b1));
				b1.bulletTimer = 0;
			}

			for (int i = 0;i < bulets.size();i++)
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
				entityManager.keepEnemies(enemies, mobIDLicznik, iteracja_tworzenie_obiektow);
				enemies[i]->killedZombie(m_scorePoints, bulets, enemies);
				m_hp_bar.UpdateHP(player);
				entityManager.keepEnemies(enemies, mobIDLicznik, iteracja_tworzenie_obiektow);


			}
			howmanyenemies = enemies.size();
			/*entityManager.RespawnEnemy(enemies, mobIDLicznik, iteracja_tworzenie_obiektow);*/

			for (int i = 0;i < enemies.size();i++)
			{
				enemies[i]->Attack(player, elapsed_time_player, delta_time_player);
				m_hp_bar.UpdateHP(player);
				entityManager.keepEnemies(enemies, mobIDLicznik, iteracja_tworzenie_obiektow);
			}
			for (int i = 0;i < enemies.size();i++)

			{
				for (int j = 0;j < enemies.size();j++)
				{

					if (enemies[i]->getLocalBounds().intersects(enemies[j]->getLocalBounds()) && (enemies[i]->mobID != enemies[j]->mobID) && (!enemies[i]->polaczone) && (!enemies[j]->polaczone))
					{


						std::cout << "Polaczone\n";
						enemies[i]->polaczone = true;
						enemies[j]->polaczone = true;
						enemies[i]->HP+=1;

						enemies.erase(enemies.begin()+j);
						entityManager.keepEnemies(enemies,newmobID,iteracja_tworzenie_obiektow);

						
						/*enemies[i]->setScale(2.0, 2.0);*/

					}

				}
			}
			apple_manager.CollisionApple(player, jablka);
			m_hp_bar.UpdateHP(player);
			if (elapsed_time >= delta_time)
			{
				entityManager.RespawnEnemy(enemies, mobIDLicznik, iteracja_tworzenie_obiektow);
				elapsed_time -= delta_time;
			}
			for (int i = 0;i < enemies.size();i++)
			{

				sf::Vector2f playerpos = sf::Vector2f(player.getPosition());
				if(enemies[i]->ableToMove==true)
				{
					enemies[i]->setMove(playerpos);
					enemies[i]->Rotate(playerpos);
					entityManager.keepEnemies(enemies, mobIDLicznik, iteracja_tworzenie_obiektow);
				}

				/*enemies[i]->setID(enemies);*/

			}
			if(player.m_playerHealth<=0)
			{
				std::cout << "Koniec gry\n";
				window.close();
			}
			m_scorePoints.updateText();
		}
		
		
			apple_manager.SpawnApple(jablka, elapsed_apples_time, delta_time_apple);
		
		

		//Clear the window

		window.clear();
		background.renderBackground(window);
		//Draw current Frame
		
		

		//Draw Enemies
		for (int i = 0;i < bulets.size();i++)
		{
			window.draw(bulets[i].bullet);
		}
		entityManager.RenderEnemies(window, enemies);
		//Draw Player

		window.draw(player);
		
		
		
		//Draw Apples
		apple_manager.RenderApples(window, jablka);
		//Update the record
		m_highscore.updateHighScore(m_scorePoints);
		//Draw the cursor
		
		m_scorePoints.pointsRender(window);
		
		m_highscore.renderHighscore(window);
		m_button.RenderUpgradeButton(window,m_scorePoints,b1);
		m_hp_bar.RenderHPBar(window);
		custom_mouse.mouseRender(window);
		//
		/*menu.draw(window);*/

		//Display everything

		window.display();
		
	}

	m_highscore.saveHighScore(m_scorePoints);
	return 0;
}