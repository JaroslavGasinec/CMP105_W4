#include "Enemy.h"

void Enemy::update(float dt)
{
	getPosition();
	delta.x = dt * speed * direction.x;
	delta.y = dt * speed * direction.y;

	if (getPosition().x > windowEnd->x - getSize().x) {
		setPosition(windowEnd->x - getSize().x, getPosition().y);
	}

	if (getPosition().x + delta.x > windowEnd->x - getSize().x) {
		delta.x = (windowEnd->x - getSize().x) - (getPosition().x + delta.x);
		direction.x *= (-1);
	}
	if (getPosition().y + delta.y > windowEnd->y - getSize().y) {
		delta.y = (windowEnd->y - getSize().y) - (getPosition().y + delta.y);
		direction.y *= (-1);
	}
	if (getPosition().x + delta.x < windowStart->x) {
		delta.x = windowStart->x - (getPosition().x + delta.x);
		direction.x *= (-1);
	}
	if (getPosition().y + delta.y < windowStart->y) {
		delta.y = windowStart->y - (getPosition().y + delta.y);
		direction.y *= (-1);
	}
	setPosition(getPosition().x + delta.x, getPosition().y + delta.y);
}

Enemy::Enemy(sf::Vector2u* windowStart,sf::Vector2u* windowEnd)
{
	this->windowEnd = windowEnd;
	this->windowStart = windowStart;
}
