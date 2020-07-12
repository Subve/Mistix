#include "BarricadeManager.h"

BarricadeManager::BarricadeManager()
{
}

BarricadeManager::~BarricadeManager()
{
}

void BarricadeManager::SpawnBarricades(std::vector<std::unique_ptr<Barricade>>& barykady,int &barricade_startamount)
{
	
	int amount_barricades = 0;
	
	while(amount_barricades<barricade_startamount)
	{
		if (amount_barricades < 0) amount_barricades = 0;
		
		
			auto barricade_pozycja_x = static_cast<float>(rand()&600+100);
			auto barricade_pozycja_y = static_cast<float>(rand()%500+50);
			 
			barykady.push_back(std::make_unique<Barricade>());
			barykady[amount_barricades]->setPosition(barricade_pozycja_x, barricade_pozycja_y);
			if(abs(800-barricade_pozycja_x)>abs(600-barricade_pozycja_y))
			{
				barykady[amount_barricades]->setRotation(90);
			}
			barykady[amount_barricades]->used = false;
			barykady[amount_barricades]->used_kill = false;
			
			
			amount_barricades += 1;
		
	}
}

void BarricadeManager::StopEnemy(std::vector<std::unique_ptr<Barricade>>& barykady,std::vector<std::unique_ptr<Enemy>>& enemies,sf::Time &elapsed_time)
{
	for (int i = 0;i < barykady.size();i++)
	{
		for (int j = 0;j < enemies.size();j++)
		{
			if (barykady[i]->getGlobalBounds().intersects(enemies[j]->getGlobalBounds()) && barykady[i]->used == false&&enemies[j]->ableToMove==true)
			{
				enemies[j]->ableToMove = false;
				barykady[i]->used = true;
				barykady[i]->elapsed_barricade_time = sf::milliseconds(0);
				
			}
		}
	}
}

void BarricadeManager::LetEnemyGo(std::vector<std::unique_ptr<Barricade>>& barykady,
	std::vector<std::unique_ptr<Enemy>>& enemies, sf::Time& delta_barricade)
{
	
		for (int i = 0;i < barykady.size();i++)
		{
			for (int j = 0;j < enemies.size();j++)
			{if (barykady[i]->elapsed_barricade_time >= delta_barricade)
			{
			
				{
					if (barykady[i]->getGlobalBounds().intersects(enemies[j]->getGlobalBounds()) && barykady[i]->used == true && enemies[j]->ableToMove == false)
					{
						enemies[j]->ableToMove = true;
						barykady[i]->used_kill = true;
						barykady[i]->elapsed_barricade_time -= delta_barricade;

					}
				
				}
			}
		
			
				
			
		}
		
	}
	
}
void BarricadeManager::KillBarricades(std::vector<std::unique_ptr<Barricade>>& barykady)
{
	for(int i=0;i<barykady.size();i++)
	{
		if(barykady[i]->used_kill==true||barykady[i]->elapsed_barricade_time>sf::seconds(9))
		{
			barykady.erase(barykady.begin() + i);
		}
	}
}

void BarricadeManager::RespawnBarricades(std::vector<std::unique_ptr<Barricade>>& barykady)
{
	
	
		int numer = barykady.size();
		auto barricade_pozycja_x = static_cast<float>(rand() & 600 + 100);
		auto barricade_pozycja_y = static_cast<float>(rand() % 500 + 50);
		barykady.emplace_back(std::make_unique<Barricade>());
		
		barykady[numer]->setPosition(barricade_pozycja_x, barricade_pozycja_y);
		barykady[numer]->used = false;
		barykady[numer]->used_kill = false;
		
	
}

void BarricadeManager::renderBarricade(sf::RenderTarget& window, std::vector<std::unique_ptr<Barricade>>& barykady)
{
	for (int i = 0;i < barykady.size();i++)
	{
		window.draw(*barykady[i]);
	}
}
