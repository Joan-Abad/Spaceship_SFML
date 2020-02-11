#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
//#include "NaveBullets.h"

class Window; 
class HUD; 
class NaveBullets; 

class Nave
{
private: 

	//Nave graphics
	sf::Sprite spr_Nave; 
	sf::Texture tex_Nave;

	//Initial Values
	float naveSpeed; 
	float naveSpeedMultiplayer = 0.2f;
	float life = 1.f; 

	//Shooting
	bool shoot; 
	sf::Vector2f cannonPosition;

	// Timers
	sf::Clock shootingClock;
	sf::Time shootingTimeManage;

	//COOLDOWNS
	const float shootingCD = 0.3f; 

	//PLAYER POINTS
	int points = 10;

	//COLLISIONS
	void CheckPlayerCollisions(sf::RenderWindow & window);

	//MOVEMENT
	bool canMoveLeft = true;
	bool canMoveRight = true;
	bool canMoveUp = true;
	bool canMoveDown = true;

public: 

	//Constructors
	Nave();
	Nave(int anchuraPantalla, int alturaPantalla, Window & window);

	//Main 
	virtual void Main();

	// Movement
	virtual void NaveInput(sf::RenderWindow & window);

	//draw bullets on windows
	void drawBullets(sf::RenderWindow &window);

	//check cd for shooting
	void eraseBulletsIfLifeTimesOver(); 

	//Bullets
	std::vector<NaveBullets*> vec_spaceshipBullets;
	void NaveBulletsMovement();

	//Check action cooldowns
	void checkActionsCooldowns();
	
	// Gameplay
	void sumPoints(int quantityToSum);

	// COLLISIONS
	void checkCollisionSpaceship();
	
	// Getters
	inline sf::Sprite &getNaveSprite() { return spr_Nave; };
	inline int getPlayerPoints() { return points; };
	inline int getLife() { return life; };


	//CLASS POINTERS
	HUD * owningHUd; 
	Window * owningWindow = nullptr;


};

