#include <SFML/Graphics.hpp>
#include "Window.h"
#include <iostream>
#include <time.h>

int main()
{
	// CREATE WINDOW LOOP
	srand(time(NULL));
	Window window(sf::VideoMode::getDesktopMode().height / 2, sf::VideoMode::getDesktopMode().height - (sf::VideoMode::getDesktopMode().height/6));	
	return 0;
}