#pragma once
#include "Power_ups.h"
class PowerUp_Shield : public Power_ups
{
private:
public:
	PowerUp_Shield();
	void Activate(Nave & nave, GameMode &gameMode) override;
};

