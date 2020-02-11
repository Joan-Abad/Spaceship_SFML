#include "Asteroides.h"
#include "GraphicsUtils.h"
#include <iostream>
Asteroides::Asteroides(sf::Vector2i AsteroidSpawn, sf::Vector2f AsteroidSize)
{
	spr_Asteroid.setTexture(GraphicsUtils::InitializeTexture(tex_Asteroid, "Images/asteroid.png"));
	spr_Asteroid.setPosition(AsteroidSpawn.x, AsteroidSpawn.y);
	

	int random = rand() % 3 + 1;

	switch (random)
	{
		case 1:
			asteroidType = AsteroidsType::easy;
			asteroidSize = 0.05f;
			spr_Asteroid.setColor(sf::Color(255, 255, 255, 255));
			break;
		case 2:
			asteroidType = AsteroidsType::medium;
			asteroidSize = 0.1f;
			spr_Asteroid.setColor(sf::Color(255, 128, 0, 255));
			break;
		case 3:
			asteroidType = AsteroidsType::hard;
			asteroidSize = 0.2f;
			spr_Asteroid.setColor(sf::Color(87, 35, 100, 255));
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
	spr_Asteroid.move(sf::Vector2f(0.f, 0.05f));
}
