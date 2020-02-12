#pragma once
#include "SFML/Graphics.hpp"

enum AsteroidsType
{
	easy,
	medium,
	hard
};

class Asteroides
{
private: 

	//Graphics
	sf::Texture tex_Asteroid;
	sf::Sprite spr_Asteroid;

	//Initial values
	float asteroidMovementSpeed = 0; 
	float damage = 0.3f;
	int points = 10; 
	float asteroidSize;
	int life = 2; 
	AsteroidsType asteroidType;
	

public: 
	//Constructors
	Asteroides(sf::Vector2i AsteroidSpawn, sf::Vector2f AsteroidSize);

	//Getters
	sf::Sprite getAsteroid() { return spr_Asteroid; }
	inline float getDamage() { return damage; }
	inline int getPoints() { return points;  }
	inline int getLife() { return life;  }

	//Setters
	void setLifeAsteroid(int damage);

	//Gameplay
	void AsteroidMovement();

	

};

