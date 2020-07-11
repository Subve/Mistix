#include "OptionsMenu.h"

//Constructor //Destructor
OptionsMenu::OptionsMenu(float width, float height)
{
	if (!m_font.loadFromFile("fonts/arial.ttf"))
	{
		std::cout<< "Error while loading options menu font\n";
	}

	//Creating menu Tiles
	m_optionsmenu[0].setFont(m_font);
	m_optionsmenu[0].setFillColor(sf::Color::Red);
	m_optionsmenu[0].setString("Volume");
	m_optionsmenu[0].setPosition(sf::Vector2f(width / 2,
		height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	m_optionsmenu[1].setFont(m_font);
	m_optionsmenu[1].setFillColor(sf::Color::White);
	m_optionsmenu[1].setString("Map Difficulty");
	m_optionsmenu[1].setPosition(sf::Vector2f(width / 2,
		height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	m_optionsmenu[2].setFont(m_font);
	m_optionsmenu[2].setFillColor(sf::Color::White);
	m_optionsmenu[2].setString("Save");
	m_optionsmenu[2].setPosition(sf::Vector2f(width / 2,
		height / (MAX_NUMBER_OF_ITEMS + 1) * 3));
	
	m_optionsmenu[3].setFont(m_font);
	m_optionsmenu[3].setFillColor(sf::Color::White);
	m_optionsmenu[3].setString("Exit");
	m_optionsmenu[3].setPosition(sf::Vector2f(width / 2,
		height / (MAX_NUMBER_OF_ITEMS + 1) * 4));

	//Initialize the selectedIndex
	selectedItemIndex = 0;

}

OptionsMenu::~OptionsMenu()
{
}
//Draw OptionsMenu
void OptionsMenu::RenderOptions(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS;i++)
	{
		window.draw(m_optionsmenu[i]);
	}
}
//Select Upp
void OptionsMenu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		m_optionsmenu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		m_optionsmenu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}
//Select Down
void OptionsMenu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
	{
		m_optionsmenu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		m_optionsmenu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}
