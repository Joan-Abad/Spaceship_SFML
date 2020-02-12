#include "NaveBullets.h"
#include "GraphicsUtils.h"
#include <iostream>
#include <memory>
#include "Nave.h"
#include "PowerUp_Speed.h"

NaveBullets::NaveBullets() = default;

NaveBullets::NaveBullets(int spawnPositionX, int spawnPositionY, Nave &nave)
{
	spr_bullets.setTexture(GraphicsUtils::InitializeTexture(tex_bullets, "laser.png"));
	spr_bullets.setPosition(spawnPositionX, spawnPositionY);
	spr_bullets.setScale(bulletSize, bulletSize);

	gamemode = &nave.owningWindow->gameMode;	
}



void NaveBullets::bulletMovement(Nave & nave)
{
	
	spr_bullets.move(0, -bulletSpeed);

	if (gamemode != nullptr)
	{
		CheckAsteroidsCollision(gamemode->GetAsteroidOnLevel(), nave);
	}
}

void NaveBullets::CheckAsteroidsCollision(std::vector<Asteroides*> &vec_Asteroids, Nave & nave)
{
	int checker = 0; 
	for (auto &asteroid : vec_Asteroids)
	{
		//WHEN BULLET COLLIDES ASTEROIDS
		if (spr_bullets.getGlobalBounds().intersects(asteroid->getAsteroid().getGlobalBounds()))
		{
			//IF ASTEROID HAS MORE THAN 1 HP
			if (asteroid->getLife() > 1)
				asteroid->setLifeAsteroid(damage);
			//IF ASTEROID IS DESTROYED
			else{

				//SPAWN POWERUP IF RAND IS INSIDE THE % OF CHANCE
				int spawn = rand() % 100 + 1;
				if (spawn < gamemode->chanceOfGettingPowerUp)
					gamemode->SpawnPowerUp(*asteroid);
	
				//DESTROY ASTEROIDS
				gamemode->asteroidDestroyed = true;
				nave.sumPoints(asteroid->getPoints());
				delete(asteroid);
				vec_Asteroids.erase(vec_Asteroids.begin() + checker);
			}
			//DELETE BULLET
			delete(this);
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





