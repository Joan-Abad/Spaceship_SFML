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
	GraphicsUtils::playSound(backgroundBuffer, backgroundSound, "Audio/MainMenu.wav", 70, true);
	
	//Background
	sf::Sprite spr_menuBackground;
	sf::Texture tex_menuBackground; 
	spr_menuBackground.setTexture(GraphicsUtils::InitializeTexture(tex_menuBackground, "Images/backgroundMainMenu.jpg"));
	spr_menuBackground.setScale(2.1f, 2.f);
	//Start Button
	sf::Texture tex_menuStart;
	sf::Sprite spr_menuStart;
	spr_menuStart.setTexture(GraphicsUtils::InitializeTexture(tex_menuStart,"Images/startButton.png"));
	spr_menuStart.setScale(0.6f, 0.6f);
	spr_menuStart.setPosition(window.getSize().x / 2 - GraphicsUtils::getSpriteSize(spr_menuStart).x/2, window.getSize().y / 3.f);
	
	sf::RectangleShape mouseDetector;
	mouseDetector.setSize(sf::Vector2f(10, 10));

	sf::Sound sound_Mouse; 
	sf::SoundBuffer buffer_Mouse; 

	sf::Sprite spr_menuQuit;
	sf::Texture tex_menuQuit; 
	spr_menuQuit.setTexture(GraphicsUtils::InitializeTexture(tex_menuQuit, "Images/quitButton.png"));
	spr_menuQuit.setScale(0.6f, 0.6f);
	spr_menuQuit.setPosition(window.getSize().x / 2 - GraphicsUtils::getSpriteSize(spr_menuStart).x / 2, window.getSize().y / 2.f);
	
	//Main Menu
	while(isInMainMenu == true)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				mouseDetector.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
				if (mouseDetector.getGlobalBounds().intersects(spr_menuStart.getGlobalBounds()))
				{
					GraphicsUtils::playSound(buffer_Mouse,sound_Mouse,"Audio/PLAY.wav",100,false);
					isInMainMenu = false; 
				}
				if (mouseDetector.getGlobalBounds().intersects(spr_menuQuit.getGlobalBounds()))
				{
					isInMainMenu = false; 
					backgroundSound.stop();
					window.close();
				}
			}
		}

		
		

		window.clear();
		window.draw(spr_menuBackground);
		window.draw(spr_menuStart);
		window.draw(spr_menuQuit);
		window.display();
	}
	GraphicsUtils::playSound(backgroundBuffer, backgroundSound, "Audio/Music.wav", 70, true);
	//Game
	while (GameOver == false)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				GameOver = true; 
				exit = true; 
			}
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
	sf::Texture tex_backgroundEnd;
	sf::Sprite spr_BackgroundEnd;

	spr_BackgroundEnd.setTexture(GraphicsUtils::InitializeTexture(tex_backgroundEnd, "Images/TheEnd.png"));
	spr_BackgroundEnd.setPosition(window.getSize().x / 2.5f - GraphicsUtils::getSpriteSize(spr_menuStart).x / 2, window.getSize().y / 2.5f);
	spr_Background.scale(2.f,2.f);

	GraphicsUtils::playSound(backgroundBuffer, backgroundSound, "Audio/TheEnd.wav", 70, true);

	while (exit == false)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
				exit = true;
			}
		}

		window.clear();
		window.draw(spr_menuBackground);
		window.draw(spr_BackgroundEnd);
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

