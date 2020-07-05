#include "Menu.h"

//Constructor //Destructor
Menu::Menu(float width, float height)
{
	if (!m_font.loadFromFile("fonts/arial.ttf"))
	{
		//handle error
	}
	m_menu[0].setFont(m_font);
	m_menu[0].setColor(sf::Color::Red);
	m_menu[0].setString("Play");
	m_menu[0].setPosition(sf::Vector2f(width / 2,
		height / (MAX_NUMBER_OF_ITEMS+1) * 1));

	m_menu[1].setFont(m_font);
	m_menu[1].setColor(sf::Color::White);
	m_menu[1].setString("Options");
	m_menu[1].setPosition(sf::Vector2f(width / 2,
		height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	m_menu[2].setFont(m_font);
	m_menu[2].setColor(sf::Color::White);
	m_menu[2].setString("Exit");
	m_menu[2].setPosition(sf::Vector2f(width / 2,
		height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
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

}
//Select Down
void Menu::MoveDown()
{

}
