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

void GraphicsUtils::playSound(sf::SoundBuffer &soundbuffer, sf::Sound &sound, const std::string AudioRouth, float volume, bool loop)
{
	if (!soundbuffer.loadFromFile(AudioRouth))
	{
		std::cout << "MUSIC NOT LOADED\n";

	}
	sound.setBuffer(soundbuffer);
	sound.setVolume(volume);
	sound.play();
	sound.setLoop(loop);
}

void GraphicsUtils::setSoundBuffer(sf::SoundBuffer & soundbuffer, sf::Sound & sound, const std::string AudioRouth, float volume, bool loop)
{
	
	if (!soundbuffer.loadFromFile(AudioRouth))
		std::cout << "Couldn't load audio\n";
	else
		sound.setBuffer(soundbuffer);
}
