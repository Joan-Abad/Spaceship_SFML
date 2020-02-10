#include "GraphicsUtils.h"
#include <string>
#include <iostream>

sf::Texture & GraphicsUtils::InitializeTexture(sf::Texture &texture, const std::string textureAddress)
{
	if (!texture.loadFromFile(textureAddress))
		std::cerr << "No se ha cargar la imagen correctente.\n";
	else
	{
		std::cout << "Se ha cargado corectamente " << textureAddress << std::endl;
	}
	return texture;
}
