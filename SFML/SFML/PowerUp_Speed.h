#pragma once
#include "Power_ups.h"
#include <string.h>

class PowerUp_Speed :public Power_ups
{
private:
public:
	PowerUp_Speed();
	void Activate(Nave & nave) override;
};

