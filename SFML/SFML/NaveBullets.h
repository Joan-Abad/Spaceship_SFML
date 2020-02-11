#pragma once
#include "SFML/Graphics.hpp"
#include "Asteroides.h"
#include <vector>
#include "GameMode.h"
#include "Window.h"


class GameMode;

class NaveBullets
{
private: 

	sf::Sprite spr_bullets; 
	sf::Texture tex_bullets; 
	
	//MODIFIABLE VALUES
	float bulletSpeed = 0.4f; 
	float bulletSize = 0.08f;

	bool destroy = false; 

	//BULLET LIFE TIMERS
	sf::Clock bulletClock; 
	sf::Time bulletTime; 

public: 

	NaveBullets();
	
	NaveBullets(int spawnPositionX, int spawnPositionY, Nave &nave);

	void bulletMovement();

	void CheckAsteroidsCollision(std::vector<Asteroides*> &vec_Asteroids);

	sf::Sprite & getBulletSprite();

	float bulletLifeTime();

	static constexpr float bulletLifetime = 1.5f;

	GameMode * gamemode = nullptr;
};

