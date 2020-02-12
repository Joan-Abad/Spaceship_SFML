#pragma once
#include "SFML/Graphics.hpp"
#include <vector>
#include "SFML/Audio.hpp"
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
	float initialNaveSpeed;
	float naveSpeed; 
	float naveSpeedMultiplayer = 0.2f;
	float life = 1.f; 
	bool canBeDamaged = true; 
	//Shooting
	bool shoot = true;
	sf::Vector2f cannonPosition;

	// Timers
	sf::Clock shootingClock;
	sf::Time shootingTimeManage;

	sf::Clock damagedClock;
	sf::Time damagedTimeManage; 

	//COOLDOWNS
	const float damageCD = 1.f; 

	//PLAYER POINTS
	int points = 10;

	//COLLISIONS
	void CheckPlayerCollisions(sf::RenderWindow & window);

	//MOVEMENT
	bool canMoveLeft = true;
	bool canMoveRight = true;
	bool canMoveUp = true;
	bool canMoveDown = true;

	// SOUND BUFFER	
	sf::SoundBuffer shotSoundBuffer;
	sf::SoundBuffer hitSoundBuffer;

	//SOUNDS
	sf::Sound shootSound;
	sf::Sound hitSound;

	

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
	void eraseBulletsIfOutOfScreen(); 

	//Bullets
	std::vector<NaveBullets*> vec_spaceshipBullets;
	void NaveBulletsMovement();

	//Check action cooldowns
	void checkActionsCooldowns();
	void checkDamagedCooldowns();
	float shootingCD = 0.3f;
	float initialShootingCD;

	
	// Gameplay
	void sumPoints(int quantityToSum);
	void ApplyDamageToPlayer(float damage);
	void ChangeNaveSpeed(float multiply);

	// COLLISIONS
	void checkCollisionSpaceship();
	
	// Getters
	inline sf::Sprite &getNaveSprite() { return spr_Nave; };
	inline int getPlayerPoints() { return points; };
	inline float getLife() { return life; };

	//TIMERS POWERYPS
	sf::Time timeManagedSpeedPU;
	sf::Clock * clockSpeedPU = nullptr;
	sf::Time timeManagedShootPU;
	sf::Clock * clockShootCadencePU = nullptr;


	//CLASS POINTERS
	HUD * owningHUd; 
	Window * owningWindow = nullptr;

	void checkPowerUpCD();

};

