#pragma once
#include <SFML/Graphics.hpp>
#include "Mover.h"
#include "Map.h"

class InputHandler
{
private:
	sf::Event event;
	int keycounter = 0;
public:
	InputHandler();
	void keyBoard(sf::RenderWindow *window, Mover *player,Map *map);
	~InputHandler();
};

