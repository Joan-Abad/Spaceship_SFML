#include "Window.h"
#include "GraphicsUtils.h"
#include <time.h>
#include <string>
#include <iostream>
#include "GraphicsUtils.h"


Window::Window() : player(300,300,*this)
{

}

Window::Window(int anchura, int altura) : player(anchura, altura, *this), playerHUD("Score: ", 58, sf::Color::White, sf::Vector2f(40.f, 20.f), player, sf::Vector2i(anchura,altura))
{
	window.create(sf::VideoMode(anchura, altura), "SURIVE THE ASTEROIDS!", sf::Style::Default);
	player.owningHUd = &playerHUD;

	//Background
	spr_Background.setTexture(GraphicsUtils::InitializeTexture(tex_Background, "Images/background.png"));
	spr_Background.setPosition(anchura, 0);
	spr_Background.rotate(90);

	//Draw window + loop game
	drawWindow();
	

}

void Window::drawWindow()
{
	//PlayBackgroundMusic
	GraphicsUtils::playSound(backgroundBuffer, backgroundSound, "Audio/Music.wav", 70, true);
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
		gameMode.Main(window);
		gameMode.spawnAIRandomlly(window.getSize().x, window.getSize().y, window);
		gameMode.moveAllAI(window.getSize().x, window.getSize().y);
		gameMode.checkPlayerCollisionWithAIOnLevel(player);
		//Move Background
		moveBackground();
		

		//WINDOW STUFF

			window.clear();

			window.draw(spr_Background);

			//DRAW NAVE
			window.draw(player.getNaveSprite());
		
			if (player.drawShield == true)
			{
				player.getPlayerShield().setPosition(player.getNaveSprite().getPosition());
				window.draw(player.getPlayerShield());
			}

			//DRAW ASTEROID
			gameMode.drawAsteroids(window);

			//DRAW POWERUPS
			gameMode.drawPowerups(window);

			//DRAW AI
			gameMode.drawAllAI(window);

			//DRAW NAVE BULLETS
			player.drawBullets(window);

			//Player score
			playerHUD.setTextScore(player);

			//DRAW HUD
			playerHUD.drawHUD(window);


			window.display();
	}
}
void Window::moveBackground()
{
	spr_Background.move(0, backgroundSpeed);

	if (spr_Background.getPosition().y < -100 && moveUp == true)
	{
		backgroundSpeed *= -1;
		moveUp = false;
	}
	if (spr_Background.getPosition().y > 0 && spr_Background.getPosition().y < 1)
	{
		backgroundSpeed *= -1;
		moveUp = true; 
	}
}

