#pragma once	
#include <random>
#include <SFML\System.hpp>
namespace kmath
{
	//Stuff from proccesing.java

	template<class T>
	T map(T* value, T istart, T istop, T ostart, T ostop){
		return ostart + (ostop - ostart) * ((value - istart) / (istop - istart));
	}

	template<class T>
	T constrain(T amt, T low, T high) {
		return  (amt < low) ? low : ((amt > high) ? high : amt);
	}
	
	//vector stuff for sfml

	float mag(sf::Vector2f vec);
	sf::Vector2f limit(sf::Vector2f vec, float max);
	sf::Vector2f normalize(sf::Vector2f vec);
	sf::Vector2f setMag(sf::Vector2f vec, float mag);
	sf::Vector2f mult(sf::Vector2f vec, sf::Vector2f vec2);

	//clear math stuff
	float RealDistrGen(float min, float max);
}
