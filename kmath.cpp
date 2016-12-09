#include "kmath.h"

namespace kmath
{
	//--------------------------------------------------

	float mag(sf::Vector2f vec)
	{
		return sqrt(vec.x * vec.x + vec.y * vec.y);
	}

	sf::Vector2f limit(sf::Vector2f vec, float max)
	{	
		
		if ((vec.x > max && vec.y > max) || ((vec.x < max && vec.y < max) && (vec.x > 0 && vec.y > 0))) vec = setMag(vec, max);
	
		return vec;
	}


	sf::Vector2f normalize(sf::Vector2f vec)
	{
		if (mag(vec) != 0) {
			vec.x = vec.x / mag(vec);
			vec.y = vec.y / mag(vec);
		}
		return vec;
	}

	sf::Vector2f setMag(sf::Vector2f vec,float mag)
	{
		vec = normalize(vec);
		vec *= mag;
		return vec;
	}

	sf::Vector2f mult(sf::Vector2f vec, sf::Vector2f vec2)
	{
		vec.x *= vec2.x;
		vec.y *= vec2.y;
		return vec;
	}

	//-----------------------------------------------------------------

	float RealDistrGen(float min, float max)
	{
		static std::default_random_engine e;
		static std::uniform_real_distribution<> dis(min, max); 
		return dis(e);
	}

}