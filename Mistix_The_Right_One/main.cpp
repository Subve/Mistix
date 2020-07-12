
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
#include "OptionsMenu.h"
#include "OptionsMenuSelect.h"
#include <fstream>
#include "Barricade.h"
#include "BarricadeManager.h"

#define VIEW_HEIGHT 600

#define  VIEW_WIDTH 800

inline double deg2rad(double degrees) {
	return degrees * 3,1429 / 360;
}

void Game_Running()
{
	std::srand(static_cast<unsigned>(time(NULL)));
	EntityManager entityManager;
	AppleManager apple_manager;
	BarricadeManager barricade_manager;
	
	Background background("tekstury/Background_Desert.png");
	HPBar m_hp_bar;

	//Creating player
	Player player;
	m_hp_bar.initHPBAR(player);
	//Creating bullets
	Bullet b1(5.f);
	std::vector<Bullet> bulets;
	bulets.push_back(Bullet(b1));
	int mobIDLicznik = 0;
	int jablkaLicznik = 0;
	//Creating enemies
	int iteracja_tworzenie_obiektow = 0;
	std::vector<std::unique_ptr<Enemy>> enemies;
	std::vector<std::unique_ptr<Apple>> jablka;
	std::vector<std::unique_ptr<Barricade>> barykady;
	
	int newmobID;
	int howmanyenemies;
	entityManager.SpawnEnemy(enemies, mobIDLicznik, iteracja_tworzenie_obiektow);
	//Spawn an apple


	//Creating upgrade Button
	Button m_button;
	//Music
	sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("data/music.wav"))
	{
		std::cout << "Failed to load Music \n";
	}
	sf::Sound m_sound;
	m_sound.setBuffer(buffer);
	m_sound.setLoop(true);
	m_sound.play();
	sf::SoundBuffer death_buffer;
	if (!death_buffer.loadFromFile("data/Dying.wav"))
	{
		std::cout << "Failed to load death sound \n";
	}
	sf::Sound m_death_sound;
	m_death_sound.setBuffer(death_buffer);
	m_death_sound.setMinDistance(2);
	
	int barricade_start_amount = 5;
	int barricade_start_respawn = 9;
	int volume=100;
	std::fstream plik;
	plik.open("data/Setting.txt");
	if(plik.good()==false)
	{
		std::cout << "Plik nie istnieje!\n";
		
	}
	std::string linia;
	int nr_linii=1;
	while(std::getline(plik,linia))
	{
		switch (nr_linii)
		{
		case 1:
			volume = std::stoi(linia);
			break;
		case 2:
			barricade_start_respawn = std::stoi(linia);
			break;
		case 3:
			barricade_start_amount = std::stoi(linia);
		case 4:
			player.m_playerHealth = std::stoi(linia);
	
		}
		
		
		
		nr_linii++;
	}
	
	barricade_manager.SpawnBarricades(barykady, barricade_start_amount);
	m_sound.setVolume(volume);
	//Creating game_window
	sf::RenderWindow game_window(sf::VideoMode(VIEW_WIDTH, VIEW_HEIGHT), "Mistix", sf::Style::Close | sf::Style::Titlebar);
	game_window.setFramerateLimit(144);
	//Creating cursor
	game_window.setMouseCursorVisible(false);
	CustomMouse custom_mouse;

	/*Menu menu(VIEW_WIDTH, VIEW_HEIGHT);*/

	//Creating ScoreBoard
	Score m_scorePoints;
	m_scorePoints.setValue(0);
	m_scorePoints.setaddPoint(1);
	HighScore m_highscore;
	b1.setAmmo(50);

	b1.setSpeed(2.f);




	//Timers
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
	sf::Time elapsed_barricade_time, temp_barricade;
	sf::Clock r_barricade;
	sf::Time elapsed_barricade_respawn, temp_barricade_respawn;
	sf::Clock r_barricade_respawn;
	bool pause;



	//How many seconds to do sth
	sf::Time delta_time_barricade_respawn = sf::seconds(barricade_start_respawn);
		sf::Time delta_time_barricade = sf::seconds(4);
		sf::Time delta_time = sf::milliseconds(1000);
		sf::Time delta_time_player = sf::milliseconds(1000);
		sf::Time delta_time_pause = sf::milliseconds(1000);
		sf::Time delta_time_upgrades = sf::milliseconds(1000);
		sf::Time delta_time_apple = sf::seconds(10);
	pause = false;
	
	while (game_window.isOpen())
	{	for(int i=0;i<barykady.size();i++)
	{
		barykady[i]->temp_barricade = r_barricade.restart();
	}
		temp_barricade_respawn = r_barricade_respawn.restart();
		temp_barricade = r_barricade.restart();
		elapsed_time_pause += r_pause.restart();
		temp_time = r.restart();
		temp_player = r_player.restart();
		temp_upgrades = r_upgrades.restart();
		temp_apples = r_apple.restart();

		if (!pause)
		{
			for (int i = 0;i < barykady.size();i++)
			{
				barykady[i]->elapsed_barricade_time += barykady[i]->temp_barricade;
			}
			elapsed_barricade_respawn += temp_barricade_respawn;
			
			elapsed_barricade_time += temp_barricade;
			
			elapsed_time += temp_time;

			elapsed_time_player += temp_player;

			elapsed_upgrades_time += temp_upgrades;

			elapsed_apples_time += temp_apples;
		}


		sf::Event ev;
		while (game_window.pollEvent(ev))
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
						game_window.close();

						break;

					default:
						break;
					}
				}

					break;
				}*/



				//Closing the game_window
			case sf::Event::Closed:
				game_window.close();
				break;
			case sf::Event::KeyPressed:

			{
				if (ev.key.code == sf::Keyboard::P && !pause)
				{
					pause = true;
					break;

				}
				if (ev.key.code == sf::Keyboard::P && pause && (elapsed_time_pause >= delta_time_pause))
				{
					pause = false;
					elapsed_time_pause -= delta_time_pause;
					break;
				}

				break;
			}



			}
		//Update the game
		if (!pause)
		{
			player.playerUpdate(game_window);
			player.playerCenter = sf::Vector2f(player.getPosition().x, player.getPosition().y);
			player.mousePosWindow = sf::Vector2f(sf::Mouse::getPosition(game_window));
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

			if (elapsed_upgrades_time >= delta_time_upgrades)
			{
				if (m_button.isClicked(game_window, m_scorePoints))
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

				entityManager.keepEnemies(enemies, mobIDLicznik, iteracja_tworzenie_obiektow);


			}
			howmanyenemies = enemies.size();
			/*entityManager.RespawnEnemy(enemies, mobIDLicznik, iteracja_tworzenie_obiektow);*/

			for (int i = 0;i < enemies.size();i++)
			{
				enemies[i]->Attack(player, elapsed_time_player, delta_time_player);

				entityManager.keepEnemies(enemies, mobIDLicznik, iteracja_tworzenie_obiektow);
			}
			for (int i = 0;i < enemies.size();i++)

			{
				for (int j = 0;j < enemies.size();j++)
				{
						int int_enemyposx_i=static_cast<int>(enemies[j]->enemyPos.x);
						int int_enemyposy_i = static_cast<int>(enemies[j]->enemyPos.y);
					if (enemies[i]->getLocalBounds().contains(int_enemyposx_i,int_enemyposy_i) && (enemies[i]->mobID != enemies[j]->mobID) && (enemies[i]->polaczone==false) && (enemies[j]->polaczone==false)&&enemies[i]->enemyPos!=sf::Vector2f(0.0f,0.0f))
					{


						std::cout << "Polaczone\n";
						enemies[i]->polaczone = true;
						enemies[j]->polaczone = true;
						//enemies[i]->HP += 1;

						//enemies.erase(enemies.begin() + j);
						entityManager.keepEnemies(enemies, newmobID, iteracja_tworzenie_obiektow);


						/*enemies[i]->setScale(2.0, 2.0);*/

					}

				}
			}
			apple_manager.CollisionApple(player, jablka);

			if (elapsed_time >= delta_time)
			{
				entityManager.RespawnEnemy(enemies, mobIDLicznik, iteracja_tworzenie_obiektow);
				elapsed_time -= delta_time;
			}
			for (int i = 0;i < enemies.size();i++)
			{

				sf::Vector2f playerpos = sf::Vector2f(player.getPosition());
				if (enemies[i]->ableToMove == true)
				{
					enemies[i]->setMove(playerpos);
					enemies[i]->Rotate(playerpos);
					entityManager.keepEnemies(enemies, mobIDLicznik, iteracja_tworzenie_obiektow);
				}

			}
			for(int i=0;i<enemies.size();i++)
			{
				
					
					
						if (enemies[i]->HP <= 0)
						{
							enemies[i]->setZabity();

						}
					
				
			}
			for (int i = 0;i < enemies.size();i++)
			{
				if (enemies[i]->zabity)
				{
					enemies.erase(enemies.begin() + i);

				}
			}
			
			if(player.m_playerHealth==4)
			{
				
				m_death_sound.play();
				
			}
			if (player.m_playerHealth <= 0)
			{
				std::cout << "Koniec gry\n";
				game_window.close();
			}
			m_scorePoints.updateText();
			m_hp_bar.UpdateHP(player);
			apple_manager.SpawnApple(jablka, elapsed_apples_time, delta_time_apple);

			if (elapsed_barricade_respawn >= delta_time_barricade_respawn)
			{
				
				barricade_manager.RespawnBarricades(barykady);
			elapsed_barricade_respawn -= delta_time_barricade_respawn;
			}
				
				
			
			
			barricade_manager.StopEnemy(barykady, enemies,elapsed_barricade_time);
			barricade_manager.LetEnemyGo(barykady, enemies, delta_time_barricade);
			barricade_manager.KillBarricades(barykady);
			
		}






		//Clear the game_window

		game_window.clear();
		background.renderBackground(game_window);
		//Draw current Frame



		//Draw Enemies
		for (int i = 0;i < bulets.size();i++)
		{
			game_window.draw(bulets[i].bullet);
		}
		entityManager.RenderEnemies(game_window, enemies);
		//Render barricades
		barricade_manager.renderBarricade(game_window, barykady);

		//Draw Player

		game_window.draw(player);



		//Draw Apples
		apple_manager.RenderApples(game_window, jablka);
		barricade_manager.renderBarricade(game_window, barykady);
		//Update the record
		m_highscore.updateHighScore(m_scorePoints);
		//Draw the cursor

		m_scorePoints.pointsRender(game_window);

		m_highscore.renderHighscore(game_window);
		m_button.RenderUpgradeButton(game_window, m_scorePoints, b1);
		m_hp_bar.RenderHPBar(game_window);
		custom_mouse.mouseRender(game_window);
		//
		/*menu.draw(game_window);*/

		//Display everything

		game_window.display();

	}

	m_highscore.saveHighScore(m_scorePoints);
	
}
void Options_Running()
{
	int sound_volume=100;
	int barricade_start_respawn = 9;
	int barricade_start_amount = 5;
	int player_health = 100;
	
		sf::RenderWindow options_window(sf::VideoMode(VIEW_WIDTH, VIEW_HEIGHT), "Mistix", sf::Style::Close | sf::Style::Titlebar);
		OptionsMenu m_optionsmenu(VIEW_WIDTH, VIEW_HEIGHT);
		OptionsMenuSelect menu_select(VIEW_WIDTH, VIEW_HEIGHT);
		Background background("tekstury/Screen.png");
		background.background_Sprite.setScale(1.3333, 1.5748);
		while (options_window.isOpen())
		{
			sf::Event options_ev;
			while (options_window.pollEvent(options_ev))
				switch (options_ev.type)
				{

					//MENU Option switch
				case sf::Event::Closed:
					options_window.close();
					break;
				case sf::Event::KeyPressed:
				{
					{	switch (options_ev.key.code)
					{
					
					case sf::Keyboard::Up:
						m_optionsmenu.MoveUp(menu_select);
						break;
					case sf::Keyboard::Down:
						m_optionsmenu.MoveDown(menu_select);
						break;
					case sf::Keyboard::Left:
						menu_select.MoveLeft();
						break;
					case sf::Keyboard::Right:
						menu_select.MoveRight();
						break;
					case sf::Keyboard::Return:
						switch (menu_select.GetPressedItem())
						{
							{
						case 0:
							std::cout << "1 button has been pressed\n";
							sound_volume = 0;
								

							break;
						case 1:
						{
							{
								std::cout << "2 button has been pressed\n";
								sound_volume = 50;


								break;
							}
						}
						case 2:
						{
							std::cout << "3 button has been pressed\n";
							sound_volume = 100;

							break;
						}
						case 3:
						{
							std::cout << "4 button has been pressed\n";
							barricade_start_respawn = 15;
							barricade_start_amount = 10;
							player_health = 100;

							break;
						}
						case 4:
						{
							std::cout << "5 button has been pressed\n";
							barricade_start_respawn = 9;
							barricade_start_amount = 5;
							player_health = 60;
								
							

							break;
						}
						case 5:
						{
							std::cout << "6 button has been pressed\n";
							

							break;
						}

						default:
						{
							break;
						}
							}
						}
						switch (m_optionsmenu.GetPressedItem())
						{
						case 2:
							{
							std::fstream setting;
							setting.open("data/Setting.txt",std::ios::out);
								if(setting.is_open())
								{
									setting << sound_volume << std::endl;
									setting << barricade_start_respawn << std::endl;
									setting << barricade_start_amount << std::endl;
									setting << player_health << std::endl;
								}
								setting.close();
							
								std::cout << "Successfully saved sound volume \n";
								
							}
							break;
						case 3:
								options_window.close();
							break;
							default:
							{
								break;
							}
						}
					}

					break;
					}
				}
				}
			

			//Update

			//Draw
				background.renderBackground(options_window);
			m_optionsmenu.RenderOptions(options_window);
			menu_select.RenderOptions(options_window);

			//Display the window
			options_window.display();

		}
		
	
}

int main()
{
	sf::RenderWindow menu_window(sf::VideoMode(VIEW_WIDTH, VIEW_HEIGHT), "Mistix", sf::Style::Close | sf::Style::Titlebar);
	Menu m_menu(VIEW_WIDTH,VIEW_HEIGHT);
	Background background("tekstury/Screen.png");
	background.background_Sprite.setScale(1.3333, 1.5748);


	
	while (menu_window.isOpen())
	{
		sf::Event memu_ev;
		while (menu_window.pollEvent(memu_ev))
			switch (memu_ev.type)
			{

				//MENU Option switch
				case sf::Event::Closed:
						menu_window.close();
						break;

			case sf::Event::KeyPressed:
				{
					{	switch (memu_ev.key.code)
					{
					
					case sf::Keyboard::Up:
                        m_menu.MoveUp();
						break;
					case sf::Keyboard::Down:
                        m_menu.MoveDown();
						break;
					case sf::Keyboard::Return:
                        switch (m_menu.GetPressedItem())
                        {
	                        {
	                        	case 0:
                                    std::cout << "Play button has been pressed\n";
									Game_Running();

	                        	break;
	                        	case 1:
	                        		
	                        			{
	                        				std::cout << "Option button has been pressed\n";
											Options_Running();
											
	                        				break;
	                        			}
	                        		
	                        	case 2:
	                        		{
	                        			std::cout << "Quit button has been pressed\n";
	                        			menu_window.close();

	                        			break;
	                        		}

	                        	default:
	                        		{
	                        			break;
	                        		}
	                        }
                        }
					}

						break;
					}
				}
			}

		//Update

		//Draw
		background.renderBackground(menu_window);
		m_menu.draw(menu_window);

		//Display the window
		menu_window.display();

	}
	//Game_Running();
	return 0;
}