#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	windowEnd = window->getSize();
	windowStart = sf::Vector2u(0,0);
	testSprite = new Player(&windowStart,&windowEnd);
	goomba = new Enemy(&windowStart, &windowEnd);
	ball = new Enemy(&windowStart, &windowEnd);
	cursor = new Cursor(&windowStart, &windowEnd);
	

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

	texture4.loadFromFile("gfx/Level1_1.png");
	background = new Background(texture4, sf::Vector2f(11038,675));
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
	
	if (input->isKeyDown(sf::Keyboard::D)) 
	{
		handleView(1, dt);
		input->setKeyUp(sf::Keyboard::D);
	}

	if (input->isKeyDown(sf::Keyboard::A))
	{
		handleView(-1, dt);
		input->setKeyUp(sf::Keyboard::A);
	}

	testSprite->handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	
	testSprite->update(dt);
	goomba->update(dt);
	ball->update(dt);
	cursor->update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	
	
	window->draw(*background);
	window->draw(*testSprite);
	window->draw(*goomba);
	window->draw(*ball);
	window->draw(*cursor);

	endDraw();
}

void Level::handleView(int direction, float dt)
{
	float deltaX = scrollSpeed * dt * direction;
	if (windowEnd.x + deltaX <= background->getSize().x && windowStart.x + deltaX >= 0 ) {
		view = window->getView();
		view.move(deltaX, 0);
		window->setView(view);

		windowEnd = sf::Vector2u(view.getCenter().x + (window->getSize().x / 2), view.getCenter().y + (window->getSize().y / 2));
		windowStart = sf::Vector2u(view.getCenter().x - (window->getSize().x / 2), view.getCenter().y - (window->getSize().y / 2));
	}

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