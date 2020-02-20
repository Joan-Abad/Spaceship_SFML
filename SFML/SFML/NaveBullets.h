#pragma once
#include "SFML/Graphics.hpp"
#include "Asteroides.h"
#include <vector>
#include "GameMode.h"
#include "Window.h"
#include "AI.h"

class GameMode;

class NaveBullets
{
private: 

	sf::Sprite spr_bullets; 
	sf::Texture tex_bullets; 
	
	//MODIFIABLE VALUES
	float bulletSpeed = 0.4f; 
	float bulletSize = 0.08f;
	int damage = 1; 


	//BULLET LIFE TIMERS
	sf::Clock bulletClock; 
	sf::Time bulletTime; 

	//SOUND 
	sf::SoundBuffer bufferExplosion;
	sf::Sound soundExplosion;

public: 

	NaveBullets();
	
	NaveBullets(int spawnPositionX, int spawnPositionY, Nave &nave);

	//Variables 
	static constexpr float bulletLifetime = 1.5f;

	void bulletMovement(Nave & nave);
	void CheckAsteroidsCollision(std::vector<Asteroides*> &vec_Asteroids, Nave & nave);
	void CheckEnemiesCollision(std::vector<AI*> &vec_AI, Nave & nave);

	//Getters
	sf::Sprite & getBulletSprite();
	int getBulletDamage() { return damage; };

	float bulletLifeTime();
	bool destroyed = false;

	GameMode * gamemode = nullptr;
};

