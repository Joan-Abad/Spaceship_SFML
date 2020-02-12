#include "Asteroides.h"
#include "GraphicsUtils.h"
#include <iostream>
Asteroides::Asteroides(sf::Vector2i AsteroidSpawn, sf::Vector2f AsteroidSize)
{
	spr_Asteroid.setTexture(GraphicsUtils::InitializeTexture(tex_Asteroid, "Images/asteroid.png"));
	spr_Asteroid.setPosition(AsteroidSpawn.x, AsteroidSpawn.y);
	

	int random = rand() % 10 + 1;

	switch (random)
	{
		case 1:
		case 2:
		case 3: 
		case 4: 
		case 5:
		case 6:
			asteroidType = AsteroidsType::easy;
			asteroidSize = 0.1;
			spr_Asteroid.setColor(sf::Color(255, 255, 255, 255));
			life = 1; 
			asteroidMovementSpeed = 0.2;
			points = 10;
			break;
		case 7: 
		case 8: 
		case 9:
			asteroidType = AsteroidsType::medium;
			asteroidSize = 0.2;
			spr_Asteroid.setColor(sf::Color(255, 128, 0, 255));
			life = 2; 
			asteroidMovementSpeed = 0.1;
			points = 20;
			break;
		case 10:
			asteroidType = AsteroidsType::hard;
			asteroidSize = 0.3;
			spr_Asteroid.setColor(sf::Color(187, 0, 0, 255));
			asteroidMovementSpeed = 0.05;
			points = 30;
			life = 3; 
			break;
		default: 
			std::cerr << "Error en random, fuera de rango.\n";
	}

	spr_Asteroid.setScale(asteroidSize, asteroidSize);
}

void Asteroides::setLifeAsteroid(int damage)
{
	life -= damage;
}

void Asteroides::AsteroidMovement()
{
	spr_Asteroid.move(sf::Vector2f(0.f, asteroidMovementSpeed));
}
