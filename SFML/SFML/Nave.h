#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
//#include "NaveBullets.h"

class NaveBullets; 

class Nave
{
private: 

	//Nave graphics
	sf::Sprite spr_Nave; 
	sf::Texture tex_Nave;

	//Initial Values
	float naveSpeed; 
	float naveSpeedMultiplayer; 

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

public: 

	//Constructors
	Nave();
	Nave(int anchuraPantalla, int alturaPantalla);

	//Main 
	virtual void Main();

	//Getters
	inline sf::Sprite &getNaveSprite() { return spr_Nave; };

	// Movement
	virtual void NaveInput();

	//draw bullets on windows
	void drawBullets(sf::RenderWindow &window);

	//check cd for shooting
	void eraseBulletsIfLifeTimesOver(); 

	//Bullets
	std::vector<NaveBullets*> astVec;
	void NaveBulletsMovement();

	//Check action cooldowns
	void checkActionsCooldowns();

	//int getPlayerPoints() { return points; };

	//void sumPoints(int quantityToSum); 

	//HUD * owningHUd; 
	//Window * owningWindow = nullptr;

};

