#include "Cursor.h"

Cursor::Cursor(sf::Vector2u* windowSize)
{
	texture.loadFromFile("gfx/cursor.png");
	setTexture(&texture);
	this->windowSize = windowSize;
}

void Cursor::update(float dt)
{
	setPosition(input->getMouseX(), input->getMouseY());
}

