#include "Cursor.h"

Cursor::Cursor(sf::Vector2u windowSize)
{
	texture.loadFromFile("gfx/icon.png");
	setTexture(&texture);
	this->windowSize = windowSize;
}

void Cursor::update(float dt)
{
	setPosition(input->getMouseX(), input->getMouseY());
}

