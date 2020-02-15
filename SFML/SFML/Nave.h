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
	float naveSpeedMultiplayer = 0.15f;
	float life = 1.f; 
	//Shooting
	bool shoot = true;
	sf::Vector2f cannonPosition;

	// Timers
	sf::Clock shootingClock;
	sf::Time shootingTimeManage;

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

	//SHIELDS
	sf::Texture spr_text;
	sf::Sprite spr_shield;

	//SOUNDS
	sf::Sound shootSound;

	// SOUND BUFFER	
	sf::SoundBuffer shotSoundBuffer;

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
	sf::Time timeManagedShielPU; 
	sf::Clock * clockShieldPU = nullptr;
	sf::Clock damagedClock;


	//CLASS POINTERS
	HUD * owningHUd; 
	Window * owningWindow = nullptr;

	void checkPowerUpCD();
	
	bool drawShield = false;
	bool canBeDamaged = true;

	inline sf::Sprite &getPlayerShield() { return spr_shield; };

	//SOUNDS
	sf::Sound hitSound;
	sf::SoundBuffer hitSoundBuffer;
};

