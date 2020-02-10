#include "Nave.h"
#include "NaveBullets.h"
#include "GraphicsUtils.h"
#include <iostream>

Nave::Nave()
{

};

Nave::Nave(int anchuraPantalla, int alturaPantalla) 
{
	spr_Nave.setTexture(GraphicsUtils::InitializeTexture(tex_Nave, "nave.png"));

	// regulator expression for 0.1 values like speed or size depending on screen
	const float regulatorExpression = ((anchuraPantalla * 0.1f) / 1280.f);

	//speed
	naveSpeedMultiplayer = 0.1f;

	
	// scale
	spr_Nave.setScale(regulatorExpression, regulatorExpression);
		
	// position
	spr_Nave.setPosition(float(anchuraPantalla/2.3), float(alturaPantalla - 200));

	//speed 
	naveSpeed = regulatorExpression;

	//shoot
	shoot = true; 

	//Initialize Shoot Cannon Position
	cannonPosition = { spr_Nave.getLocalBounds().height , spr_Nave.getPosition().y };

}

void Nave::NaveInput()
{
	//MOVE LEFT
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		spr_Nave.move(-naveSpeed, 0.f);
	}
	//MOVE RIGHT
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		spr_Nave.move(naveSpeed, 0.f);
	}
	//MOVE UP
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		spr_Nave.move(0.f, -naveSpeed);
	}
	//MOVE DOWN
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		spr_Nave.move(0.f, naveSpeed);
	}

	//SHOOT
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		//SET SHOOT POINT ORIGIN
		float xCannonPosition = spr_Nave.getLocalBounds().left;
		float YCannonPosition = spr_Nave.getGlobalBounds().top;
		cannonPosition = { xCannonPosition, YCannonPosition };

		if(shoot == true)
		{	
			//CREATE NEW BULLET
			NaveBullets * nav = new NaveBullets(spr_Nave.getGlobalBounds().left - 15.f, cannonPosition.y);
			
			//ADD TO VECTOR TO DELETE AFTER
			astVec.push_back(nav);
			shoot = false; 
			
			//sumPoints(10);
		}
	}
}

void Nave::drawBullets(sf::RenderWindow &window)
{
	if (!astVec.empty())
	{
		for (auto &bullet : astVec)
		{
			window.draw(bullet->getBulletSprite());
		}
	}
}

void Nave::eraseBulletsIfLifeTimesOver()
{
	if (!astVec.empty())
	{
		for (size_t i = 0; i < astVec.size(); i++)
		{
			if (astVec[i]->bulletLifeTime() > NaveBullets::bulletLifetime)
			{
				//std::cout << astVec[i]->bulletLifeTime();
				astVec.erase(astVec.begin() + i);
			}
		}
	}
}

void Nave::checkActionsCooldowns()
{
	shootingTimeManage = shootingClock.getElapsedTime();
	if (shootingTimeManage.asSeconds() >= shootingCD)
	{
		if (shoot == false)
		{
			shoot = true;
			shootingClock.restart();
		}
	}
}
/*
void Nave::sumPoints(int quantityToSum)
{
	points += quantityToSum;
	if (owningHUd)
	{
		owningHUd->setTextScore(*this);
	}
}
*/
void Nave::NaveBulletsMovement()
{
	if (!astVec.empty())
	{
		for (auto &bullet : astVec)
		{
			bullet->bulletMovement();
		}
	}
}

void Nave::Main()
{
	//SHOOT BULLETS MOVENET
	NaveBulletsMovement();

	//CHECK BULLETS
	eraseBulletsIfLifeTimesOver();

	//CHECK ACTIONS
	checkActionsCooldowns();
}