#pragma once
#include <SFML/Graphics.hpp>
#include "Mover.h"

class Pipes
{
	sf::Vector2f loc;
	sf::RectangleShape pipe;

	sf::FloatRect pipeBB;
	sf::FloatRect entityBB;

public:
	Pipes(sf::Vector2f sizeOfPipe);
	void cwEntity(Mover *mover);
	void updateLoc(float speed);
	void drawPipes(sf::RenderWindow *window);
	~Pipes();
};

