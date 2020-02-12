#pragma once
#include "Power_ups.h"
class PowerUp_Cadence : public Power_ups
{
private: 

public: 
	PowerUp_Cadence();

	void Activate(Nave & nave) override;

};

