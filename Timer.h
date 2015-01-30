/**
* \class Timer.h
* \brief A timer class that represents a timekeeper 
* to stop, run or pause the game. 
* \author David Stoddard
* \date January 29, 2015
*/
#pragma once

class Timer;

typedef void(Timer::*TimerInstanceEvent)();
typedef void(*TimerEvent)();

class Timer
{
public:
	enum TimerState
	{
		STOPPED,
		RUNNING,
		PAUSED
	};

	Timer();

	void Update();

	void Start();
	void Pause();
	void Stop();
	void Reset();

	float GetElapsedTime();
	float GetDeltaTime();
	float GetDuration();

	void SetDuration(float duration);

	void SetTimerEvent(TimerEvent evt);
	void SetTimerEvent(TimerInstanceEvent evt);

protected:
	float _oldTime, _currentTime, _deltaTime;
	float _duration, _elapsedTime;
	bool _paused;

	TimerState _state;
	TimerEvent _timerEvt;
	TimerInstanceEvent _timerInstEvt;
};