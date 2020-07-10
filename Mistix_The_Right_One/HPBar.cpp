#include "HPBar.h"

HPBar::HPBar()
{
}

void HPBar::inithpbartext(Player& gracz)
{
	
	this->hpBarString <<"HP : "<< gracz.m_playerHealth << " / 100 ";
	this->hpBarText.setString(hpBarString.str());
	bh_font.loadFromFile("fonts/arial.ttf");
	if(!bh_font.loadFromFile("fonts/arial.ttf"))
	{
		std::cout << "Failed to load HP BAR FONT !!!!!!!\n";
	}
	else
	{
		std::cout << "Successfully loaded HP Bar Font.\n";
	}
	this->hpBarText.setFont(bh_font);
	this->hpBarText.setPosition(10, 541);
}

void HPBar::initHPBAR(Player& gracz)
{
	
	this->inithpbarback();
	this->inithpbarfront();
	this->inithpbartext(gracz);
}

void HPBar::inithpbarback()
{
	float width = 300;
	float height = 64;
	float y = 536;
	float x = 0;
	this->hpBarBack.setSize(sf::Vector2f(width, height));
	this->hpBarBack.setFillColor(sf::Color(125,125,125,200));
	this->hpBarBack.setPosition(x, y);	
}

void HPBar::inithpbarfront()
{
	float width = 300;
	float height = 64;
	float y = 536;
	float x = 0;
	this->hpBarFront.setSize(sf::Vector2f(width, height));
	this->hpBarFront.setFillColor(sf::Color::Green);
	this->hpBarFront.setPosition(x, y);
}

void HPBar::UpdateHP(Player& gracz)
{
	
	hpBarString.str("");
	hpBarString.clear();
	this->hpBarString << "HP : " << gracz.m_playerHealth << " / 100 ";
	this->hpBarText.setString(hpBarString.str());
	if(gracz.m_playerHealth>=100)
		this->hpBarFront.setSize(sf::Vector2f(300 * 100 / 100, 64));
	this->hpBarFront.setSize(sf::Vector2f(300*gracz.m_playerHealth/100,64));
	if (gracz.m_playerHealth > 50)
		this->hpBarFront.setFillColor(sf::Color::Green);
	else if (gracz.m_playerHealth > 20)
		this->hpBarFront.setFillColor(sf::Color(255, 127, 80));
	else
		this->hpBarFront.setFillColor(sf::Color::Red);
	
}

void HPBar::RenderHPBar(sf::RenderTarget& window1)
{
	window1.draw(hpBarBack);
	window1.draw(hpBarFront);
	window1.draw(hpBarText);
}

