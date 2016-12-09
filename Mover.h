#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "kmath.h"

class Mover
{
public:
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f accelerate;
	sf::Vector2f size;

	sf::CircleShape entity;

	float mass;
	float radius;
public:
	Mover();

	void update(sf::RenderWindow *window);
	void addForce(sf::Vector2f force);
	void checkColision();
	void setPosition(sf::Vector2f location);

	~Mover();
};