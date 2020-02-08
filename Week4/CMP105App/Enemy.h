#pragma once
#include "Framework\GameObject.h"
class Enemy :
	public GameObject
{
	sf::Vector2i direction = sf::Vector2i(1, 1);
	sf::Vector2f delta;
	sf::Vector2u* windowEnd;
	sf::Vector2u* windowStart;
	float speed = 200;

public:
	Enemy(sf::Vector2u* windowStart, sf::Vector2u* windowEnd);
	void update(float dt) override;
};

