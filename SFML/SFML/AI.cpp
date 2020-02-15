#include "AI.h"
#include "GraphicsUtils.h"
#include <cstdlib>

AI::AI(int anchuraPantalla, int alturaPantalla, sf::RenderWindow & window)
{
	spr_AI.setTexture(GraphicsUtils::InitializeTexture(text_AI, "Images/AI.png"));
	spr_AI.setScale(0.2f, 0.2f);
	ai_speed = ((anchuraPantalla * ai_speed_multiplier) / 1280.f);
	int anchur = anchuraPantalla - int(GraphicsUtils::getSpriteSize(spr_AI).x) * 2;
	int x = rand() % anchur + (int)GraphicsUtils::getSpriteSize(spr_AI).x;
	int y = rand() % (alturaPantalla / 4) + anchuraPantalla/9;
	spr_AI.setPosition(x,y);
	start_aiSpeed = ai_speed;

	//BULLET
	spr_BulletAI.setTexture(GraphicsUtils::InitializeTexture(text_BulletAI, "Images/bulletAI.png"));
	spr_BulletAI.scale(0.1f, 0.1f);
	int posX = spr_AI.getPosition().x + GraphicsUtils::getSpriteSize(spr_BulletAI).x * 2;
	int posY = spr_AI.getPosition().y + GraphicsUtils::getSpriteSize(spr_BulletAI).y / 2;
	spr_BulletAI.setPosition(posX,posY);
	
}

void AI::AIMovement(int anchuraPantalla, int alturaPantalla)
{

	if (spr_AI.getPosition().x >= anchuraPantalla - int(GraphicsUtils::getSpriteSize(spr_AI).x))
		ai_speed *= -1;
	if (spr_AI.getPosition().x <= (int)GraphicsUtils::getSpriteSize(spr_AI).x)
		ai_speed *= -1;

	spr_AI.move(ai_speed, 0);

	AISpawnBullet(alturaPantalla);
	
}

void AI::AIShootBullet()
{
	spr_BulletAI.move(0, bullet_speed);
}

void AI::AISpawnBullet(int alturaPantalla)
{
	if (dead == false)
	{
		if(spr_BulletAI.getPosition().y > alturaPantalla)
		{
			int posX = spr_AI.getPosition().x + GraphicsUtils::getSpriteSize(spr_BulletAI).x * 2;
			int posY = spr_AI.getPosition().y + GraphicsUtils::getSpriteSize(spr_BulletAI).y / 2;
			spr_BulletAI.setPosition(posX, posY);
		}
	}
}

void AI::checkCollisionWithPlayer(Nave & nave)
{
	if(dead == false)
	{
		if (spr_AI.getGlobalBounds().intersects(nave.getNaveSprite().getGlobalBounds()))
		{
			if (nave.canBeDamaged == true)
			{
				if (nave.drawShield == false)
				{
					//DAMAGED CD
					nave.canBeDamaged = false;

					//APPLY DAMAGE THE ASTEROID DOES
					nave.ApplyDamageToPlayer(0.3f);

					//RESET HUD
					if (nave.owningHUd)
						nave.owningHUd->setNewLifeBar(nave);
				}
				else if (nave.drawShield == true)
				{
					nave.drawShield = false;
					nave.canBeDamaged = false;
					nave.getNaveSprite().setColor(sf::Color(0, 255, 255, 255));
					GraphicsUtils::playSound(nave.hitSoundBuffer, nave.hitSound, "Audio/ShieldOff.wav", 100, false);
					nave.damagedClock.restart();
				}
				if (nave.owningHUd)
				{
					nave.owningHUd->setNewLifeBar(nave);
				}
			}
		}
	}
}

void AI::checkBulletsCollisionWithPlayer(Nave & nave)
{
	if (dead == false)
	{
		if (spr_BulletAI.getGlobalBounds().intersects(nave.getNaveSprite().getGlobalBounds()))
		{
			if (nave.canBeDamaged == true)
			{
				if (nave.drawShield == false)
				{
					//DAMAGED CD
					nave.canBeDamaged = false;

					//APPLY DAMAGE THE ASTEROID DOES
					nave.ApplyDamageToPlayer(0.3f);

					//RESET HUD
					if (nave.owningHUd)
						nave.owningHUd->setNewLifeBar(nave);
				}
				else if (nave.drawShield == true)
				{
					nave.drawShield = false;
					nave.canBeDamaged = false;
					nave.getNaveSprite().setColor(sf::Color(0, 255, 255, 255));
					GraphicsUtils::playSound(nave.hitSoundBuffer, nave.hitSound, "Audio/ShieldOff.wav", 100, false);
					nave.damagedClock.restart();
				}
				if (nave.owningHUd)
				{
					nave.owningHUd->setNewLifeBar(nave);
				}
			}
		}
	}
}
