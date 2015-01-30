/**
* \class Asteroid.h
* \brief A class that represents a single asteroid.
* \author David Stoddard
* \date January 29, 2015
*/

#pragma once

#include "GameObject.h"
#include <cstdlib>

class Asteroid : public GameObject
{
public:
	/**
	* \fn void GameObject::Draw(SDL_Renderer *renderer, float dt)
	* \brief A virtual function that we’ll use as to define how our
	* object is drawn to the screen.
	* \param renderer The SDL renderer used to draw the object.
	* \param dt The time in fractions of a second since the last pass.
	*/
	Asteroid();
	~Asteroid();

	void Initialize();

	void Update(float dt);
	void Draw(SDL_Renderer *renderer, float dt);

	Vector2 directionVector;
	Vector2 pos;

	const float pi = 3.1415926535f;
	const int MAXASTEROIDS = 10;
	bool isActive;
	int lives;
	float speed;
};