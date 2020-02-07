#pragma once
#include "Framework\GameObject.h"
class Enemy :
	public GameObject
{
	sf::Vector2i direction = sf::Vector2i(1, 1);
	sf::Vector2f delta;
	sf::Vector2u* windowSize;
	float speed = 200;

public:
	Enemy(sf::Vector2u* windowSize);
	void update(float dt) override;
};

