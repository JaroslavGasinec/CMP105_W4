#include "Background.h"

Background::Background(sf::Texture Ntexture, sf::Vector2f size)
{
	texture = Ntexture;
	setTexture(&texture);
	setSize(size);
	setPosition(0, 0);
}
