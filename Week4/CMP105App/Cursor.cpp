#include "Cursor.h"

Cursor::Cursor(sf::Vector2u* windowStart, sf::Vector2u* windowEnd)
{
	texture.loadFromFile("gfx/cursor.png");
	setTexture(&texture);
	this->windowEnd = windowEnd;
	this->windowStart = windowStart;
}

void Cursor::update(float dt)
{
	setPosition(windowStart->x + input->getMouseX(),windowStart->y + input->getMouseY());
}

