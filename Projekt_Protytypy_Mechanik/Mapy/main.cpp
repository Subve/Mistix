#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <sstream>

int main()
{
	sf::Texture tileTexture;
	sf::Sprite tiles;

	
	std::vector<std::vector<sf::Vector2i>> map;
	std::vector<sf::Vector2i> tempMap;
	


	std::ifstream openfile("Map1.txt");
	if (openfile.is_open())
	{
		std::string tileLocation;
		openfile >> tileLocation;
		tileTexture.loadFromFile(tileLocation);
		tiles.setTexture(tileTexture);

		while (!openfile.eof())
		{
			std::string str, value;
			std::getline(openfile, str);
			std::stringstream stream(str);
			while (std::getline(stream, value, ' '))
			{
				if (value.length() > 0)
				{
					std::string xx = value.substr(0, value.find(','));
					std::string yy = value.substr(value.find(',') + 1);

					int x, y, i, j;
					for (i = 0; i < xx.length();i++)
					{
						if (!isdigit(xx[i]))
							break;
					}
					for (j = 0;j < yy.length();j++)
					{
						if (!isdigit(yy[j]))
							break;
					}
					x = (i == xx.length()) ? atoi(xx.c_str()) : -1;
					y = (j == yy.length()) ? atoi(yy.c_str()) : -1;

					tempMap.push_back(sf::Vector2i(x, y));
				}
			}
			
				map.push_back(tempMap);
				tempMap.clear();
			}
			
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

		for (int i = 0; i < map.size();i++)
		{
			for (int j = 0;j<map[i].size();j++)
			{
				if (map[i][j].x != -1 && map[i][j].y != -1)
				{
					tiles.setPosition(j *32, i * 32);
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