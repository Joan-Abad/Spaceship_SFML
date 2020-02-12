#include "PowerUp_Cadence.h"

PowerUp_Cadence::PowerUp_Cadence() : Power_ups("Images/Fire.png")
{
}

void PowerUp_Cadence::Activate(Nave & nave)
{
	nave.shootingCD = nave.initialShootingCD/2;
	sf::Clock * clock = new sf::Clock;
	nave.clockShootCadencePU = clock;
}
