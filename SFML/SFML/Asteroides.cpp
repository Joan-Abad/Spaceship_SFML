#include "Asteroides.h"

Asteroides::Asteroides(sf::Vector2i AsteroidSpawn, sf::Vector2f AsteroidSize)
{
	asteroid.setSize(sf::Vector2f(AsteroidSize.x, AsteroidSize.y));
	asteroid.setFillColor(sf::Color::Red);
	asteroid.setPosition(AsteroidSpawn.x, AsteroidSpawn.y);
	
}

void Asteroides::AsteroidMovement()
{
	asteroid.move(sf::Vector2f(0.f, 0.05f));
}
