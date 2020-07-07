#include "CustomMouse.h"

CustomMouse::CustomMouse()
{
	m_mouseTexture.loadFromFile("tekstury/Aim.png");
	if (m_mouseTexture.loadFromFile("tekstury/Aim.png"))
	{
		std::cout << "Successfully loaded Cursor Texture \n";

	}
	m_mouseTexture.setRepeated(true);
	this->m_mouseSprite.setTexture(m_mouseTexture);
	this->m_mouseSprite.setOrigin(this->m_mouseSprite.getGlobalBounds().width / 2, this->m_mouseSprite.getGlobalBounds().height / 2);
	this->m_mouseSprite.setScale(0.125f, 0.125f);
	this->m_mouseSprite.setPosition(mousePosWindow.x, mousePosWindow.y);
}

void CustomMouse::mouseUpdate()
{
	this->m_mouseSprite.setPosition(mousePosWindow.x, mousePosWindow.y);
}

void CustomMouse::mouseRender(sf::RenderWindow& window)
{
	window.draw(this->m_mouseSprite);
}
