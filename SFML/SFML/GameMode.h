#pragma once
#include "Asteroides.h"
#include <vector>
#include "SFML/Audio.hpp"
#include "Nave.h"

class AI;
class Power_ups;

class GameMode
{
private: 

	//Asteroids timers
	sf::Clock clock_Asteroids;
	sf::Time time_Asteroids; 
	float AsteroidSpawnCD = 700.f; // IN MILI SECONDS
	std::vector<Asteroides*> levelAsteroids;

	sf::Sound sound;
	sf::SoundBuffer buffer;

	//AI
	std::vector<AI*> levelAI;

	//TIMERS
	sf::Clock clock_AiSpawn;
	sf::Time time_AiSpawn;



public: 
	//Constructors
	GameMode();

	//Main
	void Main(sf::RenderWindow & window);

	//ASTEROIDS
	bool asteroidDestroyed = false;
	std::vector<Asteroides*> &GetAsteroidOnLevel();
	void drawAsteroids(sf::RenderWindow &window);
	void MoveAllAsteroids(sf::RenderWindow & window);
	void SpawnAsteroidsRandomlly(sf::RenderWindow & window);

	//AI
	void spawnAIRandomlly(int anchura, int altura, sf::RenderWindow &window);
	void drawAllAI(sf::RenderWindow & window);
	void moveAllAI(int anchuraPantalla, int alturaPantalla);
	const int maxNumberOfAI = 4;
	const int secondsToSpawnAI = 5;
	std::vector<AI*> & GetAiOnLevel();
	void checkPlayerCollisionWithAIOnLevel(Nave & nave);

	//Powerups
	Power_ups * Power_up_ToSpawn = nullptr;
	std::vector <Power_ups*> PowerUpsOnLevel;
	void SpawnPowerUp(Asteroides asteroid);
	bool powerUpPickedSpeed = false;
	bool powerUpPickedFirerate = false;
	bool powerUpPickedShield = false;
	bool AI_Destroyed = false; 
	// Chance must be between 0 and 100
	int chanceOfGettingPowerUp = 15;

	//SOUNDS
	void checkSoundsToPlay();
	void drawPowerups(sf::RenderWindow &window);

	void createNewSound(sf::Sound soundToCopy);

	sf::Sound soundPowerUps;
	sf::SoundBuffer soundBufferPowerUps;
};

