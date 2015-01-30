/**
* \class Player.h
* \brief A player class that represents the player
* that can move a ship, fire projectiles and get crushed by asteroids.
* \author David Stoddard
* \date January 29, 2015
*/
#pragma once

#include "GameObject.h"

class Player : public GameObject
{
public:
	Player();
	~Player();

	void Initialize();

	void Update(float dt);
	void Draw(SDL_Renderer *renderer, float dt);


	Vector2 pos;
	Vector2 vel;
	Vector2 directionVector;
	Vector2 endPointOffSet;
	Vector3 transformedEndPoint;
	
	const float pi = 3.1415926535f;
	float speed;
	float acceleration;
	float rotationRadians;
	float rotationDegrees;
	float rotationSpeed;

	int lives;
};