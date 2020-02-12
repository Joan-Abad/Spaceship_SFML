#include "Power_ups.h"
#include "GraphicsUtils.h"

Power_ups::Power_ups(const std::string imageAddress)
{
	spr_PowerUp.setTexture(GraphicsUtils::InitializeTexture(tex_PowerUp, imageAddress));
}

void Power_ups::Activate(Nave & nave)
{

}

