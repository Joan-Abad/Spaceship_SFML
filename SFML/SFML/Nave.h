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

	//Getters
	inline sf::Sprite &getNaveSprite() { return spr_Nave; };

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

	void checkCollisionSpaceship();

	int getPlayerPoints() { return points; };

	void sumPoints(int quantityToSum); 

	HUD * owningHUd; 
	Window * owningWindow = nullptr;
	std::string debug = "debug";
	const sf::Vector2f getSpriteSize(sf::Sprite sprite);
};

