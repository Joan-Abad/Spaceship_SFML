#include "PowerUp_Shield.h"
#include "GraphicsUtils.h"

PowerUp_Shield::PowerUp_Shield() : Power_ups("Images/Shield.png","Audio/Shield.wav")
{
}

void PowerUp_Shield::Activate(Nave & nave, GameMode & gameMode)
{
	Power_ups::Activate(nave, gameMode);
	sf::Clock * clock = new sf::Clock; 
	nave.clockShieldPU = clock; 
	gameMode.powerUpPickedShield = true; 
	nave.drawShield = true; 
}
