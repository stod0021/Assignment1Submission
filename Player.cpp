#include "Player.h"
#include "Game.h"
#include <math.h>
#include <SDL.h>

Player::Player() : GameObject()
{
	_transform.position = { 320.0f, 320.0f, 0.0f }; //Player spawn point
}

Player::~Player()
{
}

void Player::Initialize()
{
	_transform.position = { 320.0f, 320.0f, 0.0f }; //Player spawn point
	pos = {320.0f,320.0f};
	speed = 200.0f;
	vel = { 0.0f, 0.0f };
	endPointOffSet = { 10.0f, 0.0f };
	rotationDegrees = rotationDegrees = 10.0f;
	rotationRadians = MathUtils::ToRadians(rotationDegrees);
	directionVector = { cos(rotationRadians), sin(rotationRadians) };
	rotationSpeed = 10.0f;
	lives = 3;
}

void Player::Update(float dt)
{
	// Set the draw colour for our point.
	_transform.position.x = pos.x;
	_transform.position.y = pos.y;

	Vector2 rotatedOffset =
	{
		endPointOffSet.x * cosf(rotationRadians) + endPointOffSet.y * sinf(rotationRadians),
		endPointOffSet.x * sinf(rotationRadians) - endPointOffSet.y * cosf(rotationRadians)
	};

	Vector2 transformedEndPoint = { _transform.position.x + rotatedOffset.x, _transform.position.y + rotatedOffset.y };

	_transform.rotation.x = transformedEndPoint.x;
	_transform.rotation.y = transformedEndPoint.y;

	if (pos.x >= 640)
	{
		pos.x = 1;
	}
	if (pos.x <= 0){
		pos.x = 639;
	}
	if (pos.y >= 640)
	{
		pos.y = 1;
	}
	if (pos.y <= 0)
	{
		pos.y = 639;
	}

}

void Player::Draw(SDL_Renderer *renderer, float dt)
{
	SDL_RenderDrawLine(renderer,
		_transform.position.x,
		_transform.position.y,
		_transform.rotation.x,
		_transform.rotation.y);
	/*
	SDL_RenderDrawLine(renderer,
		_transform.position.x +5,
		_transform.position.y -5,
		_transform.rotation.x,
		_transform.rotation.y);

	SDL_RenderDrawLine(renderer,
		_transform.position.x -5,
		_transform.position.y +5,
		_transform.rotation.x,
		_transform.rotation.y);
		*/

}
