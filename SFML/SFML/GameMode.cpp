#include "GameMode.h"
#include <cstdlib>
#include <iostream>
#include "GraphicsUtils.h"

GameMode::GameMode()
{

}

std::vector<Asteroides*>& GameMode::getAllAsteroids()
{
	return levelAsteroids;
}

void GameMode::drawAsteroids(sf::RenderWindow & window)
{
	for (auto &asteroid : levelAsteroids)
	{
		if(asteroid)
		window.draw(asteroid->getAsteroid());
	}
}

void GameMode::MoveAllAsteroids(sf::RenderWindow & window)
{
	int checker = 0; 
	if (!levelAsteroids.empty())
	{
		for (auto &c : levelAsteroids)
		{
			c->AsteroidMovement();
			if (c->getAsteroid().getPosition().y > window.getSize().y)
			{
				delete(c);
				levelAsteroids.erase(levelAsteroids.begin() + checker);
			}
			checker++;
		}
	}

}

void GameMode::SpawnAsteroidsRandomlly(sf::RenderWindow & window)
{
	//GET ELAPSED TIME FOR NEW ASTEROID SPAWN
	time_Asteroids = clock_Asteroids.getElapsedTime(); 
	
	if (time_Asteroids.asMilliseconds() > AsteroidSpawnCD)
	{
		//ASTEROID SPAWN VARIABLE FOR CONSTRUCTOR WHO SETS POSITION ON SCRREN 
		int randomSpawnX = rand() % (window.getSize().x - window.getSize().x/10);
		int randomSpawnY = (rand() % 200 + 50) * -1;
		sf::Vector2i AsteroidPosition = { randomSpawnX, randomSpawnY };

		//SET ASTEROID SIZE
		int randomSizeX = rand() % 50 + 40; 
		int randomSizeY = rand() % 50 + 40;
		sf::Vector2f AsteroidSize(randomSizeX, randomSizeY);

		//CREATE ASTEROID ON GIVEN VARIABLES AND STORE IT ON VECTOR
		Asteroides *asteroid = new Asteroides(AsteroidPosition, AsteroidSize);
		levelAsteroids.push_back(asteroid);		

		//RESET SPAWN COOLDOWN FOR NEW ASTEROID 
		clock_Asteroids.restart();
	}
}

void GameMode::Main(sf::RenderWindow & window)
{
	//Asteroid Movement
	MoveAllAsteroids(window);
}

void GameMode::checkSoundsToPlay()
{
	if (asteroidDestroyed == true)
	{
		GraphicsUtils::playSound(buffer, sound, "Audio/Asteroid.wav", 100, false);
		asteroidDestroyed = false;
	}
}
