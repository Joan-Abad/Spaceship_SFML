#pragma once
#include "Power_ups.h"

class PowerUp_Speed :public Power_ups
{
private:

public:
	PowerUp_Speed(const std::string imageAddress);
	void Activate(Nave & nave) override;
};

