#include <SFML/Graphics.hpp>
#include "Window.h"
#include <iostream>
#include "NaveBullets.h"
#include <vector>
#include <time.h>

int main()
{
	// CREATE WINDOW LOOP
	srand(time(NULL));
	Window window(sf::VideoMode::getDesktopMode().height / 2, sf::VideoMode::getDesktopMode().height - (sf::VideoMode::getDesktopMode().height/6));
	/*std::vector<int> a = {1,2,3,4,5};
	std::cout << *a.begin() + 0;*/


	return 0;
}