#pragma once
#include <SFML/Graphics.hpp>
#include "kmath.h"
#include "Mover.h"
namespace kphys
{

class Forces
{
private:
	sf::Vector2f gravity;
	sf::Vector2f friction;
	sf::Vector2f drag;

	float speedOfDrag;
public:
	Forces();
	sf::Vector2f gravityForce(float strength, Mover body);
	sf::Vector2f frictionForce(float strength, Mover body);
	sf::Vector2f dragForce(float strength, Mover body);
	~Forces();
};

}

