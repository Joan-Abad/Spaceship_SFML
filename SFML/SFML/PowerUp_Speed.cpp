#include "PowerUp_Speed.h"

int Power_ups::LifeTimePowerUp = 4;

PowerUp_Speed::PowerUp_Speed() : Power_ups("Images/Speed.png")
{
}

void PowerUp_Speed::Activate(Nave & nave)
{
	nave.ChangeNaveSpeed(0.2);
	sf::Clock * clock = new sf::Clock;
	nave.clockSpeedPU = clock;
}
