#include <SFML/Graphics.hpp>
#include <iostream>
#include "Forces.h"
#include "Mover.h"
#include "InputHandler.h"
#include "Pipes.h"
#include "Map.h"


constexpr int WIDTH = 800;
constexpr int HEIGHT = 600;



Map one(sf::Vector2f(800, 600),450);
kphys::Forces f;
Mover player;
InputHandler input;
Pipes pi(sf::Vector2f(50, 50));

sf::ContextSettings settings;
float s = 0;

int main()
{
	srand(time(NULL));	
	
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "SFML", sf::Style::Default, settings);
	window.setFramerateLimit(120);
	
	while (window.isOpen())
	{	
		s += 0.001;
		player.addForce(f.dragForce(0.01, player));
		player.addForce(f.gravityForce(0.1, player));

		player.checkColision();
		player.update(&window);
		input.keyBoard(&window, &player, &one);

		pi.updateLoc(s);
		pi.cwEntity(&player);
		pi.drawPipes(&window);

		one.ColisionGround(&player);
		one.drawGround(&window);

		window.draw(player.entity); 
		window.display();
		window.clear();

	}
	return 0;
}

