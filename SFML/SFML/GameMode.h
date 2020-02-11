#pragma once
#include "Asteroides.h"
#include <vector>

class GameMode
{
private: 

	//Asteroids timers
	sf::Clock clock_Asteroids;
	sf::Time time_Asteroids; 

	float AsteroidSpawnCD = 700.f; // IN MILI SECONDS

	std::vector<Asteroides*> levelAsteroids;
	
public: 

	GameMode();

	std::vector<Asteroides*> &getAllAsteroids();

	void drawAsteroids(sf::RenderWindow &window);

	void MoveAllAsteroids(sf::RenderWindow & window);
	
	void SpawnAsteroidsRandomlly(sf::RenderWindow & window);

	void Main(sf::RenderWindow & window);
};

