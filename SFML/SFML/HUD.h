#pragma once
#include "SFML/Graphics.hpp"
#include "Nave.h"

class Nave;

class HUD
{
private: 
	//TEXT
	sf::Text text_Score; 

	//FONT
	sf::Font font;

	sf::RectangleShape PlayerLife; 

	sf::RectangleShape PlayerLifeBackRectangle;

public: 
	   
	//CONSTRUCTORS

	HUD();

	HUD(const std::string initialText, unsigned int fontSize, sf::Color fontColor, sf::Vector2f fontPositionOnWindow);

	HUD(const std::string initialText, unsigned int fontSize, sf::Color fontColor, sf::Vector2f fontPositionOnWindow, Nave & nave, sf::Vector2i ScreenSize);

	//GETTERS
	sf::Text & getTextScore() { return text_Score; };

	void setTextScore(Nave & nave);
		
	std::string finalString; 

	void drawHUD(sf::RenderWindow & window);

};

