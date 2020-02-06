#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in, Player* pl)
{
	window = hwnd;
	input = in;
	testSprite = pl;

	// initialise game objects
	texture.loadFromFile("gfx/Mushroom.png");
	testSprite->setTexture(&texture);
	testSprite->setSize(sf::Vector2f(100, 100));
	testSprite->setPosition(100, 100);

	texture2.loadFromFile("gfx/goomba.png");
	goomba->setTexture(&texture2);
	goomba->setSize(sf::Vector2f(100, 100));
	goomba->setPosition(200, 200);

	texture3.loadFromFile("gfx/Beach_Ball.png");
	ball->setTexture(&texture3);
	ball->setSize(sf::Vector2f(100, 100));
	ball->setPosition(350, 500);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	// Close window on Escape pressed.
	if (input->isKeyDown(sf::Keyboard::Escape))
	{
		window->close();
	}
	testSprite->handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	windowSize = window->getSize();
	testSprite->update(dt,windowSize);
	goomba->update(dt, windowSize);
	ball->update(dt, windowSize);
}

// Render level
void Level::render()
{
	beginDraw();


	window->draw(*testSprite);
	window->draw(*goomba);
	window->draw(*ball);

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}