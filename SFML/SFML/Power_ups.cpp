#include "Power_ups.h"
#include "GraphicsUtils.h"
#include "GameMode.h"
Power_ups::Power_ups(const std::string imageAddress, const std::string soundAddress)
{
	spr_PowerUp.setTexture(GraphicsUtils::InitializeTexture(tex_PowerUp, imageAddress));
	spr_PowerUp.setPosition(500, 500);
	spr_PowerUp.setScale(0.1f,0.1f);
	GraphicsUtils::setSoundBuffer(bufferPowerUp, soundPowerUp, soundAddress, 100, false);
}


void Power_ups::Activate(Nave & nave, GameMode & gameMode)
{	
	//Give sound to gamemode to play it 
	gameMode.soundPowerUps = soundPowerUp;
	gameMode.powerUpPickedSpeed = true; 

}

