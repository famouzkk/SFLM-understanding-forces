#include "Mover.h"



Mover::Mover()
{
	srand(time(NULL));

	position = sf::Vector2f(400, 300);
	velocity = sf::Vector2f(0, 0);
	accelerate = sf::Vector2f(0,0);

	mass = 2;

	entity.setPosition(position);
	entity.setRadius(10.0f);
	entity.setFillColor(sf::Color(41, 128, 185));
	entity.setOutlineColor(sf::Color(236, 240, 241));
	entity.setOutlineThickness(0.2);
}

void Mover::update(sf::RenderWindow *window)
{
	 
	velocity += accelerate;
	position += velocity;

	entity.setPosition(position);	
	entity.setScale(sf::Vector2f(mass, mass));

	accelerate *= 0.0f;

}

void Mover::addForce(sf::Vector2f force)
{
	force /= mass;
	accelerate += force;
}

void Mover::checkColision()
{
	size = sf::Vector2f(entity.getScale().x * 10.0f, entity.getScale().y * 10.0f) * 2.0f;
	
	if (position.x > 720 ) {
		position.x = 720;
		velocity.x *= -1;
	}
	else if (position.x < 0) {
		position.x = 0;
		velocity.x *= -1;	
	}

	if (position.y > 520) {
		position.y = 520;
		velocity.y *= -1;
	}
	else if (position.y < 0)
	{
		position.y = 0;
		velocity.y *= -1;
	}
}

void Mover::setPosition(sf::Vector2f location)
{
	 accelerate += location;
}

Mover::~Mover()
{
}
