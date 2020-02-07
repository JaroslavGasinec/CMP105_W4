#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	testSprite = new Player(window->getSize());
	goomba = new Enemy(window->getSize());
	ball = new Enemy(window->getSize());
	cursor = new Cursor(window->getSize());

	testSprite->setInput(in);
	cursor->setInput(in);

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

	cursor->setSize(sf::Vector2f(100, 100));
	cursor->setPosition(100, 100);

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

	testSprite->update(dt);
	goomba->update(dt);
	ball->update(dt);
	cursor->update(dt);
}

// Render level
void Level::render()
{
	beginDraw();

	window->draw(*testSprite);
	window->draw(*goomba);
	window->draw(*ball);
	window->draw(*cursor);

	endDraw();
}

// clear back buffer
void Level::beginDraw()
{
	window->clear(sf::Color(100, 100, 100));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}