#include "Nave.h"
#include "NaveBullets.h"
#include "GraphicsUtils.h"
#include <iostream>
#include "HUD.h"

Nave::Nave()
{

};

Nave::Nave(int anchuraPantalla, int alturaPantalla) 
{
	spr_Nave.setTexture(GraphicsUtils::InitializeTexture(tex_Nave, "nave.png"));

	// regulator expression for 0.1 values like speed or size depending on screen
	const float regulatorExpression = ((anchuraPantalla * 0.1f) / 1280.f);

	// scale
	spr_Nave.setScale(regulatorExpression, regulatorExpression);
		
	// position
	spr_Nave.setPosition(float(anchuraPantalla/2.3), float(alturaPantalla - 200));
	
	//speed
	naveSpeed = ((anchuraPantalla * naveSpeedMultiplayer) / 1280.f);

	//shoot
	shoot = true; 
}

void Nave::NaveInput(sf::RenderWindow & window)
{
	CheckPlayerCollisions(window);

	//MOVE LEFT
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		if(canMoveLeft == true)
		spr_Nave.move(-naveSpeed, 0.f);
	}
	//MOVE RIGHT
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		if (canMoveRight == true)
		spr_Nave.move(naveSpeed, 0.f);
	}
	//MOVE UP
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if(canMoveUp == true)
		spr_Nave.move(0.f, -naveSpeed);
	}
	//MOVE DOWN
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if(canMoveDown == true)
		spr_Nave.move(0.f, naveSpeed);
	}

	//SHOOT
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::P))
	{
		//SET SHOOT POINT ORIGIN
		float xCannonPosition = spr_Nave.getGlobalBounds().left - (getSpriteSize(spr_Nave).x / 1.6);
		float YCannonPosition = spr_Nave.getGlobalBounds().top - (getSpriteSize(spr_Nave).y / 2);
		cannonPosition = { xCannonPosition, YCannonPosition };

		if(shoot == true)
		{	
			//CREATE NEW BULLET
			NaveBullets * nav = new NaveBullets(cannonPosition.x, cannonPosition.y);
			
			//ADD TO VECTOR TO DELETE AFTER
			astVec.push_back(nav);
			shoot = false; 
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
const sf::Vector2f Nave::getSpriteSize(sf::Sprite sprite)
{
	sf::Vector2f SpriteSize; 
	SpriteSize.x = sprite.getTexture()->getSize().x * sprite.getScale().x;
	SpriteSize.y = sprite.getTexture()->getSize().y * sprite.getScale().y;
	return SpriteSize;
}

void Nave::sumPoints(int quantityToSum)
{
	points += quantityToSum;
	if (owningHUd)
	{
		owningHUd->setTextScore(*this);
	}
}

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

void Nave::CheckPlayerCollisions(sf::RenderWindow & window)
{
	float spaceshipLeftSideMargin = 0;
	float spaceshipRightSideMargin = window.getSize().x - getSpriteSize(spr_Nave).x;
	float spaceshipTopMargin = 0;
	float spaceshipBotMargin = window.getSize().y - getSpriteSize(spr_Nave).y;

	//X SIDE
		// LEFT COLLISION
	if (spr_Nave.getPosition().x < spaceshipLeftSideMargin)
	{
		canMoveDown = true; 
		canMoveLeft = false; 
		canMoveRight = true;
		canMoveUp = true;
		std::cout << "\nTOUCHING";
	}
		// RIGHT COLLISION
	else if (spr_Nave.getPosition().x > spaceshipRightSideMargin)
	{
		canMoveDown = true;
		canMoveLeft = true;
		canMoveRight = false;
		canMoveUp = true;
	}
	//Y SIDE
		// TOP COLLISION
	else if (spr_Nave.getPosition().y < spaceshipTopMargin)
	{
		canMoveDown = true;
		canMoveLeft = true;
		canMoveRight = true;
		canMoveUp = false;
	}
		// BOT COLLISION
	else if (spr_Nave.getPosition().y > spaceshipBotMargin)
	{
		canMoveDown = false;
		canMoveLeft = true;
		canMoveRight = true;
		canMoveUp = true;
	}
	else
	{
		canMoveDown = true;
		canMoveLeft = true;
		canMoveRight = true;
		canMoveUp = true;
	}
}