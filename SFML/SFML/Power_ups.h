#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Nave.h"

class Power_ups
{
private:

protected: 
	sf::Texture tex_PowerUp;
	sf::Sprite	spr_PowerUp;

public:
	Power_ups(const std::string imageAddress);
	
	static int LifeTimePowerUp;
	virtual void Activate(Nave & nave);
	sf::Sprite &getSpritePowerUp() { return spr_PowerUp; };
	static int & getLifeTimePowerUp() { return LifeTimePowerUp; };

};

