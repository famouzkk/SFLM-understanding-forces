#include "Forces.h"

namespace kphys
{ 

Forces::Forces()
{
	gravity = sf::Vector2f(0,0);
}

sf::Vector2f Forces::gravityForce(float strength, Mover body)
{
	gravity.y = strength;
	gravity *= body.mass;
	return gravity;
}

sf::Vector2f Forces::frictionForce(float strength, Mover body)
{
	friction = body.velocity;
	friction = kmath::setMag(friction, strength);
	friction *= -1.0f;

	return friction;
}

sf::Vector2f Forces::dragForce(float strength, Mover body)
{
	drag = body.velocity;
	speedOfDrag = kmath::mag(body.velocity) * kmath::mag(body.velocity);
	drag = kmath::setMag(drag, strength * speedOfDrag);
	drag *= -1.0f;
	return drag;
}


Forces::~Forces()
{
}

}