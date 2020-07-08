#include "HighScore.h"

HighScore::HighScore()
{	
	highscore_Font.loadFromFile("fonts/arial.ttf");
	if (highscore_Font.loadFromFile("fonts/arial.ttf"))
	{
		std::cout << "Highscore font loaded successfully \n";
	}
	else
	{
		std::cout << " Highscore font FAILED TO LOAD \n";
	}


	this->highscore_Text.setFont(highscore_Font);
	this->highscore_Text.setCharacterSize(24);
	this->highscore_Text.setPosition(10, 30);
	this->loadHighscore();
	this->showText();
	
}

HighScore::~HighScore()
{

}

void HighScore::updateHighScore(Score& obj)
{
	if (obj.getScore() > this->getHighscore())
	{
		 this->setHighscore(obj);
		 ssHighScore.str("");
		 ssHighScore.clear();
		 this->ssHighScore << "Points : " << this->getHighscore();
		 this->highscore_Text.setString(ssHighScore.str());
	}
}

void HighScore::renderHighscore(sf::RenderTarget &window)
{
	window.draw(this->highscore_Text);
}



int HighScore::getHighscore()
{
	return this->m_highscore;
}

int HighScore::setHighscore(Score& obj)
{
	
	return this->m_highscore=obj.getScore();

}

void HighScore::loadHighscore()
{
	std::ifstream readFile;
	readFile.open("data/Highscore.txt");

	if(readFile.is_open())
	{
		while (!readFile.eof())
		{
			readFile >> m_highscore;
		}
	}
	readFile.close();
}

void HighScore::saveHighScore(Score& obj)
{
	std::ofstream writeFile("data/Highscore.txt");
	writeFile << m_highscore;
	writeFile.close();

}

void HighScore::showText()
{
	ssHighScore.str("");
	ssHighScore.clear();
	this->ssHighScore << "Best  : " << this->getHighscore();
	this->highscore_Text.setString(ssHighScore.str());
}
