#include "Nave.h"
#include "NaveBullets.h"
#include "Window.h"
#include "GraphicsUtils.h"
#include <iostream>
#include "HUD.h"

Nave::Nave()
{

};

Nave::Nave(int anchuraPantalla, int alturaPantalla, Window & window) 
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

	owningWindow = &window; 
	
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
		float xCannonPosition = spr_Nave.getGlobalBounds().left + (GraphicsUtils::getSpriteSize(spr_Nave).x)/2.5;
		float YCannonPosition = spr_Nave.getGlobalBounds().top - (GraphicsUtils::getSpriteSize(spr_Nave).x) / 4;
		cannonPosition = { xCannonPosition, YCannonPosition };
		if(shoot == true)
		{	
			shoot = false;
			//CREATE NEW BULLET
			NaveBullets * nav = new NaveBullets(cannonPosition.x, cannonPosition.y,*this);
			
			//ADD TO VECTOR TO DELETE AFTER
			vec_spaceshipBullets.push_back(nav);

			GraphicsUtils::playSound(shotSoundBuffer, shootSound, "Audio/laser.wav", 100, false);

			shootingClock.restart();

			
		}
	}

	
}

void Nave::drawBullets(sf::RenderWindow &window)
{
	if (!vec_spaceshipBullets.empty())
	{
		for (auto &bullet : vec_spaceshipBullets)
		{
			window.draw(bullet->getBulletSprite());
		}
	}
}

void Nave::eraseBulletsIfOutOfScreen()
{
	if (!vec_spaceshipBullets.empty())
	{
		for (size_t i = 0; i < vec_spaceshipBullets.size(); i++)
		{
			if (vec_spaceshipBullets[i]->getBulletSprite().getPosition().y < 0)
			{
				vec_spaceshipBullets.erase(vec_spaceshipBullets.begin() + i);
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
			shootingClock.restart();
			shoot = true;
		}
	}
}

void Nave::checkDamagedCooldowns()
{
	damagedTimeManage = damagedClock.getElapsedTime();
	if (damagedTimeManage.asSeconds() >= damageCD)
	{
		if (canBeDamaged == false)
		{
			spr_Nave.setColor(sf::Color(255, 255, 255, 255));
			damagedClock.restart();
			canBeDamaged = true;
		}
	}
}

void Nave::sumPoints(int quantityToSum)
{
	points += quantityToSum;
	if (owningHUd)
	{
		owningHUd->setTextScore(*this);
	}
}

void Nave::ApplyDamageToPlayer(float damage)
{
	if (life > damage)
	{
		life -= damage;
		GraphicsUtils::playSound(hitSoundBuffer,hitSound,"Audio/Hit.wav",100,false);
	}
	else
		owningWindow->getWindow().close();//life = 0;

	//Set red when spaceship is damaged
	spr_Nave.setColor(sf::Color(255, 0, 0, 255));

	//RESET CLOCK WHEN DAMAGE APPLIED
	damagedClock.restart();
}
//initial multiply value is 0.2
void Nave::ChangeNaveSpeed(float multiply)
{
	naveSpeed *= multiply;
}

void Nave::NaveBulletsMovement()
{
	if (!vec_spaceshipBullets.empty())
	{
		for (auto &bullet : vec_spaceshipBullets)
		{
			bullet->bulletMovement(*this);
		}
	}
}

void Nave::checkCollisionSpaceship()
{
	for (auto &asteroid : owningWindow->gameMode.getAllAsteroids())
	{
		if (spr_Nave.getGlobalBounds().intersects(asteroid->getAsteroid().getGlobalBounds()))
		{
			if(canBeDamaged == true)
			{
				//DAMAGED CD
				canBeDamaged = false;
				
				//APPLY DAMAGE THE ASTEROID DOES
				ApplyDamageToPlayer(asteroid->getDamage()); 
				
				//RESET HUD
				if (owningHUd)
					owningHUd->setNewLifeBar(*this);
			
			}
		}
	}
}

void Nave::Main()
{
	//SHOOT BULLETS MOVENET
	NaveBulletsMovement();

	//CHECK BULLETS
	eraseBulletsIfOutOfScreen();

	//CHECK ACTIONS
	checkActionsCooldowns();
	checkDamagedCooldowns();

	//CHECK COLLISION SPACESHIP
	checkCollisionSpaceship();
}

void Nave::CheckPlayerCollisions(sf::RenderWindow & window)
{
	float spaceshipLeftSideMargin = 0;
	float spaceshipRightSideMargin = window.getSize().x - GraphicsUtils::getSpriteSize(spr_Nave).x;
	float spaceshipTopMargin = 0;
	float spaceshipBotMargin = window.getSize().y - GraphicsUtils::getSpriteSize(spr_Nave).y;

	//X SIDE
		// LEFT COLLISION
	if (spr_Nave.getPosition().x < spaceshipLeftSideMargin)
	{
		canMoveDown = true; 
		canMoveLeft = false; 
		canMoveRight = true;
		canMoveUp = true;
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