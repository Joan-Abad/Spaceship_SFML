#include "GraphicsUtils.h"
#include <string>
#include <iostream>

sf::Texture & GraphicsUtils::InitializeTexture(sf::Texture &texture, const std::string textureAddress)
{
	if (!texture.loadFromFile(textureAddress))
		std::cerr << "No se ha cargar la imagen correctente.\n";
	/*else
	{
		std::cout << "Se ha cargado corectamente " << textureAddress << std::endl;
	}*/
	return texture;
}

const sf::Vector2f GraphicsUtils::getSpriteSize(sf::Sprite sprite)
{
	sf::Vector2f SpriteSize;
	SpriteSize.x = sprite.getTexture()->getSize().x * sprite.getScale().x;
	SpriteSize.y = sprite.getTexture()->getSize().y * sprite.getScale().y;
	return SpriteSize;
}
