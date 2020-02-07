#pragma once
#include "Framework\GameObject.h"
class Cursor :
	public GameObject
{
	sf::Texture texture;
	sf::Vector2u* windowSize;

public:
	Cursor(sf::Vector2u* windowSize);
	void update(float dt) override;
};

