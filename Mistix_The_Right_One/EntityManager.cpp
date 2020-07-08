#include "EntityManager.h"

EntityManager::EntityManager()
{
}

void EntityManager::SpawnEnemy(std::vector<std::unique_ptr<Enemy>>& enemies, int& mobID,int &iteracja_tworzenie_obiektow)
{
	
	while (iteracja_tworzenie_obiektow < 25)
	{

		while (iteracja_tworzenie_obiektow < 25)
		{
			int losowanie_x = rand() % 4;
			if (losowanie_x == 0)
			{
				auto littleEnemy_pozycja_x = static_cast<float>(0);
				auto littleEnemy_pozycja_y = static_cast<float>(rand() % 400 + 100);

				enemies.emplace_back(std::make_unique<LittleEnemy>());
				enemies[iteracja_tworzenie_obiektow]->setPosition(littleEnemy_pozycja_x, littleEnemy_pozycja_y);
				enemies[iteracja_tworzenie_obiektow]->mobID = mobID;
				enemies[iteracja_tworzenie_obiektow]->polaczone = false;
				enemies[iteracja_tworzenie_obiektow]->HP = 1;
				mobID++;
				/*sf::Vector2u e_direction = normalize(player.getPosition() - enemies[iteracja_tworzenie_obiektow]->getPosition());*/
				/*enemies[iteracja_tworzenie_obiektow]->move(enemies[iteracja_tworzenie_obiektow]->direction = normalize(player.getPosition() - enemies[iteracja_tworzenie_obiektow].getPosition()));*/
				iteracja_tworzenie_obiektow++;
			}
			if (losowanie_x == 1)
			{
				auto littleEnemy_pozycja_x = static_cast<float>(700);
				auto littleEnemy_pozycja_y = static_cast<float>(rand() % 400 + 100);

				enemies.emplace_back(std::make_unique<LittleEnemy>());
				/*enemies.emplace_back(std::make_unique<LittleEnemy>());*/
				enemies[iteracja_tworzenie_obiektow]->setPosition(littleEnemy_pozycja_x, littleEnemy_pozycja_y);
				enemies[iteracja_tworzenie_obiektow]->mobID = mobID;
				enemies[iteracja_tworzenie_obiektow]->polaczone = false;
				enemies[iteracja_tworzenie_obiektow]->HP = 1;
				mobID++;
				iteracja_tworzenie_obiektow++;
			}
			if (losowanie_x == 2)
			{
				auto littleEnemy_pozycja_x = static_cast<float>(rand() % 600 + 100);
				auto littleEnemy_pozycja_y = static_cast<float>(0);

				enemies.emplace_back(std::make_unique<LittleEnemy>());
				enemies[iteracja_tworzenie_obiektow]->setPosition(littleEnemy_pozycja_x, littleEnemy_pozycja_y);
				enemies[iteracja_tworzenie_obiektow]->mobID = mobID;
				enemies[iteracja_tworzenie_obiektow]->polaczone = false;
				enemies[iteracja_tworzenie_obiektow]->HP = 1;
				mobID++;
				iteracja_tworzenie_obiektow++;
			}
			if (losowanie_x == 3)
			{
				auto littleEnemy_pozycja_x = static_cast<float>(rand() % 600 + 100);
				auto littleEnemy_pozycja_y = static_cast<float>(500);

				enemies.emplace_back(std::make_unique<LittleEnemy>());
				enemies[iteracja_tworzenie_obiektow]->setPosition(littleEnemy_pozycja_x, littleEnemy_pozycja_y);
				enemies[iteracja_tworzenie_obiektow]->mobID = mobID;
				enemies[iteracja_tworzenie_obiektow]->polaczone = false;
				enemies[iteracja_tworzenie_obiektow]->HP = 1;
				mobID++;
				iteracja_tworzenie_obiektow++;
			}
		}
	}
}

void EntityManager::RespawnEnemy(std::vector<std::unique_ptr<Enemy>>& enemies, int& mobID, int& iteracja_tworzenie_obiektow)
{
	int numer=enemies.size() - 1;
	if (numer < 0) numer = 0;
		int losowanie_x = rand() % 4;
		if (losowanie_x == 0)
		{
			auto littleEnemy_pozycja_x = static_cast<float>(0);
			auto littleEnemy_pozycja_y = static_cast<float>(rand() % 400 + 100);
			 
			enemies.push_back(std::make_unique<LittleEnemy>());
			enemies[numer]->setPosition(littleEnemy_pozycja_x, littleEnemy_pozycja_y);
			enemies[numer]->mobID = mobID;
			enemies[numer]->polaczone = false;
			enemies[numer]->HP = 1;
			mobID += 1;
			/*sf::Vector2u e_direction = normalize(player.getPosition() - enemies[iteracja_tworzenie_obiektow]->getPosition());*/
			/*enemies[iteracja_tworzenie_obiektow]->move(enemies[iteracja_tworzenie_obiektow]->direction = normalize(player.getPosition() - enemies[iteracja_tworzenie_obiektow].getPosition()));*/
			iteracja_tworzenie_obiektow += 1;
		}
		if (losowanie_x == 1)
		{
			auto littleEnemy_pozycja_x = static_cast<float>(700);
			auto littleEnemy_pozycja_y = static_cast<float>(rand() % 400 + 100);

			
			enemies.push_back(std::make_unique<LittleEnemy>());
			enemies[numer]->setPosition(littleEnemy_pozycja_x, littleEnemy_pozycja_y);
			enemies[numer]->mobID = mobID;
			enemies[numer]->polaczone = false;
			enemies[numer]->HP = 1;
			mobID += 1;
			iteracja_tworzenie_obiektow += 1;
		}
		if (losowanie_x == 2)
		{
			auto littleEnemy_pozycja_x = static_cast<float>(rand() % 600 + 100);
			auto littleEnemy_pozycja_y = static_cast<float>(0);

			enemies.push_back(std::make_unique<LittleEnemy>());
			enemies[numer]->setPosition(littleEnemy_pozycja_x, littleEnemy_pozycja_y);
			enemies[numer]->mobID = mobID;
			enemies[numer]->polaczone = false;
			enemies[numer]->HP = 1;
			mobID += 1;
			iteracja_tworzenie_obiektow += 1;
		}
		if (losowanie_x == 3)
		{
			auto littleEnemy_pozycja_x = static_cast<float>(rand() % 600 + 100);
			auto littleEnemy_pozycja_y = static_cast<float>(500);

			enemies.push_back(std::make_unique<LittleEnemy>());
			enemies[numer]->setPosition(littleEnemy_pozycja_x, littleEnemy_pozycja_y);
			enemies[numer]->mobID = mobID;
			enemies[numer]->polaczone = false;
			enemies[numer]->HP = 1;
			mobID +=1;
			iteracja_tworzenie_obiektow += 1;
		}
	
	
}
	

