#include "Projectile.h"
#include "Game.h"
#include "MathUtils.h"
#include <math.h>
#include <SDL.h>
#include <iostream>
Projectile::Projectile() : GameObject()
{
}

Projectile::~Projectile()
{
	
}

void Projectile::Initialize()
{	
	directionVector.x = getPlayerDirection.x;
	directionVector.y = getPlayerDirection.y;
	_transform.position = { pos.x, pos.y }; //Position of projectile on fire(spacebar)
	speed = 100.0f;
	timer = 10; // 10 seconds
}

void Projectile::Update(float dt)
{
	timer -= dt;
	printf("%f\n", timer);
	if (timer <= 0){
		isActive == false;
		//printf("HELLOOOSDOASODASOOASDOASODOASDODOASDOODSOSDOA \n");
	}
	else{
		//printf("%f\n", directionVector.x);
		// Set the draw colour for our point.

		_transform.position.x += speed * directionVector.x * dt;
		_transform.position.y += speed * directionVector.y * dt;

		/*Vector2 rotatedOffset =
		{
			 cosf(rotationRadians) +  sinf(rotationRadians),
			 sinf(rotationRadians) -  cosf(rotationRadians)
		};*/

		/*Vector2 transformedEndPoint = { _transform.position.x + rotatedOffset.x, _transform.position.y + rotatedOffset.y };

		_transform.rotation.x = transformedEndPoint.x;
		_transform.rotation.y = transformedEndPoint.y;*/

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
}

void Projectile::Draw(SDL_Renderer *renderer, float dt)
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
	//SDL_RenderSetScale(renderer, _transform.scale.x, _transform.scale.y);
	SDL_RenderDrawPoint(renderer, _transform.position.x , _transform.position.y );
	

}
