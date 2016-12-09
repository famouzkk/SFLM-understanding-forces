#include "InputHandler.h"

InputHandler::InputHandler()
{

}

void InputHandler::keyBoard(sf::RenderWindow *window, Mover *player, Map *map)
{
	window->setKeyRepeatEnabled(false);
	while (window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
			window->close();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (map->OnGround(player) == true)
			player->addForce(sf::Vector2f(0, -20.0));
	 }
		
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		player->addForce(sf::Vector2f(-0.5, 0));

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		player->addForce(sf::Vector2f(0, 0.5));

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		player->addForce(sf::Vector2f(0.51, 0));
}


InputHandler::~InputHandler()
{
}
