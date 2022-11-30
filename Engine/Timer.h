#pragma once


// deltaTime : ���� �����ӿ��� ���� �����ӱ��� ����� �ð�
// fps : frame per second, �� �ʸ��� ��������� ���������� ����������� ��Ÿ���ִ� �κ���. (1�ʸ��� �����)

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

