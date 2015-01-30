/**
* \class Asteroid.h
* \brief A class that represents a single projectile.
* \author David Stoddard
* \date January 29, 2015
*/
#pragma once

#include "GameObject.h"

class Projectile : public GameObject 
{
public:
	Projectile();
	~Projectile();

	void Initialize();

	void Update(float dt);
	void Draw(SDL_Renderer *renderer, float dt);

	Vector2 directionVector;
	Vector2 pos;
	Vector2 getPlayerDirection;


	float projectilesPool;
	float rotationRadians;
	const float pi = 3.1415926535f;
	bool isActive;
	float timer;
	float speed;
	float size;
};