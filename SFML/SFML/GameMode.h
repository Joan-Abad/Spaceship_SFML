#pragma once
#include "Asteroides.h"
#include <vector>
#include "SFML/Audio.hpp"

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

	bool asteroidDestroyed = false;

	GameMode();

	std::vector<Asteroides*> &getAllAsteroids();

	void drawAsteroids(sf::RenderWindow &window);

	void MoveAllAsteroids(sf::RenderWindow & window);
	
	void SpawnAsteroidsRandomlly(sf::RenderWindow & window);

	void Main(sf::RenderWindow & window);

	void checkSoundsToPlay();
};

