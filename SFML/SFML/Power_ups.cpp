#include "Power_ups.h"
#include "GraphicsUtils.h"

Power_ups::Power_ups(const std::string imageAddress)
{
	spr_PowerUp.setTexture(GraphicsUtils::InitializeTexture(tex_PowerUp, imageAddress));
	spr_PowerUp.setPosition(500, 500);
	spr_PowerUp.setScale(0.1f,0.1f);
}

void Power_ups::Activate(Nave & nave)
{

}

