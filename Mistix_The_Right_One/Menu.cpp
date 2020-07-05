#include "Menu.h"

//Constructor //Destructor
Menu::Menu(float width, float height)
{
	if (!m_font.loadFromFile("fonts/arial.ttf"))
	{
		//handle error
	}

	//Creating menu Tiles
	m_menu[0].setFont(m_font);
	m_menu[0].setFillColor(sf::Color::Red);
	m_menu[0].setString("Play");
	m_menu[0].setPosition(sf::Vector2f(width / 2,
		height / (MAX_NUMBER_OF_ITEMS+1) * 1));

	m_menu[1].setFont(m_font);
	m_menu[1].setFillColor(sf::Color::White);
	m_menu[1].setString("Options");
	m_menu[1].setPosition(sf::Vector2f(width / 2,
		height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	m_menu[2].setFont(m_font);
	m_menu[2].setFillColor(sf::Color::White);
	m_menu[2].setString("Exit");
	m_menu[2].setPosition(sf::Vector2f(width / 2,
		height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

	//Initialize the selectedIndex
	selectedItemIndex = 0;

}

Menu::~Menu()
{
}
//Draw Menu
void Menu::draw(sf::RenderWindow& window)
{
	for (int i=0; i<MAX_NUMBER_OF_ITEMS;i++)
	{
		window.draw(m_menu[i]);
	}
}
//Select Upp
void Menu::MoveUp()
{
	if (selectedItemIndex-1>=0)
	{
		m_menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		m_menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}
//Select Down
void Menu::MoveDown()
{
	if (selectedItemIndex + 1 <MAX_NUMBER_OF_ITEMS)
	{
		m_menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		m_menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}
