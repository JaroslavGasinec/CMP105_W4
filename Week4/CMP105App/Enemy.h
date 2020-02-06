#pragma once
#include "Framework\GameObject.h"
class Enemy :
	public GameObject
{
	sf::Vector2i direction = sf::Vector2i(1, 1);
	sf::Vector2f delta;
	float speed = 200;

public:
	virtual void update(float dt, sf::Vector2u windowSize);
};

