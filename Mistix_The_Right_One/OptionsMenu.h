#pragma once
#include  "iostream"
#include <SFML/Graphics.hpp>
#include <vector>
#include "OptionsMenuSelect.h"
/*#pragma warning(disable : 4996)*/
#define MAX_NUMBER_OF_ITEMS 4

class OptionsMenu
{
public:
	OptionsMenu(float width, float height);
	~OptionsMenu();

	
	void MoveUp(OptionsMenuSelect&select);
	void MoveDown(OptionsMenuSelect&select);
	int GetPressedItem() { return selectedItemIndex; };
	std::vector<OptionsMenu> optionsmenus;
	void loadConfig();
	void saveConfig();
	void RenderOptions(sf::RenderWindow& window);
private:
	int selectedItemIndex;
	sf::Font m_font;
	sf::Text m_optionsmenu[MAX_NUMBER_OF_ITEMS];

};
