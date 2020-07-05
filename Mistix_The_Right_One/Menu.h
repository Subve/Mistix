#pragma once
#include <SFML/Graphics.hpp>
#pragma warning(disable : 4996)
#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
public:
	Menu(float width,float height);
	~Menu();

	void draw(sf::RenderWindow& window);
	void MoveUp();
	void MoveDown();

private:
	int selectedItemIndex;
	sf::Font m_font;
	sf::Text m_menu[MAX_NUMBER_OF_ITEMS];
};

