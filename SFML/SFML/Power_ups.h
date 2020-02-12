#pragma once
#include "SFML/Graphics.hpp"
#include <iostream>
#include "Nave.h"

class Power_ups
{
private:
	sf::Texture tex_PowerUp;
	sf::Sprite	spr_PowerUp;

	std::string PowerUpAddress;
public:
	Power_ups(const std::string imageAddress);
	virtual void Activate(Nave & nave);
};

