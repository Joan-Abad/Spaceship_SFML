#pragma once
#include "SFML/Graphics.hpp"
#include "Nave.h"

class Window
{
private:
	sf::RenderWindow window;

	//Nave sss; 
	Nave player; 
	//classes instances 
	//Nave nave;

	//GameMode gameMode; 

	//HUD scoreHUD;

public:
	Window();

	Window(int anchura, int altura);

	void drawWindow();

	//Getters
	sf::RenderWindow &getWindow();
	//GameMode &getGameMode() { return gameMode; };

};
