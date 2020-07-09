#include "BigEnemy.h"

BigEnemy::BigEnemy() :Enemy()
{

	if (bigenemy_Texture.loadFromFile("tekstury/Zombie_evolution.png"))
	{
		std::cout << "Successfully loaded BigEnemy Texture \n";

	}
	else
	{
		std::cout << "BigEnemy texture Failed to load\n";
	}


	bigenemy_Texture.setRepeated(true);
	this->setTexture(bigenemy_Texture);
	this->setScale(sf::Vector2f(0.1f, 0.15f));
	this->trafiony = false;
	this->zabity = false;

	this->polaczone = true;
}

void BigEnemy::Follow()
{
}

void BigEnemy::Attack(Player& gracz)
{
}

void BigEnemy::Rotate(sf::Vector2f& playerpos)
{
	this->enemyPos = this->getPosition();
	angle = static_cast<float>(-atan2(enemyPos.x - playerpos.x, enemyPos.y - playerpos.y) * 180 / 3.14159);
	this->setRotation(angle - 90);
}

void BigEnemy::adMove(sf::Vector2f& vektorRuchu)
{
	this->move(-1 * vektorRuchu.x, -1 * vektorRuchu.y);
}

void BigEnemy::setDirection(sf::Vector2u& direction2)
{
	direction.x = -1 * direction2.x;
	direction.y = -1 * direction2.y;
}

void BigEnemy::setMove(sf::Vector2f& playermove)
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

void BigEnemy::killedZombie(Score& wynik, std::vector<Bullet>& pociski, std::vector<std::unique_ptr<Enemy>>& enemies)
{
	{
		for (int j = 0;j < enemies.size();j++)
		{
			for (int i = 0;i < pociski.size();i++)
			{
				if (pociski[i].bullet.getGlobalBounds().intersects(enemies[j]->getGlobalBounds()))
				{
					enemies[j]->setTrafiony();
					if (trafiony && !zabity)
					{
						std::cout << "Trafiony zombiak" << "\n";




						pociski.erase(pociski.begin() + i);
						enemies[j]->HP -= 1;;


						/*enemies.erase(enemies.begin() + j);*/


					}
					if (enemies[j]->HP == 0)
					{
						enemies[j]->setZabity();
					}
					if (trafiony && zabity)
					{
						enemies.erase(enemies.begin() + j);

						wynik.setaddPoint(1);
						wynik.addPoints();
						wynik.updateText();
					}


				}
			}
		}
	}
}

void BigEnemy::setTrafiony()
{
	if (!trafiony && !zabity)
		this->trafiony = true;
}

void BigEnemy::setZabity()
{
	if (trafiony && !zabity)
		this->zabity = true;
}

void BigEnemy::setID(int& i)
{

	this->mobID = i;

}




