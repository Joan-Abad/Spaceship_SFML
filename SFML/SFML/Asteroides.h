#pragma once
#include "SFML/Graphics.hpp"
class Asteroides
{
private: 
	sf::RectangleShape asteroid; 
	//ASTEROID SPEED
	float asteroidMovementSpeed = 0; 

	sf::Texture tex_Asteroid; 
	sf::Sprite spr_Asteroid; 

public: 
	Asteroides(sf::Vector2i AsteroidSpawn, sf::Vector2f AsteroidSize);

	sf::Sprite getAsteroid() { return spr_Asteroid; }

	void AsteroidMovement();
};

