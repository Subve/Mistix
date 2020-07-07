#include "LittleEnemy.h"

LittleEnemy::LittleEnemy() :Enemy()
{

	if (littleenemy_Texture.loadFromFile("tekstury/skeleton-attack_0.png"))
	{
		std::cout << "Successfully loaded LittleEnemy Texture \n";

	}
	littleenemy_Texture.setRepeated(true);
	this->setTexture(littleenemy_Texture);
	this->setScale(sf::Vector2f(0.1f, 0.15f));
	this->trafiony = false;
	this->zabity = false;

}

void LittleEnemy::Follow()
{
}

void LittleEnemy::Attack(Player& gracz)
{
}

void LittleEnemy::Rotate(sf::Vector2f& playerpos)
{
	this->enemyPos = this->getPosition();
	angle = static_cast<float>(-atan2(enemyPos.x - playerpos.x, enemyPos.y - playerpos.y) * 180 / 3.14159);
	this->setRotation(angle - 90);
}

void LittleEnemy::adMove(sf::Vector2f& vektorRuchu)
{
	this->move(-1 * vektorRuchu.x, -1 * vektorRuchu.y);
}

void LittleEnemy::setDirection(sf::Vector2u& direction2)
{
	direction.x = -1 * direction2.x;
	direction.y = -1 * direction2.y;
}

void LittleEnemy::setMove(sf::Vector2f& playermove)
{
	this->playerCenter = playermove;
	this->mousePosWindow = this->getPosition();
	this->aimDir =
		this->mousePosWindow - this->playerCenter;
	this->aimDirNorm = this->
		aimDir / (sqrt(pow(this->aimDir.x, 2) + pow(this->aimDir.y, 2)));
	/*enemies[i]->move(-1*(enemies[i]->aimDirNorm.x),-1*(enemies[i]->aimDirNorm.y));*/
	this->adMove(this->aimDirNorm);
}

void LittleEnemy::killedZombie(Score& wynik, std::vector<Bullet>& pociski, std::vector<std::unique_ptr<Enemy>>& enemies)
{
	{
		for (int j = 0;j < enemies.size();j++)
		{
			for (int i = 0;i < pociski.size();i++)
			{
				if (pociski[i].bullet.getGlobalBounds().intersects(this->getGlobalBounds()))
				{
					this->trafiony = true;
					if (trafiony == true && zabity == false)
					{
						std::cout << "Trafiony zombiak" << "\n";




						pociski.erase(pociski.begin() + i);
						this->zabity = true;
						if (zabity)
						{
							wynik.setaddPoint(1);
							wynik.addPoints();
							wynik.updateText();

						}
						/*enemies.erase(enemies.begin() + j);*/


					}


				}
			}
		}
	}
}
