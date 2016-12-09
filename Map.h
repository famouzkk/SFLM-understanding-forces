#pragma once
#include <SFML/Graphics.hpp>
#include "Mover.h"
#include <iostream>

class Map
{
private:
	sf::Vector2f sizeGround;
	sf::RectangleShape ground;
	float height = 0;
public:
	Map(sf::Vector2f sizeOfGround, float height);
	void ColisionGround(Mover *player);
	void drawGround(sf::RenderWindow *window);
	bool OnGround(Mover *player);
	~Map();
};

