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


	GameMode gameMode; 
	
	HUD scoreHUD;

public:
	Window();

	Window(int anchura, int altura);

	void drawWindow();

	//Getters
	sf::RenderWindow &getWindow();
	//GameMode &getGameMode() { return gameMode; };

};
