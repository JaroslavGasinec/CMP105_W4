#pragma once
#include "Framework\GameObject.h"
class Background :
	public GameObject
{
public:
	sf::Texture texture;
public:
	Background(sf::Texture Ntexture, sf:: Vector2f size);
};

