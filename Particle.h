#pragma once
#include "Forces.h"

namespace kphys
{ 
	class Particle
	{
	public:
		sf::Vector2f position;
		sf::Vector2f velocity;
		sf::Vector2f accelerate;
		sf::RectangleShape particle;

		std::vector<sf::RectangleShape> particles;

		int size = 1;
		float mass;
		float lifespan;
	public:
		
		Particle(int siz);

		void update(sf::RenderWindow *window);
		void drawAll(sf::RenderWindow *window);
		bool isDead();
		void addForce(sf::Vector2f force);

		~Particle();

	};
}
