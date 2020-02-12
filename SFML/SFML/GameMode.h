#pragma once
#include "Asteroides.h"
#include <vector>
#include "SFML/Audio.hpp"
#include "Power_ups.h"

class GameMode
{
private: 

	//Asteroids timers
	sf::Clock clock_Asteroids;
	sf::Time time_Asteroids; 
	float AsteroidSpawnCD = 700.f; // IN MILI SECONDS
	std::vector<Asteroides*> levelAsteroids;

	sf::Sound sound;
	sf::SoundBuffer buffer;


public: 
	//Constructors
	GameMode();

	//Main
	void Main(sf::RenderWindow & window);

	//ASTEROIDS
	bool asteroidDestroyed = false;
	std::vector<Asteroides*> &GetAsteroidOnLevel();
	void drawAsteroids(sf::RenderWindow &window);
	void MoveAllAsteroids(sf::RenderWindow & window);
	void SpawnAsteroidsRandomlly(sf::RenderWindow & window);

	//Powerups
	Power_ups * Power_up_ToSpawn = nullptr;
	std::vector <Power_ups*> PowerUpsOnLevel;
	void SpawnPowerUp(Asteroides asteroid);

	// Chance must be between 0 and 100
	int chanceOfGettingPowerUp = 10;

	//SOUNDS
	void checkSoundsToPlay();
	void drawPowerups(sf::RenderWindow &window);

	

};

