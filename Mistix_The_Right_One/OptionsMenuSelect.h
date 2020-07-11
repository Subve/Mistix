#pragma once
#include  "iostream"
#include <SFML/Graphics.hpp>
#include <vector>
/*#pragma warning(disable : 4996)*/
#define MAX_NUMBER_OF_ITEMS 4
#define MAX_NUMBER_OF_OPTIONS 6

class OptionsMenuSelect
{
public:
	OptionsMenuSelect(float width, float height);
	~OptionsMenuSelect();


	void MoveLeft();
	void MoveRight();
	
	int GetPressedItem() { return selectedItemOptionsIndex; };
	std::vector<OptionsMenuSelect> optionsmenusoptions;
	void loadConfig();
	void saveConfig();
	void RenderOptions(sf::RenderWindow& window);

	int selectedItemOptionsIndex;
	sf::Font m_font;
	sf::Text m_optionsmenu[MAX_NUMBER_OF_ITEMS];
	sf::Text m_optionsmenumenu[MAX_NUMBER_OF_OPTIONS];

};
