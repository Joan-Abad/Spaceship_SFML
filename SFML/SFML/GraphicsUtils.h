#pragma once
#include "SFML/Graphics.hpp"
class GraphicsUtils
{
private:

public:
	static sf::Texture & InitializeTexture(sf::Texture &texture, const std::string textureAddress);
	const static sf::Vector2f getSpriteSize(sf::Sprite sprite);
};

