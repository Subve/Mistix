#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <cmath>
#include <math.h>
#include <memory>
#include <sstream>
#include "Enemy.h"
#include "LittleEnemy.h"
class EntityManager
{
private:

public:

	EntityManager();

	void SpawnEnemy(std::vector<std::unique_ptr<Enemy>>& enemies,int &mobID, int& iteracja_tworzenie_obiektow);
	void RespawnEnemy(std::vector<std::unique_ptr<Enemy>>& enemies, int& mobID1, int& iteracja_tworzenie_obiektow);
	void InitEnemy(std::vector<std::unique_ptr<Enemy>>& enemies, int& mobID, int& iteracja_tworzenie_obiektow);
	void keepEnemies(std::vector<std::unique_ptr<Enemy>>& enemies,int&mobID, int&iteracja_tworzenie_obiektow);
	void RenderEnemies(sf::RenderTarget& window, std::vector < std::unique_ptr< Enemy >> &enemies);
	int enemyTimer;
	int enemyTimerMax;
};

