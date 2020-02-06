#include "Player.h"

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

void Player::update(float dt, sf::Vector2u windowSize)
{
	delta.x = dt * speed * direction.x;
	delta.y = dt * speed * direction.y;
	if (getPosition().x + delta.x > windowSize.x - getSize().x) {
		delta.x = 0.0f;
	}
	if (getPosition().y + delta.y > windowSize.y - getSize().y) {
		delta.y = 0.0f;
	}
	this->setPosition(this->getPosition().x + delta.x, this->getPosition().y + delta.y);

}
