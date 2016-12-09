#include "Map.h"



Map::Map(sf::Vector2f sizeOfGround,float height)
{
	this->sizeGround = sizeOfGround;
	this->height = height;
	ground.setSize(sizeGround);
	ground.setPosition(0, height);
}

void Map::ColisionGround(Mover *player)
{
	if (OnGround(player))
	{
		player->position.y = height - 42.0f;
		std::cout << "WTF!" << std::endl;

	}
	
}

void Map::drawGround(sf::RenderWindow *window)
{
	window->draw(ground);
}

bool Map::OnGround(Mover *player)
{
	if (player->position.y > height - 42.0f)
	{
		return true;
	}
	else
		return false;


}


Map::~Map()
{
}
