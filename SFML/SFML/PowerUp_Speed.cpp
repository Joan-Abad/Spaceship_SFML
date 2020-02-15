#include "PowerUp_Speed.h"
#include "GraphicsUtils.h"
int Power_ups::LifeTimePowerUp = 4;

PowerUp_Speed::PowerUp_Speed() : Power_ups("Images/Speed.png","Audio/Speed.wav")
{
}

void PowerUp_Speed::Activate(Nave & nave, GameMode &gameMode)
{
	Power_ups::Activate(nave,gameMode);
	nave.ChangeNaveSpeed(0.2);

	sf::Clock * clock = new sf::Clock;
	nave.clockSpeedPU = clock;

	gameMode.powerUpPickedSpeed = true; 
}
