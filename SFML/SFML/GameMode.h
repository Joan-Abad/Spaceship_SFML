#pragma once
#include "Asteroides.h"
#include <vector>

class GameMode
{
private: 

	//Asteroids timers
	sf::Clock clock_Asteroids;
	sf::Time time_Asteroids; 

	float AsteroidSpawnCD = 700.f;

	
public: 

	GameMode();

	std::vector<Asteroides*> levelAsteroids; 

	void drawAsteroids(sf::RenderWindow &window);

	void MoveAllAsteroids();
	
	void SpawnAsteroidsRandomlly(sf::RenderWindow & window);

	void Main();


};

