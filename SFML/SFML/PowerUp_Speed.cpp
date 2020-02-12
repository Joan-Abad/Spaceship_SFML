#include "PowerUp_Speed.h"

PowerUp_Speed::PowerUp_Speed(const std::string imageAddress) : Power_ups(imageAddress)
{

}

void PowerUp_Speed::Activate(Nave & nave)
{
	nave.ChangeNaveSpeed(2);
}
