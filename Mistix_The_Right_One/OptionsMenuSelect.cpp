#include "OptionsMenuSelect.h"

OptionsMenuSelect::OptionsMenuSelect(float width, float height)
{
	if (!m_font.loadFromFile("fonts/arial.ttf"))
	{
		std::cout << "Error while loading options menu font\n";
	}

	//Creating menu Tiles
	m_optionsmenumenu[0].setFont(m_font);
	m_optionsmenumenu[0].setFillColor(sf::Color::Red);
	m_optionsmenumenu[0].setString("OFF");
	m_optionsmenumenu[0].setPosition(sf::Vector2f(width / 2+100,
		height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	m_optionsmenumenu[1].setFont(m_font);
	m_optionsmenumenu[1].setFillColor(sf::Color::White);
	m_optionsmenumenu[1].setString("50%");
	m_optionsmenumenu[1].setPosition(sf::Vector2f(width / 2+200,
		height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	m_optionsmenumenu[2].setFont(m_font);
	m_optionsmenumenu[2].setFillColor(sf::Color::White);
	m_optionsmenumenu[2].setString("100%");
	m_optionsmenumenu[2].setPosition(sf::Vector2f(width / 2+300,
		height / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	m_optionsmenumenu[3].setFont(m_font);
	m_optionsmenumenu[3].setFillColor(sf::Color::White);
	m_optionsmenumenu[3].setString("Normal");
	m_optionsmenumenu[3].setPosition(sf::Vector2f(width / 2+100,
		height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	m_optionsmenumenu[4].setFont(m_font);
	m_optionsmenumenu[4].setFillColor(sf::Color::White);
	m_optionsmenumenu[4].setString("Hard");
	m_optionsmenumenu[4].setPosition(sf::Vector2f(width / 2+200,
		height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	m_optionsmenumenu[5].setString("");

	//Initialize the selectedIndex
	selectedItemOptionsIndex = 0;
}

OptionsMenuSelect::~OptionsMenuSelect()
{
}

void OptionsMenuSelect::MoveLeft()
{
	if (selectedItemOptionsIndex - 1 >= 0)
	{
		m_optionsmenumenu[selectedItemOptionsIndex].setFillColor(sf::Color::White);
		selectedItemOptionsIndex--;
		m_optionsmenumenu[selectedItemOptionsIndex].setFillColor(sf::Color::Red);
	}
}

void OptionsMenuSelect::MoveRight()
{
	if (selectedItemOptionsIndex + 1 < MAX_NUMBER_OF_OPTIONS)
	{
		m_optionsmenumenu[selectedItemOptionsIndex].setFillColor(sf::Color::White);
		
			selectedItemOptionsIndex++;
		if(selectedItemOptionsIndex!=5)
		{
			m_optionsmenumenu[selectedItemOptionsIndex].setFillColor(sf::Color::Red);
		}
		
	}
}

void OptionsMenuSelect::loadConfig()
{
}

void OptionsMenuSelect::saveConfig()
{
}

void OptionsMenuSelect::RenderOptions(sf::RenderWindow& window)
{
	for (int i = 0; i < MAX_NUMBER_OF_OPTIONS;i++)
	{
		window.draw(m_optionsmenumenu[i]);
	}
}
