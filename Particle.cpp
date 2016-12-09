#include "Particle.h"


namespace kphys
{

	Particle::Particle(int siz)
	{
		position = sf::Vector2f(400, 300);
		velocity = sf::Vector2f(0, 0);
		accelerate = sf::Vector2f(1, 1);
		
		particle.setSize(sf::Vector2f(10, 10));

		mass = 1;
		lifespan = 255;
		
		size = siz;
		

	}


	void Particle::update(sf::RenderWindow * window)
	{
		velocity += accelerate;
		position += velocity;

		particle.setPosition(position);
		particles = std::vector<sf::RectangleShape>(size, particle);
		accelerate *= 0.0f;
		lifespan -= 0.4;

		

		if (!isDead())
		{
			particle.setFillColor(sf::Color(lifespan, lifespan, lifespan));
		}
		
	}

	void Particle::drawAll(sf::RenderWindow * window)
	{
		update(window);
		window->clear();
		for (int i = 0; i < particles.size(); i++)
		{

			window->draw(particles[i]);
		}
	}

	bool Particle::isDead()
	{
		if (lifespan < 0)
		{
			return true;
		}
		else
			return false;
	}

	void Particle::addForce(sf::Vector2f force)
	{
		force /= mass;
		accelerate += force;
	}

	Particle::~Particle()
	{
	}

}
