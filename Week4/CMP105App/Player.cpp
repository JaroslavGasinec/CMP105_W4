#include "Player.h"

Player::Player(sf::Vector2u* windowStart, sf::Vector2u* windowEnd)
{
	this->windowEnd = windowEnd;
	this->windowStart = windowStart;
}

void Player::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Up)) {
		direction.y -= 1;
		input->setKeyUp(sf::Keyboard::Up);
	}
	if (input->isKeyDown(sf::Keyboard::Down)) {
		direction.y += 1;
		input->setKeyUp(sf::Keyboard::Down);
	}
	if (input->isKeyDown(sf::Keyboard::Left)) {
		direction.x -= 1;
		input->setKeyUp(sf::Keyboard::Left);
	}
	if (input->isKeyDown(sf::Keyboard::Right)) {
		direction.x += 1;
		input->setKeyUp(sf::Keyboard::Right);
	}
	if (direction.x != 0) {
		direction.x = direction.x / abs(direction.x);
	}
	if (direction.y != 0) {
		direction.y = direction.y / abs(direction.y);
	}
}

void Player::update(float dt)
{
	delta.x = dt * speed * direction.x;
	delta.y = dt * speed * direction.y;
	if (getPosition().x + delta.x > windowEnd->x - getSize().x) {
		delta.x = 0.0f;
		setPosition(windowEnd->x - getSize().x, getPosition().y);
	}
	if (getPosition().y + delta.y > windowEnd->y - getSize().y) {
		delta.y = 0.0f;
		setPosition(getPosition().x, windowEnd->y - getSize().y);
	}
	if (getPosition().x + delta.x < windowStart->x) {
		delta.x = 0.0f;
		setPosition(windowStart->x,getPosition().y);
	}
	if (getPosition().y + delta.y < windowStart->y) {
		delta.y = 0.0f;
		setPosition(getPosition().x, windowStart->y);
	}
	setPosition(getPosition().x + delta.x,getPosition().y + delta.y);
	direction = sf::Vector2i(0,0);
}
