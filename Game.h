/**
* \class Game.h
* \brief A class that represents the game field and its interacting 
* objects within that field such as asteroids, projectiles and the player in this case.
* \author David Stoddard
* \date January 29, 2015
*/
#pragma once

#include "GameEngine.h"
#include <list>

class Game : public GameEngine
{
	friend class GameEngine;
protected:
	Game();

	void InitializeImpl();
	void UpdateImpl(SDL_Renderer *renderer,float dt);
	void DrawImpl(SDL_Renderer *renderer, float dt);
	
	Player _player;
	Projectile _projectile;
	Asteroid _asteroid[10];
	//std::list <Projectile> _projectiles;
	//::list <Asteroid> _asteroids;
	
	//Asteroid _asteroid[10];

	//int projectilePool =20; // projectile total bullets at play
	//int asteroidPool = 10; // asteroid total at play
	const float pi = 3.1415926535f;

};