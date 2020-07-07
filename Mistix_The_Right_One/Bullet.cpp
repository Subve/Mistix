#include "Bullet.h"

Bullet::Bullet(float radius):currVelocity(0.f, 0.f), maxSpeed(15.f)
{
	
	{	
		this->bullet.setRadius(radius);
		this->bullet.setFillColor(sf::Color::White);

	}
}

void Bullet::setAmmo(int n)
{
	maxbulletTimer = n;
}
void Bullet::setSpeed(float n)
{
	maxSpeed = n;
}
;
