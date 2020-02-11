#pragma once
#include "SFML/Graphics.hpp"
#include "Nave.h"
#include "GameMode.h"
#include "HUD.h"

class Window
{
private:
	sf::RenderWindow window;

	Nave player; 
	//classes instances 

	
	HUD playerHUD;


public:
	Window();

	Window(int anchura, int altura);

	void drawWindow();

	//Getters
	
	//GameMode &getGameMode() { return gameMode; };
	GameMode gameMode;
	sf::RenderWindow &getWindow() { return window; }

};
