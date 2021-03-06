#include "GameMode.h"
#include <cstdlib>
#include <iostream>
#include "GraphicsUtils.h"
#include "PowerUp_Speed.h"
#include "PowerUp_Cadence.h"
#include "PowerUp_Shield.h"
#include "AI.h"

GameMode::GameMode()
{

}

std::vector<Asteroides*>& GameMode::GetAsteroidOnLevel()
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

void GameMode::spawnAIRandomlly(int anchura, int altura, sf::RenderWindow &window)
{
	time_AiSpawn = clock_AiSpawn.getElapsedTime();
	if (time_AiSpawn.asSeconds() > secondsToSpawnAI && levelAI.size() < maxNumberOfAI)
	{
		AI *artificialInteligence = new AI(anchura,altura,window);
		levelAI.push_back(artificialInteligence);
		clock_AiSpawn.restart();
	}
}

void GameMode::drawAllAI(sf::RenderWindow & window)
{
	if(!levelAI.empty())
	{
		for (auto &a : levelAI)
		{
			if(a->dead == false)
			{
				//a->AIMovement(window.getSize().x);
				window.draw(a->getSprite());	
				window.draw(a->getBulletSprite());
			}
		}
	}
}

void GameMode::moveAllAI(int anchuraPantalla, int alturaPantalla)
{
	if(!levelAI.empty())
	{
		for (auto &a : levelAI)
		{
			a->AIMovement(anchuraPantalla, alturaPantalla);
			a->AIShootBullet();
		}
	}
}
std::vector<AI*>& GameMode::GetAiOnLevel()
{
	return levelAI;
}

void GameMode::checkPlayerCollisionWithAIOnLevel(Nave & nave)
{
	if (!levelAI.empty())
	{
		for (auto &a : levelAI)
		{
			a->checkCollisionWithPlayer(nave);
			a->checkBulletsCollisionWithPlayer(nave);
		}
	}
}

void GameMode::SpawnPowerUp(Asteroides asteroid)
{
	int randPowerup = rand() % 3 + 1;

	if (randPowerup == 1)
		Power_up_ToSpawn = new PowerUp_Speed;
	else if (randPowerup == 2)
		Power_up_ToSpawn = new PowerUp_Cadence;
	else if (randPowerup == 3)
		Power_up_ToSpawn = new PowerUp_Shield;

	Power_up_ToSpawn->getSpritePowerUp().setPosition(asteroid.getAsteroid().getPosition());

	PowerUpsOnLevel.push_back(Power_up_ToSpawn);
}

void GameMode::Main(sf::RenderWindow & window)
{
	//Spawn asteroids randomlly above the map
	SpawnAsteroidsRandomlly(window);

	//Asteroid Movement
	MoveAllAsteroids(window);

	//Sounds
	checkSoundsToPlay();
}

void GameMode::checkSoundsToPlay()
{

	if (asteroidDestroyed == true)
	{
		GraphicsUtils::playSound(buffer, sound, "Audio/Asteroid.wav", 100, false);
		asteroidDestroyed = false;
	}

	if (powerUpPickedSpeed == true)
	{
		GraphicsUtils::playSound(soundBufferPowerUps, soundPowerUps, "Audio/Speed.wav", 100, false);
		powerUpPickedSpeed = false;
	}

	if (powerUpPickedFirerate == true)
	{
		GraphicsUtils::playSound(soundBufferPowerUps, soundPowerUps, "Audio/Firerate.wav", 100, false);
		powerUpPickedFirerate = false;
	}

	if (powerUpPickedShield == true)
	{
		GraphicsUtils::playSound(soundBufferPowerUps, soundPowerUps, "Audio/Shield.wav", 100, false);
		powerUpPickedShield = false;
	}
	if (AI_Destroyed == true)
	{
		GraphicsUtils::playSound(buffer, sound, "Audio/AI_dead.wav", 100, false);
		AI_Destroyed = false; 

	}

}

void GameMode::drawPowerups(sf::RenderWindow & window)
{
	if (!PowerUpsOnLevel.empty())
	{
		for (auto a : PowerUpsOnLevel)
		{
			window.draw(a->getSpritePowerUp());
		}
	}
}

void GameMode::createNewSound(sf::Sound soundToCopy)
{
	this->soundPowerUps = soundToCopy;
	std::cout << "asd";
}
