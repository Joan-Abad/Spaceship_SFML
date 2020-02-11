#include "Window.h"
#include <time.h>
#include <string>
#include <iostream>

Window::Window() : player(300,300,*this)
{

}

Window::Window(int anchura, int altura) : player(anchura, altura, *this), playerHUD("Score: ", 58, sf::Color::White, sf::Vector2f(40.f, 20.f), player, sf::Vector2i(anchura,altura))
{
	window.create(sf::VideoMode(anchura, altura), "SURIVE THE ASTEROIDS!", sf::Style::Default);
	player.owningHUd = &playerHUD;
	drawWindow();
}

void Window::drawWindow()
{
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		//Nave Stuff
		
		player.NaveInput(window);
		
		player.Main();

		//GameModeStuff
		gameMode.SpawnAsteroidsRandomlly(window);
		gameMode.MoveAllAsteroids(window);

		std::cout << "Asteroids in vector: " << gameMode.getAllAsteroids().size() << std::endl;

		window.clear(sf::Color(60,45,105));

		//DRAW NAVE
		window.draw(player.getNaveSprite());
		
		//DRAW ASTEROID
		gameMode.drawAsteroids(window);

		//DRAW NAVE BULLETS
		player.drawBullets(window);

		//Player score
		playerHUD.setTextScore(player);

		//DRAW HUD
		playerHUD.drawHUD(window);

		window.display();
	}
}
/*
sf::RenderWindow & Window::getWindow()
{
	return window;
}
*/