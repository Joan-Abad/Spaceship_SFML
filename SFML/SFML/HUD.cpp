#include "HUD.h"
#include <string>
#include <iostream>
#include "GraphicsUtils.h"

HUD::HUD() = default;

//Font size in pixels
HUD::HUD(const std::string initialText, unsigned int fontSize, sf::Color fontColor, sf::Vector2f fontPositionOnWindow)
{
	
	if (!font.loadFromFile("Fonts/space354.ttf"))
	{
		std::cerr << "Font wasn't loaded correctlly";
	}

	text_Score.setFont(font);
	text_Score.setCharacterSize(fontSize);
	text_Score.setFillColor(fontColor);
	text_Score.setPosition(fontPositionOnWindow);
}

HUD::HUD(const std::string initialText, unsigned int fontSize, sf::Color fontColor, sf::Vector2f fontPositionOnWindow, Nave & nave,sf::Vector2i ScreenSize)
{
	if (!font.loadFromFile("Fonts/space354.ttf"))
	{
		std::cerr << "Font wasn't loaded correctlly";
	}

	//Player score
	text_Score.setFont(font);
	text_Score.setCharacterSize(fontSize);
	text_Score.setFillColor(fontColor);
	text_Score.setPosition(fontPositionOnWindow);
	setTextScore(nave);



	//PLAYER LIFE
	PlayerLife.setFillColor(sf::Color::Red);
	PlayerLife.setSize(sf::Vector2f(200.f, 30.f));
	

	float playerLifePositionX = (ScreenSize.x - ((ScreenSize.x / 100) * 2)) - PlayerLife.getSize().x;
	float playerLifePositionY = ((ScreenSize.y / 100) * 1.5f);
	PlayerLife.setPosition(sf::Vector2f(playerLifePositionX, playerLifePositionY));
	PlayerLife.setScale(nave.getLife(), 1.f);
	
	//PLAYER BACK RECTANGLE
	PlayerLifeBackRectangle.setFillColor(sf::Color(128, 128, 128, 255));
	PlayerLifeBackRectangle.setSize(sf::Vector2f(200.f, 30.f));
	PlayerLifeBackRectangle.setPosition(sf::Vector2f(playerLifePositionX, playerLifePositionY));



}

void HUD::setTextScore(Nave & nave)
{
	finalString = "Score: " + std::to_string(nave.getPlayerPoints());
	text_Score.setString(finalString);
}

void HUD::drawHUD(sf::RenderWindow & window)
{
	window.draw(text_Score);
	window.draw(PlayerLifeBackRectangle);
	window.draw(PlayerLife);
}
