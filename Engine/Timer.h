#pragma once


// deltaTime : 이전 프레임에서 현재 프레임까지 경과된 시간
// fps : frame per second, 매 초마다 평균적으로 몇프레임이 실행됬는지를 나타내주는 부분임. (1초마다 결과물)

class Timer
{
public:
	void Init();
	void Update();

public:
	uint32	GetFps()		{ return _fps; }
	float	GetDeltaTime()	{ return _deltaTime; }

private:
	uint64	_frequency = 0;
	uint64	_prevCount = 0;
	float	_deltaTime = 0.f;

private:
	uint32	_frameCount = 0;
	float	_frameTime = 0.f;
	uint32	_fps = 0;

};

