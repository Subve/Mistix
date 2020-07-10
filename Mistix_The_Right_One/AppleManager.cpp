#include "AppleManager.h"
AppleManager::AppleManager()
{
	
}
void AppleManager::SpawnApple(std::vector<std::unique_ptr<Apple>>& jablka, sf::Time& elapsed_jablka,
	sf::Time& delta_jablka)
{
	if (elapsed_jablka >= delta_jablka)
	{
		int numer = jablka.size();
		auto apple_pozycja_x = static_cast<float>(rand() % 700+50);
		auto apple_pozycja_y = static_cast<float>(rand() % 500+50);
		jablka.emplace_back(std::make_unique<Apple>());
		jablka[numer]->setOrigin((jablka[numer]->getPosition().x + jablka[numer]->getGlobalBounds().width) / 2, (jablka[numer]->getPosition().y + jablka[numer]->getGlobalBounds().height) / 2);
		jablka[numer]->setPosition(apple_pozycja_x, apple_pozycja_y);
		elapsed_jablka -= delta_jablka;
	}
	
	
	
}

void AppleManager::RenderApples(sf::RenderTarget& window, std::vector<std::unique_ptr<Apple>>& jablka)
{
	
	for(int i=0;i<jablka.size();i++)
	{
		window.draw(*jablka[i]);
	}
}
