#pragma once
#include "SFML/Graphics.hpp"
class Asteroides
{
private: 
	sf::RectangleShape asteroid; 
	//ASTEROID SPEED
	float asteroidMovementSpeed = 0; 

public: 
	Asteroides(sf::Vector2i AsteroidSpawn, sf::Vector2f AsteroidSize);

	sf::RectangleShape getAsteroid() { return asteroid; }

	void AsteroidMovement();
};

