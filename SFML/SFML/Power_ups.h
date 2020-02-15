#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Nave.h"
#include "GameMode.h"

class GameMode;

class Power_ups
{
private:

protected: 
	sf::Texture tex_PowerUp;
	sf::Sprite	spr_PowerUp;
	//SOUNDS
	sf::SoundBuffer bufferPowerUp;
	sf::Sound soundPowerUp;

public:
	//Initialize image address and sound address 
	Power_ups(const std::string imageAddress, const std::string soundAddress);
	
	static int LifeTimePowerUp;
	virtual void Activate(Nave & nave, GameMode & gameMode);
	sf::Sprite &getSpritePowerUp() { return spr_PowerUp; };
	static int & getLifeTimePowerUp() { return LifeTimePowerUp; };

};

