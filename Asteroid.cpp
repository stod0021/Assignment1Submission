#include "Asteroid.h"
#include "Game.h"
#include "MathUtils.h"
#include <math.h>
#include <SDL.h>
Asteroid::Asteroid() : GameObject()
{
}

Asteroid::~Asteroid()
{
}

void Asteroid::Initialize()
{
	float randomPosX = rand() % 639 + 1;
	float randomPosY = rand() % 639 + 1;

	float randomDirX = rand() % 359 + 1;
	float randomDirY = rand() % 359 + 1;

	directionVector = { cos(randomDirX), sin(randomDirY) };
	_transform.position = { randomPosX, randomPosY }; //Asteroid spawn point
	speed = 50.0f;
	lives = 1;
}

void Asteroid::Update(float dt)
{

	// Set the draw colour for our point.
	_transform.position.x += speed * directionVector.x * dt;
	_transform.position.y += speed * directionVector.y *dt;

	if (_transform.position.x >= 640)
	{
		_transform.position.x = 1;
	}
	if (_transform.position.x <= 0){
		_transform.position.x = 639;
	}
	if (_transform.position.y >= 640)
	{
		_transform.position.y = 1;
	}
	if (_transform.position.y <= 0)
	{
		_transform.position.y = 639;
	}


}

void Asteroid::Draw(SDL_Renderer *renderer, float dt)
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	/*SDL_Point *points = new SDL_Point[100];
	int i, j;
	for (j = 0; j <= 100; j++)
	{
		for (i = 0; i <= 100; i++)
		{
			points[i].x =  _transform.position.x;
			points[i].y =  _transform.position.y;
		}
	}
	
	SDL_RenderDrawLines(renderer, points, 100);
	SDL_EnclosePoints(points,100,)*/
	
	SDL_RenderDrawPoint(renderer, _transform.position.x - 5, _transform.position.y + 5);
	SDL_RenderDrawPoint(renderer, _transform.position.x, _transform.position.y + 5);
	SDL_RenderDrawPoint(renderer, _transform.position.x - 4, _transform.position.y + 4);
	SDL_RenderDrawPoint(renderer, _transform.position.x, _transform.position.y + 4);
	SDL_RenderDrawPoint(renderer, _transform.position.x - 3, _transform.position.y + 3);
	SDL_RenderDrawPoint(renderer, _transform.position.x, _transform.position.y + 3);
	SDL_RenderDrawPoint(renderer, _transform.position.x - 2, _transform.position.y + 2);
	SDL_RenderDrawPoint(renderer, _transform.position.x, _transform.position.y + 2);
	SDL_RenderDrawPoint(renderer, _transform.position.x - 1, _transform.position.y + 1);
	SDL_RenderDrawPoint(renderer, _transform.position.x, _transform.position.y + 1);
	SDL_RenderDrawPoint(renderer, _transform.position.x + 5, _transform.position.y + 5);
	SDL_RenderDrawPoint(renderer, _transform.position.x + 5, _transform.position.y);
	SDL_RenderDrawPoint(renderer, _transform.position.x + 4, _transform.position.y + 4);
	SDL_RenderDrawPoint(renderer, _transform.position.x + 4, _transform.position.y);
	SDL_RenderDrawPoint(renderer, _transform.position.x + 3, _transform.position.y + 3);
	SDL_RenderDrawPoint(renderer, _transform.position.x + 3, _transform.position.y);
	SDL_RenderDrawPoint(renderer, _transform.position.x + 2, _transform.position.y + 2);
	SDL_RenderDrawPoint(renderer, _transform.position.x + 2, _transform.position.y);
	SDL_RenderDrawPoint(renderer, _transform.position.x + 1, _transform.position.y + 1);
	SDL_RenderDrawPoint(renderer, _transform.position.x + 1, _transform.position.y);
	SDL_RenderDrawPoint(renderer, _transform.position.x, _transform.position.y);
	SDL_RenderDrawPoint(renderer, _transform.position.x - 1, _transform.position.y);
	SDL_RenderDrawPoint(renderer, _transform.position.x - 1, _transform.position.y - 1);
	SDL_RenderDrawPoint(renderer, _transform.position.x - 2, _transform.position.y);
	SDL_RenderDrawPoint(renderer, _transform.position.x - 2, _transform.position.y - 2);
	SDL_RenderDrawPoint(renderer, _transform.position.x - 3, _transform.position.y);
	SDL_RenderDrawPoint(renderer, _transform.position.x - 3, _transform.position.y - 3);
	SDL_RenderDrawPoint(renderer, _transform.position.x - 4, _transform.position.y);
	SDL_RenderDrawPoint(renderer, _transform.position.x - 4, _transform.position.y - 4);
	SDL_RenderDrawPoint(renderer, _transform.position.x - 5, _transform.position.y);
	SDL_RenderDrawPoint(renderer, _transform.position.x - 5, _transform.position.y - 5);
	SDL_RenderDrawPoint(renderer, _transform.position.x, _transform.position.y - 1);
	SDL_RenderDrawPoint(renderer, _transform.position.x + 1, _transform.position.y - 1);
	SDL_RenderDrawPoint(renderer, _transform.position.x, _transform.position.y - 2);
	SDL_RenderDrawPoint(renderer, _transform.position.x + 2, _transform.position.y - 2);
	SDL_RenderDrawPoint(renderer, _transform.position.x, _transform.position.y - 3);
	SDL_RenderDrawPoint(renderer, _transform.position.x + 3, _transform.position.y - 3);
	SDL_RenderDrawPoint(renderer, _transform.position.x, _transform.position.y - 4);
	SDL_RenderDrawPoint(renderer, _transform.position.x + 4, _transform.position.y - 4);
	SDL_RenderDrawPoint(renderer, _transform.position.x, _transform.position.y - 5);
	SDL_RenderDrawPoint(renderer, _transform.position.x + 5, _transform.position.y - 5);
}