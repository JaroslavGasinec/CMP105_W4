#pragma once
#include "Framework\GameObject.h"
class Cursor :
	public GameObject
{
	sf::Texture texture;
	sf::Vector2u* windowEnd;
	sf::Vector2u* windowStart;
public:
	Cursor(sf::Vector2u* windowStart, sf::Vector2u* windowEnd);
	void update(float dt) override;
};

