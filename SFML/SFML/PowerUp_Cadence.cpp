#include "PowerUp_Cadence.h"
#include "GraphicsUtils.h"
PowerUp_Cadence::PowerUp_Cadence() : Power_ups("Images/Fire.png", "Audio/Firerate.wav")
{
}

void PowerUp_Cadence::Activate(Nave & nave, GameMode &gameMode)
{
	Power_ups::Activate(nave, gameMode);
	nave.shootingCD = nave.initialShootingCD/2;
	sf::Clock * clock = new sf::Clock;
	nave.clockShootCadencePU = clock;
	gameMode.powerUpPickedFirerate = true; 
}
