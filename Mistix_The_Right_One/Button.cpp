#include "Button.h"

Button::Button()
{
	if (button_texture.loadFromFile("Upgrade_attackspeedbutton.png"))
	{
		std::cout << "Successfully loaded Button Texture \n";

	}


	button_texture.setRepeated(true);
	this -> button_sprite.setTexture(button_texture);
}


Button::~Button()
{

}

bool Button::isClicked(sf::RenderWindow& window,sf::Event  &eventt)
{
	/*bool Button::isClicked(sf::RenderWindow & window)
	{
		sf::Vector2f mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

		if (this->getGlobalBounds().contains(mousePosition)
			&& event.type == sf::Event::MouseButtonReleased
			&& event.mouseButton.button == sf::Mouse::Left) //if clicked
		{
			return true;
		}
		else
		{
			return false;
		}
	}*/
	sf::Vector2f mousePosition = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
	if (this->button_sprite.getGlobalBounds().contains(mousePosition)
		&& eventt.type == sf::Event::MouseButtonReleased
		&& eventt.mouseButton.button == sf::Mouse::Right) //if clicked
	{
		return true;
	}
	else
	{
		return false;
	}
	
}
void Button::UpgradeBulletSpeed(Bullet& pocisk)
{
	if (pocisk.maxbulletTimer >= 20)
	{
		pocisk.maxbulletTimer -= 4;
	}
	else
	{
		std::cout << "Max amount of upgrades bought\n";
	}
	
}
void Button::ShowUpgradeButton(sf::RenderTarget& window,Score &wynik)
{
	if(wynik.getScore()>=this->UpgradeCost)
	{
		wynik.setValue(wynik.getScore() - this->UpgradeCost);
		
	}
	window.draw(this->button_sprite);
	
}
