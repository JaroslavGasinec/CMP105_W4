#pragma once
#include "FrameWork\GameObject.h"
#include <cstdlib>

class Player :
	public GameObject
{

	sf::Vector2i direction = sf::Vector2i(0,0);
	sf::Vector2f delta;
	float speed = 1000;
	sf::Vector2u* windowSize;

public:
	Player();
	Player(sf::Vector2u* windowSize);
	void handleInput(float dt) override;
	void update(float dt) override;
};

