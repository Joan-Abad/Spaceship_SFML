#include "HUD.h"
#include <string>
#include <iostream>

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

HUD::HUD(const std::string initialText, unsigned int fontSize, sf::Color fontColor, sf::Vector2f fontPositionOnWindow, Nave & nave)
{
	if (!font.loadFromFile("Fonts/space354.ttf"))
	{
		std::cerr << "Font wasn't loaded correctlly";
	}

	text_Score.setFont(font);
	text_Score.setCharacterSize(fontSize);
	text_Score.setFillColor(fontColor);
	text_Score.setPosition(fontPositionOnWindow);

	setTextScore(nave);
}

void HUD::setTextScore(Nave & nave)
{
	finalString = "Score: " + std::to_string(nave.getPlayerPoints());
	text_Score.setString(finalString);
}
