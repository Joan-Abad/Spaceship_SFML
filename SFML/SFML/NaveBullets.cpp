#include "NaveBullets.h"
#include "GraphicsUtils.h"
#include <iostream>
#include <memory>

NaveBullets::NaveBullets() = default;

NaveBullets::NaveBullets(int spawnPositionX, int spawnPositionY)
{
	spr_bullets.setTexture(GraphicsUtils::InitializeTexture(tex_bullets, "laser.png"));
	spr_bullets.setPosition(spawnPositionX, spawnPositionY);
	spr_bullets.setScale(0.5f,0.5f);

	//gamemode = &(nave.owningWindow->getGameMode());
}



void NaveBullets::bulletMovement()
{
	
	spr_bullets.move(0, -bulletSpeed);

	//if(gamemode)
	//CheckAsteroidsCollision(gamemode->levelAsteroids);
}

void NaveBullets::CheckAsteroidsCollision(std::vector<Asteroides*> vec_Asteroids)
{
	for (auto &asteroid : vec_Asteroids)
	{
		if (spr_bullets.getGlobalBounds().intersects(asteroid->getAsteroid().getGlobalBounds()))
		{
			std::cout << "COLLIDING WITH AN ASTEROID BRUUUUH";
		}
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





