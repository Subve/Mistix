#include "Button.h"

Button::Button()
{
	if (button_texture.loadFromFile("tekstury/Upgrade_attackspeedbutton.png"))
	{
		std::cout << "Successfully loaded Button Texture \n";

	}


	button_texture.setSmooth(true);
	this->button_sprite.setTexture(button_texture);
	this->button_sprite.setPosition(300.0f, 536.0f);
}


Button::~Button()
{

}

bool Button::isClicked(sf::RenderWindow& window, Score& wynik)
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
	sf::Vector2f mousePosition2 = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
	if (this->button_sprite.getGlobalBounds().contains(mousePosition2)&&
	(sf::Mouse::isButtonPressed(sf::Mouse::Right))&& wynik.getScore() >= this->UpgradeCost) //if clicked
	{
		return true;
	}
	else
	{
		return false;
	}

}
void Button::UpgradeBulletSpeed(Bullet& pocisk,Score& wynik)
{
	if (wynik.getScore() >= this->UpgradeCost)
	{
		if (pocisk.maxbulletTimer >= 20)
		{
			pocisk.maxbulletTimer -= 4;
		}
		else
		{
			std::cout << "Max amount of upgrades bought\n";
		}
		wynik.setValue(wynik.getScore() - this->UpgradeCost);

	}


}
void Button::RenderUpgradeButton(sf::RenderTarget& window,Score&wynik, Bullet& pocisk)
{
	if (pocisk.maxbulletTimer >= 20)
	{
		if(wynik.getScore() >= this->UpgradeCost)
			window.draw(this->button_sprite);
	}

}
