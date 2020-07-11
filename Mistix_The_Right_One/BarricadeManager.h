#pragma once
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
class Barricade;

class BarricadeManager
{

public:
	BarricadeManager();
	~BarricadeManager();
	void SpawnBarricades(std::vector<std::unique_ptr<Barricade>>& barykady, int& barricade_startamount);
	void StopEnemy(std::vector<std::unique_ptr<Barricade>>& barykady, std::vector<std::unique_ptr<Enemy>>& enemies,sf::Time &elapsed_time);
	void LetEnemyGo(std::vector<std::unique_ptr<Barricade>>& barykady, std::vector<std::unique_ptr<Enemy>>& enemies, sf::Time& elapsed_barricade,
		sf::Time& delta_barricade);
	void RespawnBarricades(std::vector<std::unique_ptr<Barricade>>& barykady);
	void KillBarricades(std::vector < std::unique_ptr < Barricade>> &barykady);
	void renderBarricade(sf::RenderTarget& window, std::vector<std::unique_ptr<Barricade>>& barykady);
	
};











