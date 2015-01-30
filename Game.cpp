#include "Game.h"
#include "InputManager.h"
#include <SDL.h>
#include <math.h>
#include <istream>

// Initializing our static member pointer.
GameEngine* GameEngine::_instance = nullptr;

GameEngine* GameEngine::CreateInstance()
{
	if (_instance == nullptr)
	{
		_instance = new Game();
	}
	return _instance;
}

Game::Game() : GameEngine()
{

}

void Game::InitializeImpl()
{
	// Using the default member-wise initializer for our new struct.
	_player.Initialize();

	_projectile.Initialize();
	//for (int i = 0; i < 10; i++){
		//_projectile[i].
	//}

	for (int i = 0; i < 10; i++){
		_asteroid[i].Initialize();
	}
}

void Game::UpdateImpl(SDL_Renderer *renderer, float dt)
	{
	InputManager *im = InputManager::GetInstance();
	im->Update(dt);
	
	_player.directionVector = { cos(_player.rotationRadians), sin(_player.rotationRadians) };
	_player.pos.x = _player.pos.x;
	_player.pos.y = _player.pos.y;
	// Check for user input.
	if (im->IsKeyDown(SDLK_UP) == true)
		{
				if ((_player.vel.x || _player.vel.y) > 100 || (_player.vel.x || _player.vel.y) < -100) //Speed limiter.
					{
						//do f all
					}
				else
					{
						_player.vel.x += _player.speed * _player.directionVector.x * dt;
						_player.vel.y += _player.speed * _player.directionVector.y * dt;
						_player.vel.x *= 0.9999999;//very nice effect vs 0.99 not so nice
						_player.vel.y *= 0.9999999;
					}
		}
	else if (im->IsKeyDown(SDLK_DOWN) == true)
		{
			if ((_player.vel.x || _player.vel.y) > 100 || (_player.vel.x || _player.vel.y) < -100) //Speed limiter.
				{
					//do f all
				}
			else
				{
				_player.vel.x -= _player.speed * _player.directionVector.x * dt;
				_player.vel.y -= _player.speed * _player.directionVector.y * dt;
				_player.vel.x *= 0.9999999;
				_player.vel.y *= 0.9999999;
				}
		}
	else if (im->IsKeyDown(SDLK_LEFT) == true)
		{
			_player.rotationRadians -= _player.rotationSpeed * dt;
						if (_player.rotationRadians > pi)
							_player.rotationRadians = -pi;
						else if (_player.rotationRadians < -pi){
							_player.rotationRadians = pi;
						}
		}
	else if (im->IsKeyDown(SDLK_RIGHT) == true)
		{
			_player.rotationRadians += _player.rotationSpeed * dt;
						if (_player.rotationRadians > pi)
							_player.rotationRadians = -pi;
						else if (_player.rotationRadians < -pi){
							_player.rotationRadians = pi;
						}
		}
	else if (im->IsKeyDown(SDLK_SPACE) == true)
		{
		/*
			if (j==10)
			{
				j = 0; // if bullet reaches 10 reset counter to 0.
			}
				j++;

				//_projectile[j].isDisapeared = false;
				_projectile[j].pos.x = _player.pos.x;
				_projectile[j].pos.y = _player.pos.y;
				_projectile[j].directionVector.x = _player.directionVector.x;
				_projectile[j].directionVector.y = _player.directionVector.y;
				_projectile[j].isActive = true;
				//printf("%d \n", j);
				*/
		}
		//printf("%.3f\n", _player.vel.y);

		_player.pos.x += _player.vel.x  * dt;
		_player.pos.y += _player.vel.y * dt;
		_player.Update(dt);
//		_projectile[j].Update(dt);
		for (int i = 0; i < 10; i++){
			_asteroid[i].Update(dt);
		}
}


void Game::DrawImpl(SDL_Renderer *renderer, float dt)
{
			// Set the draw colour for screen clearing.
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
			// Clear the renderer with the current draw colour.
		SDL_RenderClear(renderer);

			// Set the draw colour for our point.
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

			// Draw the player
		_player.Draw(renderer, dt);

			//Draw projectiles if needed
		/*
		for (int j = 0; j < 10; j++)
		{
			if (_projectile[j].isActive == true) // if projectile 
				_projectile[j].Draw(renderer, dt);
			else 
			{
				_projectile[j].isActive = true;
			}
		}*/
			
			//Draw the asteroid
		for (int i = 0; i < 10; i++){
			_asteroid[i].Draw(renderer,dt);
		}
			// Present what is in our renderer to our window.
		SDL_RenderPresent(renderer);
}