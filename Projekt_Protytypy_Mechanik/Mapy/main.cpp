#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

int main()
{
	sf::Texture tileTexture;
	sf::Sprite tiles;

	sf::Vector2i map[100][100];
	sf::Vector2i loadCounter = sf::Vector2i(0, 0);


	std::ifstream openfile("Map1.txt");
	if (openfile.is_open())
	{
		std::string tileLocation;
		openfile >> tileLocation;
		tileTexture.loadFromFile(tileLocation);
		tiles.setTexture(tileTexture);

		while (!openfile.eof())
		{
			std::string str;
			openfile >> str;
			char x = str[0];
			char y = str[2];

			if (!isdigit(x) || !isdigit(y))
			{
				map[loadCounter.x][loadCounter.y] = sf::Vector2i(-1, -1);

			}
			else
			{

				map[loadCounter.x][loadCounter.y] = sf::Vector2i(x - '0', y - '0');

			}
			if (openfile.peek() == '\n')
			{
				loadCounter.x = 0;
				loadCounter.y++;
			}
			else
			{
				loadCounter.x++;
			}
		}

		loadCounter.y++;

	}

	sf::RenderWindow window(sf::VideoMode(640, 480, 32), "Loading maps[easy]");
	while (window.isOpen())
	{
		sf::Event Event;
		while (window.pollEvent(Event))
		{
			switch (Event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			}
		}

		window.clear(sf::Color::Cyan);

		for (int i = 0; i < loadCounter.x;i++)
		{
			for (int j = 0;j<loadCounter.y;j++)
			{
				if (map[i][j].x != -1 && map[i][j].y != -1)
				{
					tiles.setPosition(i *32, j * 32);
					tiles.setTextureRect(sf::IntRect(map[i][j].x * 32,
						map[i][j].y * 32, 32, 32));
					window.draw(tiles);
					std::cout << "Creating a tiles\n";
				}
			}
		}

		window.display();

	}
}