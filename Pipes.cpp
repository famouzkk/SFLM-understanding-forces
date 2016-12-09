#include "Pipes.h"



Pipes::Pipes(sf::Vector2f sizeOfPipe)
{
	pipe.setSize(sizeOfPipe);
	loc = sf::Vector2f(800 - sizeOfPipe.x, 450 - sizeOfPipe.y);
	pipe.setPosition(loc);
	pipe.setFillColor(sf::Color(50, 240, 15));
}

void Pipes::cwEntity(Mover *mover)
{
	pipeBB = pipe.getGlobalBounds();
	entityBB = mover->entity.getGlobalBounds();

	if (entityBB.intersects(pipeBB))
	{
		pipe.setFillColor(sf::Color(233, 150, 27));
	}

}

void Pipes::updateLoc(float speed)
{
	loc.x -= speed;
	pipe.setPosition(loc);

	if (loc.x < 0 - pipe.getSize().x)
	{
		loc.x = 800 + pipe.getSize().x;
	}
}

void Pipes::drawPipes(sf::RenderWindow * window)
{
	window->draw(pipe);
}

Pipes::~Pipes()
{

}
