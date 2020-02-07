#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/GameObject.h"
#include <string.h>
#include "Player.h"
#include "Enemy.h"
#include "Cursor.h"
#include "Background.h"
#include <iostream>


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

	sf::Vector2u windowBoundaries;

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	sf::RenderWindow* window;
	Input* input;

	// Level objects
	float scrollSpeed = 1000.0f;
	GameObject* testSprite;
	GameObject* goomba;
	GameObject* ball;
	GameObject* cursor;
	GameObject* background;
	sf::View view;
	sf::Texture texture;
	sf::Texture texture2;
	sf::Texture texture3;
	sf::Texture texture4;

};