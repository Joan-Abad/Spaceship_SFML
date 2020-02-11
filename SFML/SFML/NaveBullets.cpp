#include "NaveBullets.h"
#include "GraphicsUtils.h"
#include <iostream>
#include <memory>

NaveBullets::NaveBullets() = default;

NaveBullets::NaveBullets(int spawnPositionX, int spawnPositionY, Nave &nave)
{
	spr_bullets.setTexture(GraphicsUtils::InitializeTexture(tex_bullets, "laser.png"));
	spr_bullets.setPosition(spawnPositionX, spawnPositionY);
	spr_bullets.setScale(bulletSize, bulletSize);

	gamemode = &nave.owningWindow->gameMode;	
}



void NaveBullets::bulletMovement()
{
	
	spr_bullets.move(0, -bulletSpeed);

	if (gamemode != nullptr)
	{
		CheckAsteroidsCollision(gamemode->getAllAsteroids());
	}
}

void NaveBullets::CheckAsteroidsCollision(std::vector<Asteroides*> &vec_Asteroids)
{
	int checker = 0; 
	for (auto &asteroid : vec_Asteroids)
	{
		if (spr_bullets.getGlobalBounds().intersects(asteroid->getAsteroid().getGlobalBounds()))
		{
			delete(asteroid);
			vec_Asteroids.erase(vec_Asteroids.begin() + checker);
			delete(this);
			checker--;
		}
		checker++;
	}
}


sf::Sprite & NaveBullets::getBulletSprite()
{
	return spr_bullets;
}

float NaveBullets::bulletLifeTime()
{
	bulletTime = bulletClock.getElapsedTime(); 

	return bulletTime.asSeconds();
}





