#include "Score.h"

Score::Score()
{
	score_Font.loadFromFile("fonts/arial.ttf");
	if (score_Font.loadFromFile("fonts/arial.ttf"))
	{
		std::cout << "Score font loaded successfully \n";
	}
	else
	{
		std::cout << " Score font FAILED TO LOAD \n";
	}


	this->score_Text.setFont(score_Font);
	this->score_Text.setCharacterSize(24);
	this->score_Text.setPosition(10, 10);
	this->updateText();
}

void Score::updateText()
{
	ssScore.str("");
	ssScore.clear();
	this->ssScore << "Points : " << this->value;
	this->score_Text.setString(ssScore.str());
}

void Score::setValue(int n)
{
	value = n;
}

void Score::pointsRender(sf::RenderWindow& window)
{
	window.draw(this->score_Text);
}

int Score::getScore()
{
	return this->value;
}

void Score::setaddPoint(float n)
{
	m_addValue = static_cast<int>(n);
}

void Score::addPoints()
{
	value += m_addValue;
}
