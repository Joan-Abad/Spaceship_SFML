#pragma once
#include "SFML/Graphics.hpp"
#include "Window.h"
#include "Nave.h"

enum AIDifficulty
{
	easyAI, 
	mediumAI, 
	hardAI
};

class AI
{

private: 

	AIDifficulty aiDifficulty; 
	float ai_speed; 
	float ai_speed_multiplier = 0.1f;
	float start_aiSpeed;
	float sizeMultiplier; 
	bool movingRight = true;
	float bullet_speed = 0.2f;
	int life = 3; 

	//Graphics
	sf::Sprite spr_AI; 
	sf::Texture text_AI;
	sf::Sprite spr_BulletAI;
	sf::Texture text_BulletAI;

public: 
	AI(int anchuraPantalla, int alturaPantalla, sf::RenderWindow & window);
	//GETTERS
	inline sf::Sprite &getSprite() { return spr_AI; };
	inline sf::Sprite &getBulletSprite() { return spr_BulletAI; };
	inline int &getLife() { return life; };
	inline void applyDamage(int SubstractValue) { life = life - SubstractValue;  }
	void AIMovement(int anchuraPantalla, int alturaPantalla);
	void AIShootBullet();
	void AISpawnBullet(int alturaPantalla);
	void checkCollisionWithPlayer(Nave &nave);
	void checkBulletsCollisionWithPlayer(Nave &nave);
	
	//Player Points
	const int points = 100;
	
	bool dead = false;
};

