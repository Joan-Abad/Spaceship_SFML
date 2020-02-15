#pragma once
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
class GraphicsUtils
{
private:

public:
	static sf::Texture & InitializeTexture(sf::Texture &texture, const std::string textureAddress);
	const static sf::Vector2f getSpriteSize(sf::Sprite sprite);
	static void playSound(sf::SoundBuffer &soundbuffer, sf::Sound & sound, const std::string AudioRouth, float volume, bool loop);
	static void setSoundBuffer(sf::SoundBuffer &soundbuffer, sf::Sound & sound, const std::string AudioRouth, float volume, bool loop);
};

