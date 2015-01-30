/**
* \class GameEngine.h
* \brief A class that represents a the game engine object that initializes and manages
* the core components of SDL.
* \author David Stoddard
* \date January 29, 2015
*/
#pragma once // Preprocessor directive to ensure that this header will only be included once. -- Generally used on Windows

// Preprocessor directive to ensure that this header will only be included once. -- Generally used for all environments.
/*#ifndef _GAME_ENGINE_H_
#define _GAME_ENGINE_H_

#endif // _GAME_ENGINE_H_*/
#include <string.h>
#include "MathUtils.h"
#include "Player.h"
#include "Asteroid.h"
#include "Projectile.h"
#include "Timer.h"

// Forward declaring our renderer and window.
// Because we're using them as pointers, we don't need to know their size
// at compile time to define this class.
struct SDL_Renderer;
struct SDL_Window;

class GameEngine
{
public:
	static GameEngine* CreateInstance();
//	std::string score="0";
//	std::string lives="3";

	void Initialize();
	void Shutdown();

	void Update();
	void Draw();

	~GameEngine();
protected:
	GameEngine();

	virtual void InitializeImpl() = 0;
	virtual void UpdateImpl(SDL_Renderer *renderer,float dt) = 0;
	virtual void DrawImpl(SDL_Renderer *renderer, float dt) = 0;

	static GameEngine *_instance;

	SDL_Window *_window;
	SDL_Renderer *_renderer;
	Timer _engineTimer;

	float _oldTime, _currentTime, _deltaTime;
};