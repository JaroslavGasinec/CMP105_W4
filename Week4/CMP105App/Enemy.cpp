#include "Enemy.h"

void Enemy::update(float dt, sf::Vector2u windowSize)
{
	getPosition();
	delta.x = dt * speed * direction.x;
	delta.y = dt * speed * direction.y;

	if (getPosition().x > windowSize.x - getSize().x) {
		setPosition(windowSize.x - getSize().x, getPosition().y);
	}

	if (getPosition().x + delta.x > windowSize.x - getSize().x) {
		delta.x = (windowSize.x - getSize().x) - (getPosition().x + delta.x);
		direction.x *= (-1);
	}
	if (getPosition().y + delta.y > windowSize.y - getSize().y) {
		delta.y = (windowSize.y - getSize().y) - (getPosition().y + delta.y);
		direction.y *= (-1);
	}
	if (getPosition().x + delta.x < 0) {
		delta.x = 0 - (getPosition().x + delta.x);
		direction.x *= (-1);
	}
	if (getPosition().y + delta.y < 0) {
		delta.y = 0 - (getPosition().y + delta.y);
		direction.y *= (-1);
	}
	setPosition(getPosition().x + delta.x, getPosition().y + delta.y);
}

