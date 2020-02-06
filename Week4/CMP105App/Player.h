#pragma once
#include "FrameWork\GameObject.h"
#include <cstdlib>

class Player :
	public GameObject
{

	sf::Vector2i direction = sf::Vector2i(0,0);
	sf::Vector2f delta;
	float speed = 1000;

public:
	void handleInput(float dt);
	virtual void update(float dt, sf::Vector2u windowSize);
};

