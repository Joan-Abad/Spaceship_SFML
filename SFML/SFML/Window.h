#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Nave.h"
#include "GameMode.h"
#include "HUD.h"
#include "Power_ups.h"

class Window
{
private:
	sf::RenderWindow window;

	Nave player; 
	//classes instances 

	HUD playerHUD;

	sf::Texture tex_Background;
	sf::Sprite spr_Background; 

	float backgroundSpeed = -0.01;

	sf::SoundBuffer backgroundBuffer;
	sf::Sound backgroundSound;


public:
	Window();

	Window(int anchura, int altura);

	void drawWindow();

	//Getters
	
	//GameMode &getGameMode() { return gameMode; };
	GameMode gameMode;
	sf::RenderWindow &getWindow() { return window; }

	void moveBackground();

	bool moveUp = true;
};
