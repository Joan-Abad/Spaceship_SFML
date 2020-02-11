#include "Asteroides.h"
#include "GraphicsUtils.h"

Asteroides::Asteroides(sf::Vector2i AsteroidSpawn, sf::Vector2f AsteroidSize)
{
	spr_Asteroid.setTexture(GraphicsUtils::InitializeTexture(tex_Asteroid, "Images/asteroid.png"));
	spr_Asteroid.setPosition(AsteroidSpawn.x, AsteroidSpawn.y);
	spr_Asteroid.setScale(0.2f, 0.2f);
}

void Asteroides::AsteroidMovement()
{
	spr_Asteroid.move(sf::Vector2f(0.f, 0.05f));
}
