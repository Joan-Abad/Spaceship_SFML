#include "Window.h"
#include <time.h>
#include <string>

Window::Window() : player(300,300)
{

}

Window::Window(int anchura, int altura) : player(anchura, altura)
{
	window.create(sf::VideoMode(anchura, altura), "SURIVE THE ASTEROIDS!", sf::Style::None);
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
		player.NaveInput();
		player.Main();

		//GameModeStuff
		//gameMode.SpawnAsteroidsRandomlly(window);
		//gameMode.MoveAllAsteroids();


		window.clear(sf::Color(60,45,105));

		//DRAW NAVE
		window.draw(player.getNaveSprite());
		//window.draw(sss.getNaveSprite());
		
		//DRAW ASTEROID
		//gameMode.drawAsteroids(window);

		//DRAW NAVE BULLETS
		player.drawBullets(window);

		//scoreHUD.setTextScore(nave);

		//DRAW HUD
		//window.draw(scoreHUD.getTextScore());

		window.display();
	}
}
/*
sf::RenderWindow & Window::getWindow()
{
	return window;
}
*/