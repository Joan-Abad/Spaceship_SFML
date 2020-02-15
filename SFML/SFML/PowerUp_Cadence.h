#pragma once
#include "Power_ups.h"
#include "sfml/Audio.hpp"
#include "GameMode.h"

class PowerUp_Cadence : public Power_ups
{
private: 
	
public: 
	PowerUp_Cadence();

	void Activate(Nave & nave, GameMode &gameMode) override;

};

